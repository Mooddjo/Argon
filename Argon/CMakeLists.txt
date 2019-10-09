cmake_minimum_required(VERSION 3.15)

project(Argon)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DARGON_BUILD)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})