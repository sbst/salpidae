#pragma once
#include <string>
#include <memory>

class Activity
{
public:

  enum SignalHandle
  {
     Stop
  };

  Activity();

  ~Activity() = default;

  void RegisterSignal(int signal, Activity::SignalHandle handle);

  bool ProcessArguments(int argc, char* argv[]);

  void Run();

private:

  std::string input;

  std::string output;

  long int block;

};
