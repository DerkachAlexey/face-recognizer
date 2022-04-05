#include "Application.hpp"
#include "Constants.hpp"
#include "EnumNamesProvider.hpp"
#include "ServicesLocator.hpp"

namespace fr
{

namespace common
{

Application::Application(int argc, char **argv):
    m_logger("fr.common.Application"), m_argsInterpreter(argc, argv)
{
  m_logger.info("Application started");
  m_logger.info("Application mode: " +
                fr::services::ServicesLocator::getService<
                    fr::services::EnumNamesProvider>()
                    ->getName(m_argsInterpreter.getInterpretedMode()));
}
} // namespace common
} // namespace fr
