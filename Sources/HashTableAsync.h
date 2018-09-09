#pragma once
#include "HashTable.h"
#include <mutex>

class HashTableAsync : public HashTable
{
public:
  using HashTable::HashTable;

  virtual ~HashTableAsync() = default;

  virtual void Add(int key, int value) override;

private:

  std::recursive_mutex mutex;
};
