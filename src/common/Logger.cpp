#include "Logger.hpp"
#include "LogService.hpp"
#include "ServicesLocator.hpp"
#include "Constants.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace fr
{

namespace common
{

Logger::Logger(const std::string &loggerName)
{
  const auto& logService =
        services::ServicesLocator::getService<services::LogService>();

  const auto& logFilePath = logService->getLogFilePath();
  m_logger = spdlog::basic_logger_mt(loggerName, logFilePath);
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

} // namespace common
} // namespace fr
