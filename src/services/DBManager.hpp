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
    using dbNote = std::pair<std::string, std::string>;
public:
    DBManager();

    bool write(const std::string &key,
               const std::string &value);

    std::optional<std::string> read(const std::string &key) const;
    std::vector<dbNote> loadAllData() const;

private:
    leveldb::DB* m_DB;
};

} // namespace db
} // namespace services
} // namespace fr

#endif // SERVICES_DBMANAGER_H
