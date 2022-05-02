#include_directories(common)
#include_directories(services)
#include_directories(cvDomain)
include_directories(.)

add_subdirectory(common)
add_subdirectory(services)
add_subdirectory(cvDomain)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

target_link_libraries(${PROJECT_NAME} common services)
