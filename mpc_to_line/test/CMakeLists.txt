cmake_minimum_required(VERSION 3.5)
project(mpc_to_line_test CXX)

set(sources test_mpc_to_line.cc)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${sources})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  target_link_libraries(${PROJECT_NAME} mpc ipopt python2.7 ${CONAN_LIBS})
else()
  target_link_libraries(${PROJECT_NAME} mpc ipopt python ${CONAN_LIBS})
endif()

add_test(
    NAME ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMAND ${PROJECT_NAME}
)
