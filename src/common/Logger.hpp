#ifndef COMMON_LOGGER
#define COMMON_LOGGER

#include <memory>
#include <spdlog/spdlog.h>
#include <string>

#include "Constants.hpp"

namespace fr {
namespace common {

class Logger {

public:
  Logger(const std::string &loggerName);

  void trace(const std::string &msg);
  void debug(const std::string &msg);
  void info(const std::string &msg);
  void warn(const std::string &msg);
  void error(const std::string &msg);
  void critical(const std::string &msg);

private:
  void configureLogsDirectory(const std::string &relativeLogDirectory);
  void configureLogFile(const std::string &logFile);

private:
  std::shared_ptr<spdlog::logger> m_logger;
  std::string m_logsDirectory;
  std::string m_logFilePath;
};

} // namespace common
} // namespace fr

#endif
