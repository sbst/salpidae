#pragma once
#include "File.h"
#include <vector>

/**
 * Interface for data block handling
 * Manager processing incoming data and set to output
 */
class IManager
{
public:
  virtual ~IManager() = default;

  /**
   * Set source which will obtain processing result
   * @param output
   */
  virtual void SetOutput(File&& output) = 0;

  /**
   * Set data block to manager
   * @param block - bytes
   * @param size - size of incoming bytes
   */
  virtual void Seed(const std::vector<char>& block, long int size) = 0;

  /**
   * Update seeded data
   */
  virtual void Write() = 0;

  /**
   * Clear seeded data
   */
  virtual void Clear() = 0;

};
