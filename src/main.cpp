#include "Constants.hpp"
#include "EnumNamesProvider.hpp"
#include "LogService.hpp"
#include "Logger.hpp"
#include "ServicesLocator.hpp"
#include "application/Application.hpp"
#include "database/DBManager.hpp"

#include <filesystem>

void configureDatabaseFolder()
{
    using namespace fr::common;

    if (!std::filesystem::exists(constants::photosDatabaseFolder))
    {
        std::filesystem::create_directory(constants::photosDatabaseFolder);
    }
}

void configureLogsFolder()
{
    using namespace fr::common;

    if (!std::filesystem::exists(constants::logDirectoryName))
    {
        std::filesystem::create_directory(constants::logDirectoryName);
    }
}

void configureSourceFolder()
{
    using namespace fr::common;

    if (!std::filesystem::exists(constants::sourcePhotosFolder))
    {
        std::filesystem::create_directory(constants::sourcePhotosFolder);
    }
}

void configureFilesystem()
{
    using namespace fr::common;

    std::filesystem::current_path(constants::homeDir);

    const auto& homePath = std::filesystem::current_path();

    std::filesystem::current_path(homePath);
    std::filesystem::current_path(constants::configFolder);

    if (!std::filesystem::exists(constants::projectFolder))
    {
        std::filesystem::create_directory(constants::projectFolder);
    }

    std::filesystem::current_path(constants::projectFolder);

    configureLogsFolder();
    configureSourceFolder();
    configureDatabaseFolder();

    std::filesystem::current_path(constants::homeDir);
}

void registerServices()
{
    using namespace fr::services;

    auto namesProvider = std::make_shared<EnumNamesProvider>();
    auto logService = std::make_shared<LogService>();
    auto dbService = std::make_shared<db::DBManager>();

    ServicesLocator::registerService<EnumNamesProvider>(namesProvider);
    ServicesLocator::registerService<LogService>(logService);
    ServicesLocator::registerService<db::DBManager>(dbService);
}

int main(int argc, char **argv)
{
    configureFilesystem();
    registerServices();

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
