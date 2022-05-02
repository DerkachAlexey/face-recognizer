#ifndef APPLICATIONEXECUTORSFACTORY_H
#define APPLICATIONEXECUTORSFACTORY_H

#include <memory>

#include "common/Enums.hpp"
#include "common/application/IApplicationExecutor.hpp"
#include "common/Logger.hpp"

namespace fr
{

namespace common
{

class ApplicationExecutorFactory
{
public:
    std::shared_ptr<IApplicationExecutor> makeAppExecutor(
        enums::ApplicationMode appMode);

private:
    common::Logger m_logger{"fr.common.ApplicationExecutorFactory"};
};

} // namespace fr
} // namespace common

#endif // APPLICATIONEXECUTORSFACTORY_H
