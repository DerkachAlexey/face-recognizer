#ifndef SERVICES_DBMANAGER_H
#define SERVICES_DBMANAGER_H

#include <leveldb/db.h>
#include <memory>
#include <optional>

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

    void write(const std::string &key,
               const std::string &value);

    std::optional<std::string> read(const std::string &key) const;

private:
    leveldb::DB* m_DB;
};

} // namespace db
} // namespace services
} // namespace fr

#endif // SERVICES_DBMANAGER_H
