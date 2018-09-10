#pragma once
#include <vector>
#include <string>

/**
 * Generator for CRC32 hash
 */
class HashGenerator
{
public:

  HashGenerator() = default;

  ~HashGenerator() = default;

  /**
   *
   * @param block - data for hasing
   * @param size - data size
   * @return CRC32 hash string
   */
  std::string Generate(std::vector<char> block, long int size);
};
