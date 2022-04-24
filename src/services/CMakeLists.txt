set(SRC_SERVICE	
		IService.hpp
                ServicesLocator.hpp
                EnumNamesProvider.hpp
                EnumNamesProvider.cpp
                database/DBManager.hpp
                database/DBManager.cpp
                database/Constants.hpp
                LogService.hpp
                LogService.cpp)

find_package(leveldb REQUIRED)

include_directories(${LEVELDB_INCLUDE_DIRS})
include_directories(../)

add_library(services ${SRC_SERVICE})
target_link_libraries( services leveldb )
