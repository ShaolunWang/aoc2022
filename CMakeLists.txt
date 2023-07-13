cmake_minimum_required (VERSION 3.20)
project(AdventOfCode LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
project (AdventOfCode)
add_executable(aoc
	aoc.cpp
	src/day01.cpp
	src/day02.cpp
	util/utils.cpp)
