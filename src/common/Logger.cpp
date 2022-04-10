#include "Logger.hpp"

#include <filesystem>
#include <fstream>
#include <spdlog/sinks/basic_file_sink.h>

namespace fr
{

namespace common
{

Logger::Logger(const std::string &loggerName)
{
  configureLogsDirectory(constants::logDirectoryName);
  configureLogFile(constants::logFileName);

  m_logger = spdlog::basic_logger_mt(loggerName, m_logFilePath);
  m_logger->set_pattern(constants::logPattern);
}

void Logger::trace(const std::string &msg)
{
    m_logger->trace(msg);
}

void Logger::warn(const std::string &msg)
{
    m_logger->warn(msg);
}

void Logger::error(const std::string &msg)
{
    m_logger->error(msg);
}

void Logger::critical(const std::string &msg)
{
    m_logger->critical(msg);
}

void Logger::info(const std::string &msg)
{
    m_logger->info(msg);
}

void Logger::debug(const std::string &msg)
{
    m_logger->debug(msg);
}

void Logger::configureLogsDirectory(const std::string &relativeLogDirectory)
{
  const auto &currentPath = std::filesystem::current_path();
  auto logsPathView = currentPath.string() +
                      std::filesystem::path::preferred_separator +
                      relativeLogDirectory;

  if (!std::filesystem::exists(logsPathView))
  {
    std::filesystem::create_directory(logsPathView);
  }

  m_logsDirectory = logsPathView;
}

void Logger::configureLogFile(const std::string &logFile)
{
  const auto &logFilePathView =
      m_logsDirectory + std::filesystem::path::preferred_separator + logFile;

  if (!std::filesystem::exists(logFilePathView))
  {
    std::ofstream stream(logFilePathView);
  }

  m_logFilePath = logFilePathView;
}

} // namespace common
} // namespace fr
