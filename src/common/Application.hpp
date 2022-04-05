#ifndef COMMON_APPLICATION
#define COMMON_APPLICATION

#include "Logger.hpp"
#include "ArgsInterpreter.hpp"

namespace fr
{

namespace common
{

class Application
{
public:
    Application(int argc, char **argv);

private:    
    Logger m_logger;
    ArgumentsInterpreter m_argsInterpreter;

};

} // namespace common
} // namespace fr

#endif
