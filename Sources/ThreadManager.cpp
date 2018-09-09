#include "pch.h"
#include "ThreadManager.h"
#include "HashGenerator.h"

ThreadManager::ThreadManager() : id(0)
{}

void ThreadManager::Seed(std::vector<char> block, long int size)
{
  auto hash = HashGenerator().Generate(block, size); // thread func
  table.Add(id++, hash);
}

void ThreadManager::Write()
{

}

/*#include <iostream>
#include <vector>
#include <mutex>
#include <map>
#include <thread>
#include <string>
#include <cstdarg>
#include <chrono>

class container
{
      std::recursive_mutex _lock;
     std::map<int, int> _elements;
public:
     void add(int key, int value)
     {

       std::this_thread::sleep_for(std::chrono::seconds(1 + rand() % 10));
       _lock.lock();
          _elements.emplace(key, value);
          _lock.unlock();
     }

     void dump()
     {
          _lock.lock();
          for(auto e: _elements)
            std::cout << e.first << " " << e.second << std::endl;
          _lock.unlock();
     }
};

void threadFunction(container& c, int key)
{
     c.add(key, rand());
}

int main()
{
     srand((unsigned int)time(0));
     container cntr;
     std::vector<std::thread> threads;
     for(int i = 0; i < 300; ++i)
       threads.push_back(std::thread(threadFunction, std::ref(cntr), i));
     for(auto &t: threads)
       t.join();
     cntr.dump();
     return 0;
}
*/
