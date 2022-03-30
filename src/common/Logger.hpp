#ifndef COMMON_LOGGER
#define COMMON_LOGGER

#include <memory>
#include <string>
#include <spdlog/spdlog.h>

namespace fr {
namespace common {
class Logger
{
public:
    enum class LogLevel {
        TRACE = 0,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        CRITICAL,
        FATAL
    };

public:
    Logger(const std::string &loggerName);

    void warn(const std::string &msg);

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
