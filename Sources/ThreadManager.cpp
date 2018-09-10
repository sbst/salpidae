#include "pch.h"
#include "ThreadManager.h"
#include "HashGenerator.h"

void Generate(HashTableAsync& table, int id, std::vector<char> block, long int size)
{
  auto hash = HashGenerator().Generate(block, size);
  table.Add(id, hash);
}

ThreadManager::ThreadManager(size_t limit) : limit(limit), id(0)
{}

void ThreadManager::Seed(const std::vector<char>& block, long int size)
{
  if (threads.size() >= limit)
  {
    Wait();
    CleanThreads();
  }

  if (threads.size() < limit)
  {
    threads.push_back(std::thread(Generate, std::ref(table), id++, block, size));
  }
}

void ThreadManager::Write()
{
  if (threads.size() >= limit)
  {
    Wait();
    table.ToFile(output, id);
    CleanThreads();
  }
}

void ThreadManager::SetOutput(File&& file)
{
  output = std::move(file);
}

void ThreadManager::Clear()
{
  Wait();
  table.ToFile(output, id);
  CleanThreads();
}

void ThreadManager::Wait()
{
  for (auto& thread : threads)
    thread.join();
}

void ThreadManager::CleanThreads()
{
  threads.erase(threads.begin(), threads.end());
  id = 0;
}
