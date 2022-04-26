#include "DBManager.hpp"
#include "Constants.hpp"
#include "common/Constants.hpp"
#include "services/ServicesLocator.hpp"
#include "services/PathProvider.hpp"

#include <filesystem>

namespace fr
{

namespace services
{

namespace db
{

DBManager::DBManager()
{
    auto pathProvider = ServicesLocator::getService<PathProvider>();
    const auto& dbPath = pathProvider->getPath(enums::Path::DATABASE);

    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, dbPath, &m_DB);
}

void DBManager::write(const std::string &key, const std::string &value)
{
    m_DB->Put(leveldb::WriteOptions(), key, value);
}

std::optional<std::string> DBManager::read(const std::string &key) const
{
    std::string value;

    if (auto status = m_DB->Get(leveldb::ReadOptions(), key, &value);
        !status.ok())
    {
        return std::nullopt;
    }

    return value;
}

} // namespace db
} // namespace services
} // namespace fr
