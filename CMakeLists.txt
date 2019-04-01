cmake_minimum_required(VERSION 3.13)
project(PO_C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(PO_C
        src/main.cpp src/World/World.cpp src/World/World.h src/World/Field.cpp src/World/Field.h src/Organisms/Organism.cpp
        src/Organisms/Organism.h src/Organisms/Animal.cpp src/Organisms/Animal.h src/Organisms/Human/Human.cpp
        src/Organisms/Human/Human.h src/Renderer/Notifications.cpp src/Renderer/Notifications.h src/Renderer/Renderer.cpp src/Renderer/Renderer.h)

SET(GCC_COVERAGE_COMPILE_FLAGS "-I/usr/include/ -pthread")
SET(GCC_COVERAGE_LINK_FLAGS    "-L/usr/lib -lcaca")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
