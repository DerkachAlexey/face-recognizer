#include "common/application/ApplicationExecutorFactory.hpp"
#include "common/application/PersonRegistrationExecutor.hpp"
#include "common/application/PersonRecognitionExecutor.hpp"

namespace fr
{

namespace common
{

std::shared_ptr<IApplicationExecutor> ApplicationExecutorFactory::makeAppExecutor(
    enums::ApplicationMode appMode)
{
    switch (appMode)
    {
    case enums::ApplicationMode::REGISTRATION:
        return std::make_shared<PersonRegistrationExecutor>();
    case enums::ApplicationMode::RECOGNITION:
        return std::make_shared<PersonRecognitionExecutor>();
    default:
        m_logger.error("Provided invalid application mode");
        throw std::invalid_argument("invalid app mode");
    }
}

} // namespace fr
} // namespace common
