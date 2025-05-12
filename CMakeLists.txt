
cmake_minimum_required(VERSION 3.10)
project(GameBoyEmulator VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)


set(SOURCES
    src/main.cpp
    src/cpu/cpu.cpp
    )


add_executable(gbemu ${SOURCES})
target_link_libraries(gbemu ${SDL2_LIBRARIES})
