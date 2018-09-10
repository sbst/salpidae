#include "HashTableAsync.h"

void HashTableAsync::Add(int key, std::string value)
{
  mutex.lock();
  HashTable::Add(key, value);
  mutex.unlock();
}
