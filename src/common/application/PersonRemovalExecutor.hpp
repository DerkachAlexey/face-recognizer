#ifndef COMMON_APPLICATION_PERSONREMOVALEXECUTOR_H
#define COMMON_APPLICATION_PERSONREMOVALEXECUTOR_H

#include "common/application/IApplicationExecutor.hpp"
#include "common/Logger.hpp"

namespace fr
{

namespace common
{

class PersonRemovalExecutor : public IApplicationExecutor
{
public:
    void execute() override;

private:
    Logger m_logger{"fr.common.application.PersonRemovalExecutor"};
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_PERSONREMOVALEXECUTOR_H
