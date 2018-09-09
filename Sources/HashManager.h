#pragma once
#include "IManager.h"
#include <map>

class HashManager : public IManager
{
public:

  using HashTable = std::map<int, int>;

  HashManager();

  virtual ~HashManager() = default;

  virtual void Seed(std::vector<char> block, long int size) override;

  virtual void Write() override;

protected:

  int id;

  int hash;

  HashTable table;


};
