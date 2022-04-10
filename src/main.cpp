#include "application/Application.hpp"
#include "EnumNamesProvider.hpp"
#include "ServicesLocator.hpp"
#include "Logger.hpp"

void registerServices()
{

    auto namesProvider = std::make_shared<fr::services::EnumNamesProvider>();
    fr::services::ServicesLocator::registerService<
        fr::services::EnumNamesProvider>(namesProvider);
}

int main(int argc, char **argv)
{

    fr::common::Logger logger("main");

    try
    {

        registerServices();
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
