#ifndef COMMON_APPLICATION
#define COMMON_APPLICATION

#include "Logger.hpp"

#include <argparse/argparse.hpp>

namespace fr {

namespace common {

class Application
{
public:
    Application(int argc, char **argv);

private:
    argparse::ArgumentParser m_argsParser;
    Logger m_logger;
};

} // namespace common
} // namespace fr

#endif
