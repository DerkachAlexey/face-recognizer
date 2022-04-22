#include "LogService.hpp"
#include "Constants.hpp"

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
    std::filesystem::current_path(common::constants::homeDir);
    std::filesystem::current_path(common::constants::configFolder);
    std::filesystem::current_path(common::constants::projectFolder);
    std::filesystem::current_path(common::constants::logDirectoryName);

    m_logsDirectory = std::filesystem::current_path();

    std::filesystem::current_path(common::constants::homeDir);
}

void LogService::configureLogFile()
{
    std::filesystem::path logsDir(m_logsDirectory);

    auto directoryIt = std::filesystem::directory_iterator(
        logsDir);

    const auto numberOfFile = std::distance(begin(directoryIt), end(directoryIt));

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
