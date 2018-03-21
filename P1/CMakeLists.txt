cmake_minimum_required(VERSION 2.8.9)
project(practica1)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)

include(CMakeToolsHelpers OPTIONAL)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(practica1 ${SOURCES})