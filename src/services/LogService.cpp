#include "services/LogService.hpp"
#include "services/Constants.hpp"
#include "common/Constants.hpp"
#include "services/PathProvider.hpp"
#include "services/ServicesLocator.hpp"

#include <filesystem>
#include <fstream>

namespace fr
{

namespace services
{

LogService::LogService()
{
    configureLogsDirectory();
    configureLogFile();
}

std::string LogService::getLogFilePath() const
{
    return m_logFilePath;
}

void LogService::configureLogsDirectory()
{
    auto pathProvider = ServicesLocator::getService<PathProvider>();

    m_logsDirectory = std::filesystem::path(
        pathProvider->getPath(enums::Path::LOGS));
}

void LogService::configureLogFile()
{
    std::filesystem::path logsDir(m_logsDirectory);

    auto directoryIt = std::filesystem::directory_iterator(
        logsDir);

    const auto numberOfFile = std::distance(begin(directoryIt), end(directoryIt)) + 1;

    auto logFileFullName = common::constants::logFileName
                           + common::constants::filesExtensionSeparator
                           + std::to_string(numberOfFile)
                           + common::constants::filesExtensionSeparator
                           + common::constants::logFileExtension;

    const auto &logFilePathView =
        m_logsDirectory
        + std::filesystem::path::preferred_separator
        + logFileFullName;

    if (!std::filesystem::exists(logFilePathView))
    {
        std::ofstream stream(logFilePathView);
    }

    m_logFilePath = logFilePathView;
}

} // namespace services
} // namespace fr
