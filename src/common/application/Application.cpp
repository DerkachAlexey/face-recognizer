#include "Application.hpp"
#include "common/Constants.hpp"
#include "services/EnumNamesProvider.hpp"
#include "services/ServicesLocator.hpp"
#include "ApplicationExecutorFactory.hpp"
#include "services/ArgsInterpreter.hpp"

namespace fr
{

namespace common
{

using namespace fr::services;

Application::Application(int argc, char **argv):
    m_logger("fr.common.Application")
{
    auto argsInterpreter = ServicesLocator::getService<ArgumentsInterpreter>();
    m_mode = argsInterpreter->getInterpretedMode();
    m_logger.info("Application initialized");
    m_logger.info("Application mode: " + ServicesLocator::getService<
                    EnumNamesProvider>()->getName(m_mode));
}

void Application::startup()
{
    m_logger.info("Application started");

    ApplicationExecutorFactory factory;
    auto appExecutor = factory.makeAppExecutor(m_mode);
    appExecutor->execute();

    m_logger.info("Application finished");
}

} // namespace common
} // namespace fr
