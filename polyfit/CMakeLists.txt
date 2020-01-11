cmake_minimum_required (VERSION 3.5)
project(polyfit CXX)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

enable_testing()
add_subdirectory(test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(sources src/polynomial.cpp)
add_library(polynomial SHARED ${sources})
target_link_libraries(polynomial ${CONAN_LIBS_EIGEN})
target_include_directories(polynomial
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
  polynomial
  ${CONAN_LIBS_EIGEN}
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include)
