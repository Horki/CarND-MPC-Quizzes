cmake_minimum_required(VERSION 3.5)

project(global_kinematic_model CXX)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

enable_testing()
add_subdirectory(test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(sources src/kinematic.cpp)
add_library(kinematic SHARED ${sources})
target_link_libraries(kinematic ${CONAN_LIBS_EIGEN})
target_include_directories(kinematic
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
  kinematic
  ${CONAN_LIBS_EIGEN})

target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include)

