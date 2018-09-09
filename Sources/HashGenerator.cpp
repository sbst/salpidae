#include "HashGenerator.h"
#include <boost/crc.hpp>

int HashGenerator::Generate(std::vector<char> block, long int size)
{
  boost::crc_32_type crc;
  crc.process_bytes(&block[0], size);
  return crc.checksum();
}
