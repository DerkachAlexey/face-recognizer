#include "services/DBManager.hpp"
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

bool DBManager::write(const std::string &key, const std::string &value)
{
    return m_DB->Put(leveldb::WriteOptions(), key, value).ok();
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

std::vector<DBManager::dbNote>
DBManager::loadAllData() const
{
    std::vector<DBManager::dbNote> data;

    auto it = m_DB->NewIterator(leveldb::ReadOptions());

    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        data.emplace_back(it->key().ToString(), it->value().ToString());
    }

    delete it;

    return data;
}

} // namespace db
} // namespace services
} // namespace fr
