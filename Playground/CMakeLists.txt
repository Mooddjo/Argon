cmake_minimum_required(VERSION 3.15)

project(Playground)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})