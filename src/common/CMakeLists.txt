set(COMMON_SRC
            application/IApplicationExecutor.hpp
            application/IApplication.hpp
            application/Application.hpp
            application/Application.cpp
            application/ApplicationExecutorFactory.hpp
            application/PhotosApplicationExecutor.hpp
            application/PhotosApplicationExecutor.cpp
            application/PersonRegistrationExecutor.hpp
            application/PersonRegistrationExecutor.cpp
            application/ApplicationExecutorFactory.cpp
            Constants.hpp
            Logger.hpp
            Logger.cpp
            UUID.hpp
            UUID.cpp
	    ArgsInterpreter.hpp
            ArgsInterpreter.cpp
            Enums.hpp)

include_directories(..)

add_library(common ${COMMON_SRC})

target_link_libraries(common spdlog argparse cvDom)

