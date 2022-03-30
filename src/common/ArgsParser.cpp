#include "ArgsParser.hpp"
#include "Constants.hpp"

namespace fr {
namespace common {
ArgsParser::ArgsParser(int argc, char **argv)
    : m_argsParser(constants::applicationName)
{}
} // namespace common
} // namespace fr
