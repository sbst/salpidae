#include "HashTable.h"
#include <iostream>
#include <algorithm>

HashTable::HashTable()
{}

void HashTable::Add(int id, std::string value)
{
  table.emplace(id, value);
}

void HashTable::ToFile(File& file, int length)
{
  for (auto i = 0; i < length; i++)
  {
    file.Write(table.at(i));
  }
  table.clear();
}
