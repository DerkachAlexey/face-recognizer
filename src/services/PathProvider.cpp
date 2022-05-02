#include "services/PathProvider.hpp"
#include "services/Constants.hpp"
#include "common/Constants.hpp"

#include <filesystem>

namespace fr
{

namespace services
{

namespace
{

void configureDatabaseFolder()
{
    if (!std::filesystem::exists(constants::photosDatabaseFolder))
    {
        std::filesystem::create_directory(constants::photosDatabaseFolder);
    }
}

void configureLogsFolder()
{
    if (!std::filesystem::exists(constants::logDirectoryName))
    {
        std::filesystem::create_directory(constants::logDirectoryName);
    }
}

void configureSourceFolder()
{
    if (!std::filesystem::exists(constants::sourcePhotosFolder))
    {
        std::filesystem::create_directory(constants::sourcePhotosFolder);
    }
}

}

PathProvider::PathProvider()
{
    configureFilesystem();
}

std::string PathProvider::getPath(enums::Path path) const
{
    switch (path)
    {
    case enums::Path::CONFIGS:
        return getConfigsPath();
    case enums::Path::DATABASE:
        return getDatabasePath();
    case enums::Path::HOME:
        return getHomePath();
    case enums::Path::LOGS:
        return getLogsPath();
    case enums::Path::PHOTOS_BASE:
        return getPhotosBasePath();
    case enums::Path::SOURCE_PHOTOS:
        return getSourcePhotosPath();
    case enums::Path::PROJECT:
        return getProjectFolderPath();
    default:
        return std::string();
    }

    return std::string();
}

void PathProvider::configureFilesystem()
{
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

std::string PathProvider::getConfigsPath() const
{
    std::filesystem::current_path(constants::homeDir);
    std::filesystem::current_path(constants::configFolder);

    const auto& configDir = std::filesystem::current_path();

    std::filesystem::current_path(constants::homeDir);

    return configDir;
}

std::string PathProvider::getDatabasePath() const
{
    auto projectPath = getProjectFolderPath();
    auto dbPath = projectPath
                  + std::filesystem::path::preferred_separator
                  + constants::dbName;

    return dbPath;
}

std::string PathProvider::getHomePath() const
{
    return constants::homeDir;
}

std::string PathProvider::getLogsPath() const
{
    auto projectPath = getProjectFolderPath();

    return projectPath+ std::filesystem::path::preferred_separator
           + constants::logDirectoryName;
}

std::string PathProvider::getProjectFolderPath() const
{
    auto configPath = getConfigsPath();

    return configPath + std::filesystem::path::preferred_separator
           + constants::projectFolder;
}

std::string PathProvider::getPhotosBasePath() const
{
    auto projectPath = getProjectFolderPath();

    return projectPath+ std::filesystem::path::preferred_separator
           + constants::photosDatabaseFolder;
}

std::string PathProvider::getSourcePhotosPath() const
{
    auto projectPath = getProjectFolderPath();

    return projectPath+ std::filesystem::path::preferred_separator
           + constants::sourcePhotosFolder;
}

} // namespace services
} // namespace fr
