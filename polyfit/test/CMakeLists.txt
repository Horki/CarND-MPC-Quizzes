cmake_minimum_required(VERSION 3.5)
project(polyfit_test CXX)

set(sources test_polyfit.cc)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME}
  PUBLIC
  polynomial
  ${CONAN_LIBS})

# enable_testing()
add_test(
    NAME ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMAND ${PROJECT_NAME}
)
