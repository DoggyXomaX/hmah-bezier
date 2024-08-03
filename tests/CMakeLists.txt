cmake_minimum_required(VERSION 3.14)
project(HmahBezierLibTests)

unset(CMAKE_CXX_COMPILER)

function(add_test TEST_NAME)
  add_executable(${TEST_NAME} "${TEST_NAME}.c")
  target_include_directories(${TEST_NAME} PRIVATE ../src)
  target_link_libraries(${TEST_NAME} PRIVATE hmahbezier)
endfunction()

add_test(linear_test)
add_test(quadratic_test)
add_test(cubic_test)