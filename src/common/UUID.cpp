#include "common/UUID.hpp"
#include <random>

namespace fr
{

namespace common
{

namespace
{

std::random_device randomDevice;
std::mt19937_64 randomGenerator(randomDevice());
std::uniform_int_distribution<uint64_t> uniformDistribution;

} // namespace

UUID::UUID(uint64_t firstCode, uint64_t secondCode)
    : m_firstCode(firstCode), m_secondCode(secondCode)
{
}

UUID::UUID()
    : m_firstCode(uniformDistribution(randomGenerator)),
      m_secondCode(uniformDistribution(randomGenerator))
{
}

std::array<uint64_t, 2> UUID::getCodes() const
{
  return {m_firstCode, m_secondCode};
}

bool UUID::operator<(const UUID &rhs) const
{
  return std::hash<UUID>()(*this) < std::hash<UUID>()(rhs);
}

} // namespace common
} // namespace fr
