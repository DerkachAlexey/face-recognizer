#include "application/Application.hpp"
#include "EnumNamesProvider.hpp"
#include "ServicesLocator.hpp"
#include "LogService.hpp"
#include "Logger.hpp"

#include <filesystem>

void configureFilesystem()
{
    using namespace fr::common;

    std::filesystem::current_path(std::filesystem::temp_directory_path());

    const auto& projectRoot = constants::projectRoot;

    if (!std::filesystem::exists(projectRoot))
    {
        std::filesystem::create_directory(projectRoot);
    }

    std::filesystem::current_path(projectRoot);
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
