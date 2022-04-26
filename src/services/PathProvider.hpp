#ifndef SERVICES_PATHPROVIDER_H
#define SERVICES_PATHPROVIDER_H

#include "IService.hpp"
#include "services/Enums.hpp"
#include <string>

namespace fr
{

namespace services
{

class PathProvider : public IService
{
public:
    PathProvider();

    std::string getPath(enums::Path path) const;

private:
    void configureFilesystem();
    std::string getConfigsPath() const;
    std::string getDatabasePath() const;
    std::string getHomePath() const;
    std::string getLogsPath() const;
    std::string getProjectFolderPath() const;
    std::string getPhotosBasePath() const;
    std::string getSourcePhotosPath() const;

};

} // namespace services
} // namespace fr

#endif // SERVICES_DBMANAGER_H
