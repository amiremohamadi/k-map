cmake_minimum_required(VERSION 3.5)

project(k-map LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS OFF)

file(GLOB SOURCE_FILES source/*.cpp)
file(GLOB HEADER_FILES src/*.hpp)

add_executable(kmap ${SOURCE_FILES} ${HEADER_FILES})
