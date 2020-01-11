cmake_minimum_required(VERSION 3.5)
project(global_kinematic_model_test CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} test_global_kinematic_model.cc)
target_link_libraries(${PROJECT_NAME}
  PUBLIC
  kinematic
  ${CONAN_LIBS})

add_test(
    NAME ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMAND ${PROJECT_NAME}
)
