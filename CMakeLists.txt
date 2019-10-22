cmake_minimum_required(VERSION 3.11)
project(example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenGL
set( OpenGL_GL_PREFERENCE GLVND )
find_package(OpenGL REQUIRED)

# GLFW
# find_package(glfw3 REQUIRED)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw-3.3)
include_directories(glfw-3.3/include)

# GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(main src/main.cpp)

target_link_libraries(main ${OPENGL_LIBRARY} glfw ${GLEW_LIBRARIES})
