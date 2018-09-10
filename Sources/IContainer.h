#pragma once

#include "File.h"

class IContainer
{
public:
  virtual ~IContainer() = default;

  virtual void Add(int key, std::string value) = 0;

  virtual void ToFile(File& file, int length) = 0;
};
