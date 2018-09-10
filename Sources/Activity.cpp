#include "pch.h"
#include "Activity.h"
#include "ThreadManager.h"
#include <boost/program_options.hpp>

#define THREADS 20  // TODO: adjust it dynamically or from arguments

using namespace std::chrono_literals;

namespace po = boost::program_options;

void Help()
{
  std::cout << "Usage: salpidae -i <input-file> -o <output-file> [-b <block-size>]" << std::endl << std::endl;
  std::cout << "Options: " << std::endl;
  std::cout << "\t -i <input-file>: file for signature generation" << std::endl;
  std::cout << "\t -o <output-file>: file for signature output" << std::endl;
  std::cout << "\t -b <block-size>: size of block in MB. 1 by default" << std::endl;
  std::cout << "\t -h: print this message" << std::endl;
}

Activity::Activity() : input(), output(), block(1), manager(std::make_unique<ThreadManager>(THREADS))
{}

bool Activity::ProcessArguments(int argc, char** argv)
{
  bool result = true;
  try
  {
    po::options_description desc("Allowed options");
    desc.add_options()
          ("help,h","")
          ("input,i", po::value<std::string>(&input))
          ("output,o", po::value<std::string>(&output))
          ("block,b", po::value<long int>(&block)->default_value(1));

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
      Help();
      return false;
    }

    if (input.empty() || output.empty() || block < 1)
    {
      std::cout << "Wrong arguments" << std::endl;
      Help();
      result = false;
    }
  }
  catch(const std::exception& e)
  {
    result = false;
    sout << e.what() << std::endl;
  }

  return result;
}

void Activity::Run()
{
  long int bytes = block*1048576;
  try
  {
    sout << "Open input file: " << input << "..." << std::endl;
    File in(input, std::fstream::in | std::fstream::binary);
    sout << "Open output file: " << output << "..." << std::endl;
    manager->SetOutput(std::move(File(output, std::fstream::out)));
    sout << "Seeding..." << std::endl;
    while(in.IsOpen())
    {
      const std::vector<char>& block = in.ReadBlock(bytes);
      try
      {
        manager->Seed(block, bytes);
        manager->Write();
      }
      catch(const std::exception& e)
      {
        sout << e.what() << std::endl;
      }
    }
    sout << "Clear..." << std::endl;
    manager->Clear();
    sout << "Done" << std::endl;
  }
  catch(const std::fstream::failure& e)
  {
    sout << "[Exception] " << e.what() << std::endl;
  }
}

