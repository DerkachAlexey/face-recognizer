#ifndef SERVICES_LOGSERVICE_HPP
#define SERVICES_LOGSERVICE_HPP

#include "IService.hpp"

#include <string>

namespace fr
{

namespace services
{

class LogService : public IService
{
public:
    LogService();

    std::string getLogFilePath() const;

private:
    void configureLogsDirectory(const std::string &relativeLogDirectory);
    void configureLogFile(const std::string &logFile);

private:
    std::string m_logsDirectory;
    std::string m_logFilePath;
};

} // namespace services
} // namespace fr

#endif // SERVICES_LOGSERVICE_HPP