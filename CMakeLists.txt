cmake_minimum_required(VERSION 3.20)
project(ASCIIGraph_V2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all source files
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(asciigraph ${SOURCES})

# Include directories
target_include_directories(asciigraph PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Optional: Add compiler warnings
if(MSVC)
    target_compile_options(asciigraph PRIVATE /W4)
else()
    target_compile_options(asciigraph PRIVATE -Wall -Wextra -Wpedantic)
endif()
