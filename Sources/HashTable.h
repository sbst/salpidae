#pragma once
#include "IContainer.h"
#include <map>

class HashTable : public IContainer
{
public:

  HashTable();

  virtual ~HashTable() = default;

  virtual void Add(int key, std::string value) override;

  virtual void ToFile(File& file, int length) override;

protected:

  std::map<int, std::string> table;
};
