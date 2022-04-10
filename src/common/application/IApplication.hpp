#ifndef COMMON_APPLICATION_IAPPLICATION_H
#define COMMON_APPLICATION_IAPPLICATION_H

namespace fr
{

namespace common

{

class IApplication
{
public:
    virtual void startup() = 0;
    virtual ~IApplication(){};
};

} // namespace fr
} // namespace common
#endif // COMMON_APPLICATION_IAPPLICATION_H
