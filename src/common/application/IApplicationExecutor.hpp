#ifndef COMMON_APPLICATION_IAPPLICATIONEXECUTOR_H
#define COMMON_APPLICATION_IAPPLICATIONEXECUTOR_H

namespace fr
{

namespace common
{

class IApplicationExecutor
{
public:
    virtual void execute() = 0;
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_IAPPLICATIONEXECUTOR_H
