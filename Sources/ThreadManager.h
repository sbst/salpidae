#pragma once
#include "IManager.h"
#include "HashTableAsync.h"
#include <thread>

class ThreadManager : public IManager
{
public:

  ThreadManager(size_t limit);

  virtual ~ThreadManager() = default;

  virtual void Seed(const std::vector<char>& block, long int size) override;

  virtual void SetOutput(File&& file) override;

  virtual void Write() override;

  virtual void Clear() override;

  const size_t limit;

protected:

  void Update();

  HashTableAsync table;

  File output;

private:

  void Wait();

  void CleanThreads();

  std::vector<std::thread> threads;

  int id;
};
