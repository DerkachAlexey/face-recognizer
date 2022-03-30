set(COMMON_SRC
            Application.hpp
            Application.cpp
            Constants.hpp
            Logger.hpp
            Logger.cpp
            UUID.hpp
            UUID.cpp)

add_library(common ${COMMON_SRC})
target_link_libraries(common spdlog argparse)
