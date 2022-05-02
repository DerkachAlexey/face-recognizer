#include "common/application/PersonRemovalExecutor.hpp"
#include "services/ServicesLocator.hpp"
#include "services/DBManager.hpp"
#include "services/ArgsInterpreter.hpp"

#include <filesystem>

namespace fr
{

namespace common
{

void PersonRemovalExecutor::execute()
{
    auto dbManager =
        services::ServicesLocator::getService<services::db::DBManager>();

    auto argsInterpreter =
        services::ServicesLocator::getService<services::ArgumentsInterpreter>();

    const auto& nameToRemove = argsInterpreter->getNameToRemove();

    auto photoPath = dbManager->read(nameToRemove);

    if (!photoPath)
    {
        m_logger.error("Person " + nameToRemove + " doesn't exist in database");
    }

    std::filesystem::remove(*photoPath);

    if(dbManager->remove(nameToRemove))
    {
        m_logger.info("Person " + nameToRemove + " was succesfully removed");
    }
}

} //namespace common
} //namespace fr
