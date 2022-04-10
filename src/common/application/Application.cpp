#include "Application.hpp"
#include "Constants.hpp"
#include "EnumNamesProvider.hpp"
#include "ServicesLocator.hpp"
#include "ApplicationExecutorFactory.hpp"

namespace fr
{

namespace common
{

Application::Application(int argc, char **argv):
    m_logger("fr.common.Application"), m_argsInterpreter(argc, argv)
{
    m_mode = m_argsInterpreter.getInterpretedMode();
    m_logger.info("Application initialized");
    m_logger.info("Application mode: " +
                fr::services::ServicesLocator::getService<
                    fr::services::EnumNamesProvider>()
                      ->getName(m_mode));
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
