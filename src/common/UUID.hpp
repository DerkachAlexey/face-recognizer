#ifndef COMMON_UUID
#define COMMON_UUID

#include <cstdint>

namespace fpd
{

class UUID
{
public:
    UUID(int64_t firstCode, int64_t secondCode);
    UUID();

private:
    uint64_t m_firstCode;
    uint64_t m_secondCode;
};

} // namespace fpd

#endif
