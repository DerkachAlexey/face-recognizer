include_directories(common)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} argparse spdlog)
