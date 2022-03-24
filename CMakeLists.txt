cmake_minimum_required(VERSION 3.15)

project(face-pos-detector)

set(SRC	main.cpp)

add_subdirectory(third-party)
add_executable(${CMAKE_PROJECT_NAME} ${SRC})

target_link_libraries(${CMAKE_PROJECT_NAME} argparse)
