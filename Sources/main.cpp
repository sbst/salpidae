#include "Activity.h"
#include <csignal>

int main(int argc, char* argv[])
{
  int exit = 0;
  Activity activity;
  if (activity.ProcessArguments(argc, argv))
  {
    activity.RegisterSignal(SIGINT, Activity::Stop);
    activity.Run();
  }
  else exit = 1;
  return exit;
}
