#include "pch.h"
#include "ThreadManager.h"
#include "HashGenerator.h"
#include <mutex>

std::recursive_mutex exMutex;

void Generate(HashTableAsync& table, int id, std::vector<char> block, long int size)
{
  try
  {
    auto hash = HashGenerator().Generate(block, size);
    table.Add(id, hash);
  }
  catch (const std::exception& e)
  {
    exMutex.lock();
    std::cout << "salpidae: [Exception] Thread " << std::this_thread::get_id() << " throws: " << e.what() << std::endl;
    exMutex.unlock();
  }
}

ThreadManager::ThreadManager(size_t limit) : limit(limit), id(0)
{}

void ThreadManager::SetOutput(File&& file)
{
  output = std::move(file);
}

void ThreadManager::Seed(const std::vector<char>& block, long int size)
{
  if (threads.size() >= limit)
  {
    Wait();
    CleanThreads();
  }

  if (threads.size() < limit)
  {
    threads.push_back(std::move(std::thread(Generate, std::ref(table), id++, block, size)));
  }
}

void ThreadManager::Write()
{
  if (threads.size() >= limit)
  {
    Update();
  }
}

void ThreadManager::Clear()
{
  Update();
}

void ThreadManager::Update()
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
