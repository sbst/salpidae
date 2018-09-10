#include "pch.h"
#include "File.h"

File::File(std::string name, std::fstream::openmode mode)
{
  file.open(name, mode);
  if (!file.is_open()) throw std::fstream::failure("Unable to open " + name);
}

File::File(File&& rhs)
{
  std::swap(file, rhs.file);
}

File& File::operator=(File&& rhs)
{
  std::swap(file, rhs.file);
  return *this;
}

std::vector<char> File::ReadBlock(long int& size)
{
  std::vector<char> buffer(size);
  file.read(&buffer[0], buffer.size());
  size = file.gcount();
  return buffer;
}

void File::Write(const std::string& str)
{
  file << str << std::endl;
}

bool File::IsOpen()
{
  return file.peek() != EOF;
}

File::~File()
{
  file.close();
}
