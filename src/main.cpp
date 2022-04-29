#include "Constants.hpp"
#include "EnumNamesProvider.hpp"
#include "LogService.hpp"
#include "Logger.hpp"
#include "ServicesLocator.hpp"
#include "application/Application.hpp"
#include "services/DBManager.hpp"
#include "services/PathProvider.hpp"
#include "services/ArgsInterpreter.hpp"

#include <filesystem>

void registerServices(int argc, char **argv)
{
    using namespace fr::services;

    auto pathProvider = std::make_shared<PathProvider>();
    ServicesLocator::registerService<PathProvider>(pathProvider);

    auto namesProvider = std::make_shared<EnumNamesProvider>();
    auto logService = std::make_shared<LogService>();
    auto dbService = std::make_shared<db::DBManager>();
    auto argsInterpreter = std::make_shared<ArgumentsInterpreter>(argc, argv);

    ServicesLocator::registerService<EnumNamesProvider>(namesProvider);
    ServicesLocator::registerService<LogService>(logService);
    ServicesLocator::registerService<db::DBManager>(dbService);
    ServicesLocator::registerService<ArgumentsInterpreter>(argsInterpreter);
}

int main(int argc, char **argv)
{
    registerServices(argc, argv);

    fr::common::Logger logger("main");

    try
    {
        fr::common::Application app(argc, argv);
        app.startup();
    }
    catch (std::exception& ex)
    {
        logger.critical(ex.what());
        return 1;
    }

    return 0;
}
