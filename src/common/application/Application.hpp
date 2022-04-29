#ifndef COMMON_APPLICATION_APPLICATION_H
#define COMMON_APPLICATION_APPLICATION_H

#include "IApplication.hpp"
#include "Logger.hpp"
#include "Enums.hpp"

namespace fr
{

namespace common
{

class Application : public IApplication
{
public:
    Application(int argc, char **argv);

    void startup() override;
private:
    Logger m_logger;
    enums::ApplicationMode m_mode;
};

} // namespace common
} // namespace fr

#endif // COMMON_APPLICATION_APPLICATION_H
