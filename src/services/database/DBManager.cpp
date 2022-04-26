#include "DBManager.hpp"
#include "Constants.hpp"
#include "common/Constants.hpp"

#include <filesystem>

namespace fr
{

namespace services
{

namespace db
{

DBManager::DBManager()
{
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, getDBPath(), &m_DB);
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

std::string DBManager::getDBPath() const
{
    std::filesystem::current_path(common::constants::homeDir);
    std::filesystem::current_path(common::constants::configFolder);
    std::filesystem::current_path(common::constants::projectFolder);

    auto configPath = std::filesystem::current_path();
    auto dbPath = configPath.string()
                  + std::filesystem::path::preferred_separator
                  + db::constants::dbName;

    std::filesystem::current_path(common::constants::homeDir);

    return dbPath;
}

} // namespace db
} // namespace services
} // namespace fr
