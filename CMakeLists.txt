cmake_minimum_required(VERSION 3.17.0)
project(FootballEngine VERSION 0.1.0)

# Source files
set(SRC_DIR "src/FootballEngine")
#set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")
set(SOURCES "${SRC_DIR}/main.cpp")

# Main Executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# CPACK
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("src/vendor/glfw")
target_link_libraries(${PROJECT_NAME} glfw)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Glad
add_subdirectory(src/vendor/Glad/)
target_link_libraries(${PROJECT_NAME} glad ${CMAKE_DL_LIBS})