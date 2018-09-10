#pragma once

#include "File.h"

/**
 * Interface temporary container
 */
class IContainer
{
public:
  virtual ~IContainer() = default;

  /**
   * Add data to container
   * @param key
   * @param value
   */
  virtual void Add(int key, std::string value) = 0;

  /**
   * Output data from container
   * @param file
   * @param length
   */
  virtual void ToFile(File& file, int length) = 0;
};
