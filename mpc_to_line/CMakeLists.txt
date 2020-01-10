project(mpc_to_line CXX)

cmake_minimum_required (VERSION 3.5)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

enable_testing()
add_subdirectory(test)

add_library(mpc include/MPC.hpp include/helpers.hpp src/MPC.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

target_include_directories(mpc
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  target_link_libraries(${PROJECT_NAME} mpc ipopt python2.7 ${CONAN_LIBS})
else()
  target_link_libraries(${PROJECT_NAME} mpc ipopt python ${CONAN_LIBS})
endif()
