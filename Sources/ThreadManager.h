#pragma once
#include "IManager.h"
#include "HashTableAsync.h"

class ThreadManager : public IManager
{
public:

  ThreadManager();

  virtual ~ThreadManager() = default;

  virtual void Seed(std::vector<char> block, long int size) override;

  virtual void Write() override;

protected:

  HashTableAsync table;

  int id;
};
