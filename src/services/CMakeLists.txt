set(SRC_SERVICE	
		IService.hpp
                ServicesLocator.hpp
                EnumNamesProvider.hpp
                EnumNamesProvider.cpp
                LogService.hpp
                LogService.cpp)

include_directories(../common/)
add_library(services ${SRC_SERVICE})
