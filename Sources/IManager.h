#pragma once
#include "File.h"
#include <vector>

class IManager
{
public:
  virtual ~IManager() = default;

  virtual void Seed(const std::vector<char>& block, long int size) = 0;

  virtual void SetOutput(File&& output) = 0;

  virtual void Write() = 0;

  virtual void Clear() = 0;

};
