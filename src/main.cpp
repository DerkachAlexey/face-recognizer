#include "application/Application.hpp"
#include "EnumNamesProvider.hpp"
#include "ServicesLocator.hpp"
#include "LogService.hpp"
#include "Logger.hpp"

#include <filesystem>

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

    std::filesystem::current_path(constants::homeDir);
}

void registerServices()
{
    using namespace fr::services;

    auto namesProvider = std::make_shared<EnumNamesProvider>();
    auto logService = std::make_shared<LogService>();

   ServicesLocator::registerService<EnumNamesProvider>(namesProvider);
   ServicesLocator::registerService<LogService>(logService);
}

int main(int argc, char **argv)
{
    try
    {
        configureFilesystem();
        registerServices();
    }
    catch (...)
    {
        return 1;
    }

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
