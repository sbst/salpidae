#pragma once
#include <vector>

class HashGenerator
{
public:

  HashGenerator() = default;

  ~HashGenerator() = default;

  int Generate(std::vector<char> block, long int size);
};
