#ifndef SERVICES_DBMANAGER_H
#define SERVICES_DBMANAGER_H

#include <leveldb/db.h>
#include <memory>

#include "IService.hpp"

namespace fr
{

namespace services
{

namespace db
{

class DBManager : public IService
{
public:
    DBManager();

private:
    std::string getDBPath() const;

private:
    std::unique_ptr<leveldb::DB> m_DB;
};

} // namespace db
} // namespace services
} // namespace fr

#endif // SERVICES_DBMANAGER_H
