#pragma once
#include "IContainer.h"
#include <map>

class HashTable : public IContainer
{
public:

  HashTable();

  virtual ~HashTable() = default;

  virtual void Add(int key, int value) override;

  virtual void Sort();

protected:

  std::map<int, int> table;
};
