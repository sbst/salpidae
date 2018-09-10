#include "pch.h"
#include "HashTable.h"

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
    try
    {
      file.Write(table.at(i));
    }
    catch(const std::out_of_range& e)
    {
      sout << "[Exception] #" << i << " map block not found" << std::endl;
      file.Write(std::string("error"));
    }
  }
  table.clear();
}
