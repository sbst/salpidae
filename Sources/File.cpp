#include "pch.h"
#include "File.h"

File::File(std::string name)
{
  file.open(name, std::fstream::in | std::fstream::out | std::fstream::binary);
  if (!file.is_open()) throw std::runtime_error("Unable to open " + name);
}

std::vector<char> File::ReadBlock(long int& size)
{
  std::vector<char> buffer(size);
  file.read(&buffer[0], buffer.size());
  size = file.gcount();
  return buffer;
}

bool File::IsOpen()
{
  return !file;
}

File::~File()
{
  file.close();
}
