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

    auto dbInstance = m_DB.get();
    leveldb::Status status = leveldb::DB::Open(options, getDBPath(), &dbInstance);
}

std::string DBManager::getDBPath() const
{
    std::filesystem::current_path(common::constants::homeDir);
    std::filesystem::current_path(common::constants::configFolder);

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
