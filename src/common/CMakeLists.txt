set(COMMON_SRC
            application/IApplicationExecutor.hpp
            application/IApplication.hpp
            application/Application.hpp
            application/Application.cpp
            application/ApplicationExecutorFactory.hpp
            application/PersonRegistrationExecutor.hpp
            application/PersonRegistrationExecutor.cpp
            application/ApplicationExecutorFactory.cpp
            application/PersonRecognitionExecutor.hpp
            application/PersonRecognitionExecutor.cpp
            application/PersonRemovalExecutor.hpp
            application/PersonRemovalExecutor.cpp
            Constants.hpp
            Logger.hpp
            Logger.cpp
            UUID.hpp
            UUID.cpp
            Enums.hpp)

include_directories(..)

add_library(common ${COMMON_SRC})

target_link_libraries(common spdlog argparse cvDom)

