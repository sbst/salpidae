#pragma once
#include <fstream>
#include <vector>

class File
{
public:

  File() = delete;

  File(const File& rhs) = delete;

  File(File&& rhs);

  explicit File(std::string file);

  ~File();

  std::vector<char> ReadBlock(long int& size);

  bool IsOpen();

protected:

  std::fstream file;

};
