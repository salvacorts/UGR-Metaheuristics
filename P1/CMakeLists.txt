cmake_minimum_required(VERSION 2.8.9)
project(practica1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)


include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(practica1 ${SOURCES})