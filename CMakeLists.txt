cmake_minimum_required(VERSION 3.15)
project(CalculatorProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(include)

option(BUILD_TESTING "Enable tests" ON)

if(BUILD_TESTING)
    enable_testing()
endif()

add_subdirectory(src)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build configured. You can debug calculator_app executable.")
    message(STATUS "Main executable: ${CMAKE_CURRENT_BINARY_DIR}/src/calculator_app")
    if(BUILD_TESTING)
        message(STATUS "Test executable: ${CMAKE_CURRENT_BINARY_DIR}/tests/calculator_tests")
    endif()
endif()