#include "HashManager.h"
#include <iostream>
#include <boost/crc.hpp>

HashManager::HashManager() : id(0), hash(0)
{}

void HashManager::Seed(std::vector<char> block, long int size)
{
  id++;
  boost::crc_32_type crc;
  crc.process_bytes(&block[0], size);
  hash = crc.checksum();
}

void HashManager::Write()
{
  table.emplace(id, hash);
  std::cout << id << " " << hash << std::endl;
}
