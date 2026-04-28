cmake_minimum_required(VERSION 3.16)

project(DeterministicSimulationDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(deterministic_simulation_demo
        src/main.cpp
)