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
    configureLogsDirectory(common::constants::logDirectoryName);
    configureLogFile(common::constants::logFileName);
}

std::string LogService::getLogFilePath() const
{
    return m_logFilePath;
}

void LogService::configureLogsDirectory(const std::string &relativeLogDirectory)
{
   const auto curPath = std::filesystem::current_path().string();

   auto logsPathView = curPath +
                       std::filesystem::path::preferred_separator +
                       relativeLogDirectory;


    std::filesystem::path logsPath(logsPathView);

    if (!std::filesystem::exists(logsPath))
    {
        std::filesystem::create_directory(logsPath);
    }

    m_logsDirectory = logsPathView;
}

void LogService::configureLogFile(const std::string &logFile)
{
    std::filesystem::path logsDir(m_logsDirectory);

    auto directoryIt = std::filesystem::directory_iterator(
        logsDir);

    const auto numberOfFile = std::distance(begin(directoryIt), end(directoryIt));

    auto logFileFullName = logFile
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
