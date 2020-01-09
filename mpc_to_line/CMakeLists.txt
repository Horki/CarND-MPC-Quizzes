project(mpc CXX)

cmake_minimum_required (VERSION 3.5)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# enable_testing()
# add_subdirectoy(test)

set(sources src/MPC.cpp src/main.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(${PROJECT_NAME} ${sources})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  target_link_libraries(${PROJECT_NAME} ipopt python2.7 ${CONAN_LIBS})
else()
  target_link_libraries(${PROJECT_NAME} ipopt python ${CONAN_LIBS})
endif()
