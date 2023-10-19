cmake_minimum_required(VERSION 3.24)
project(dungeoneering)

set(CMAKE_CXX_STANDARD 14)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(dungeoneering
        app/main.cpp app/App.cpp app/App.h app/Window/Window.cpp app/Window/Window.h app/Shader/Shader.h app/Shader/Program.h)

add_subdirectory(glfw)
target_link_libraries(dungeoneering opengl32)
target_link_libraries(dungeoneering glfw)

add_subdirectory(glad)
target_link_libraries(dungeoneering glad)


