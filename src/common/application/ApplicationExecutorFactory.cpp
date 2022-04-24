#include "ApplicationExecutorFactory.hpp"
#include "PhotosApplicationExecutor.hpp"
#include "PersonRegistrationExecutor.hpp"

namespace fr
{

namespace common
{

std::shared_ptr<IApplicationExecutor> ApplicationExecutorFactory::makeAppExecutor(
    enums::ApplicationMode appMode)
{
    switch (appMode)
    {
    case enums::ApplicationMode::PHOTO:
        return std::make_shared<PhotosApplicationExecutor>();
    case enums::ApplicationMode::REGISTRATION:
        return std::make_shared<PersonRegistrationExecutor>();
    default:
        m_logger.error("Provided invalid application mode");
        throw std::invalid_argument("invalid app mode");
    }
}

} // namespace fr
} // namespace common
