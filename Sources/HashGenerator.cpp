#include "HashGenerator.h"
#include <boost/crc.hpp>
#include <sstream>

std::string HashGenerator::Generate(std::vector<char> block, long int size)
{
  boost::crc_32_type crc;
  crc.process_bytes(&block[0], size);
  std::ostringstream ss;
  ss << std::hex << std::uppercase << crc.checksum();
  return ss.str();
}
