#pragma once
#include <fstream>
#include <vector>

class File
{
public:

  explicit File(std::string file);

  std::vector<char> ReadBlock(long int& size);

  bool IsOpen();

  ~File();

protected:

  std::fstream file;

};
