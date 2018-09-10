#pragma once
#include <vector>
#include <string>

class HashGenerator
{
public:

  HashGenerator() = default;

  ~HashGenerator() = default;

  std::string Generate(std::vector<char> block, long int size);
};
