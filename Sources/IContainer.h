#pragma once

class IContainer
{
public:
  virtual ~IContainer() = default;

  virtual void Add(int key, int value) = 0;

  virtual void Sort() = 0;
};
