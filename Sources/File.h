#pragma once
#include <fstream>
#include <vector>

class File
{
public:

  File() = default;

  File(const File& rhs) = delete;

  File(File&& rhs);

  File& operator=(File&& rhs);

  explicit File(std::string file, std::fstream::openmode mode);

  ~File();

  std::vector<char> ReadBlock(long int& size);

  void Write(const std::string& str);

  bool IsOpen();

protected:

  std::fstream file;

};
