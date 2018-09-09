#include "HashTableAsync.h"

void HashTableAsync::Add(int key, int value)
{
  mutex.lock();
  HashTable::Add(key, value);
  mutex.unlock();
}
