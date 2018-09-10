#pragma once
#include "HashTable.h"
#include <mutex>

/**
 * Non-blocking collect data to hash table
 * Used for gathering data from working threads
 */
class HashTableAsync : public HashTable
{
public:
  using HashTable::HashTable;

  virtual ~HashTableAsync() = default;

  /**
   * Add data non-blocking
   * @param key - table index
   * @param value - hash
   */
  virtual void Add(int key, std::string value) override;

private:

  std::recursive_mutex mutex;
};
