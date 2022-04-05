#ifndef COMMON_UUID
#define COMMON_UUID

#include <cstdint>
#include <functional>

namespace fr
{

namespace common
{

class UUID
{
public:
  UUID(uint64_t firstCode, uint64_t secondCode);
  UUID();

  std::array<uint64_t, 2> getCodes() const;

  bool operator<(const UUID &rhs) const;

private:
  uint64_t m_firstCode;
  uint64_t m_secondCode;
};

} // namespace common
} // namespace fr

namespace std
{

template <> struct hash<fr::common::UUID>
{

  std::size_t operator()(const fr::common::UUID &uuid) const
  {
    size_t firstCodeHash = hash<uint64_t>()(uuid.getCodes()[0]);
    size_t secondCodeHash = hash<uint64_t>()(uuid.getCodes()[1]);
    return firstCodeHash ^ (secondCodeHash << 1);
  }
};

} // namespace std

#endif
