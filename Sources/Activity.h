#pragma once
#include "IManager.h"
#include <string>
#include <memory>

/**
 * Main application activity
 */
class Activity
{
public:

  Activity();

  ~Activity() = default;

  /**
   * Process arguments from main
   * @param argc
   * @param argv
   * @return false - wrong arguments, true - correct
   */
  bool ProcessArguments(int argc, char* argv[]);

  /**
   * Run application logic
   */
  void Run();

private:

  std::string input;

  std::string output;

  long int block;

  std::unique_ptr<IManager> manager;

};
