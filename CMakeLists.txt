cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME WindowManager)
set(CXX_FLAGS "-Wall -Wextra")

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS ${CXX_FLAGS})

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/windowmanager.cpp
  src/windowmanager.hpp
  src/mainwindow.cpp
  src/mainwindow.hpp
  src/elemwidget.cpp
  src/elemwidget.hpp
  src/elemmanager.cpp
  src/elemmanager.hpp
  src/button.cpp
  src/button.hpp
  src/slider.cpp
  src/slider.hpp
  src/scrollbar.cpp
  src/scrollbar.hpp
  src/event.cpp
  src/event.hpp
  src/texture.cpp
  src/texture.hpp
  src/Renderer/shaderprogram.cpp
  src/Renderer/shaderprogram.hpp
  src/Renderer/vertexarray.cpp
  src/Renderer/vertexarray.hpp
  src/Renderer/textureva.cpp
  src/Renderer/textureva.hpp
  )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

include_directories(external/glm)

#include_directories(/home/artem/Main/WindowManager/src/Renderer/Shaders/)

target_link_libraries(${PROJECT_NAME} -lSOIL)
