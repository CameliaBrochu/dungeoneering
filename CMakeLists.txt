cmake_minimum_required(VERSION 3.24)
project(dungeoneering)

set(CMAKE_CXX_STANDARD 14)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(dungeoneering
        app/main.cpp)

add_subdirectory(glfw)
target_link_libraries(dungeoneering opengl32)
target_link_libraries(dungeoneering glfw)


