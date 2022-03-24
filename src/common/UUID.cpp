#include "UUID.hpp"
#include <random>

namespace fpd
{

namespace
{
std::random_device randomDevice;
std::mt19937_64 randomGenerator(randomDevice());
std::uniform_int_distribution<uint64_t> uniformDistribution;
}

UUID::UUID(int64_t firstCode, int64_t secondCode):
      m_firstCode(firstCode),
      m_secondCode(secondCode)
{
}

UUID::UUID():
      m_firstCode(uniformDistribution(randomGenerator)),
      m_secondCode(uniformDistribution(randomGenerator))
{
}

} // namespace fpd
