#pragma once
#include "IContainer.h"
#include <map>

/**
 * Collect data to hash map
 */
class HashTable : public IContainer
{
public:

  HashTable() = default;

  virtual ~HashTable() = default;

  /**
   * Add new record
   * @param key - processed block id
   * @param value - result hash
   */
  virtual void Add(int key, std::string value) override;

  /**
   * Store data to file and clean temporary
   * @param file - destination
   * @param length - last item for storing
   */
  virtual void ToFile(File& file, int length) override;

protected:

  /**
   * index - hash
   * where index starts from 0
   */
  std::map<int, std::string> table;
};
