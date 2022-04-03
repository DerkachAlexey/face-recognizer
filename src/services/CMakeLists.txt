set(SRC_SERVICE	
		IService.hpp
                ServicesLocator.hpp
                EnumNamesProvider.hpp
                EnumNamesProvider.cpp)

include_directories(../common/)
add_library(services ${SRC_SERVICE})
