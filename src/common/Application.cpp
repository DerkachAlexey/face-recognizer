#include "Application.hpp"

namespace fr {

namespace common {

Application::Application(int argc, char **argv)
    : m_logger("fr.common.Application") {
    m_logger.info("Application started");
}
} // namespace common
} // namespace fr
