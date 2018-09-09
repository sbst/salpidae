#include "HashTable.h"
#include <iostream>

HashTable::HashTable()
{}

void HashTable::Add(int key, int value)
{
  table.emplace(key, value);
  std::cout << key << " " << value << std::endl;
}


void HashTable::Sort()
{

}
