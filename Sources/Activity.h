#pragma once
#include "IManager.h"
#include <string>
#include <memory>

class Activity
{
public:

  Activity();

  ~Activity() = default;

  bool ProcessArguments(int argc, char* argv[]);

  void Run();

private:

  std::string input;

  std::string output;

  long int block;

  std::unique_ptr<IManager> manager;

};
