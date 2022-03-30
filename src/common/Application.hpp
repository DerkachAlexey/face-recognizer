#ifndef COMMON_APPLICATION
#define COMMON_APPLICATION

#include "Logger.hpp"

namespace fr {

namespace common {

class Application
{
public:
    Application(int argc, char **argv);

private:    
    Logger m_logger;
};

} // namespace common
} // namespace fr

#endif
