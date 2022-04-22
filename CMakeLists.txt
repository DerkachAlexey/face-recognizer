cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
project(face-recognizer)

add_subdirectory(third-party)
add_subdirectory(src)

install(DIRECTORY data DESTINATION share)
