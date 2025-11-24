cmake_minimum_required(VERSION 4.0)
project(Lance LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/glfw)
add_subdirectory(engine)
add_subdirectory(game)
