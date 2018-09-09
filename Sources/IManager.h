#pragma once
#include <vector>

class IManager
{
public:
  virtual ~IManager() = default;

  virtual void Seed(std::vector<char> block, long int size) = 0;

  virtual void Write() = 0;

};
