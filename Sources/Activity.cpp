#include "pch.h"
#include "Activity.h"
#include "File.h"
#include "HashManager.h"
#include <csignal>
#include <unistd.h>

//#define THREADS 20  // TODO: detect optimal threads number from filesize

using namespace std::chrono_literals;

static volatile sig_atomic_t stop = 0;

static void StopHandler(int sig)
{
  stop = 1;
}

void Help()
{
  std::cout << "Usage: salpidae -i <input-file> -o <output-file> [-b <block-size>]" << std::endl << std::endl;
  std::cout << "Options: " << std::endl;
  std::cout << "\t -i <input-file>: file for signature generation" << std::endl;
  std::cout << "\t -o <output-file>: file for signature output" << std::endl;
  std::cout << "\t -b <block-size>: size of block in MB. 1 by default" << std::endl;
  std::cout << "\t -h: print this message" << std::endl;
}

Activity::Activity() : input(), output(), block(1), manager(std::make_unique<HashManager>())
{}

void Activity::RegisterSignal(int signal, Activity::SignalHandle handle)
{
  switch(handle)
  {
    case Stop: std::signal(signal, StopHandler); break;
    default: sout << "Unknown signal handler" << std::endl; break;
  }
}

bool Activity::ProcessArguments(int argc, char** argv)
{
  bool result = true;
  int arg = -1;
  while((arg = getopt(argc, argv, "i:o:b:h")) != -1)
  {
    switch(arg)
    {
      case 'i': input = optarg; break;
      case 'o': output = optarg; break;
      case 'b':
      {
        try
        {
          block = std::stoi(optarg);
        }
        catch(const std::invalid_argument&)
        {
          result = false;
          block = -1;

        }
      }
      break;
      case 'h':
      {
        Help();
        return false;
      }
      break;
    }
  }

  if (input.empty() || output.empty() || block < 0)
  {
    sout << "Wrong arguments" << std::endl;
    Help();
    result = false;
  }
  return result;
}

void Activity::Run()
{
  long int bytes = block*1048576;
  File file(input);
  while(!file.IsOpen())
  {
    const std::vector<char>& block = file.ReadBlock(bytes);
    manager->Seed(block, bytes);
    manager->Write();
  }
}

