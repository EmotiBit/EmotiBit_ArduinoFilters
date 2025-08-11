cmake_minimum_required(VERSION 3.18)
project(Arduino-Filters CXX)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add coverage target
option(AH_WITH_COVERAGE
    "Generate coverage information." Off)
if (AH_WITH_COVERAGE)
    add_custom_target(coverage
        ${CMAKE_CURRENT_LIST_DIR}/scripts/coverage.sh
        ${CMAKE_CXX_COMPILER_ID}
        ${CMAKE_CXX_COMPILER_VERSION}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fno-inline")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fno-inline")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    add_dependencies(coverage Arduino-Helpers::tests)
endif()

# Add documentation target
find_program(AH_DOXYGEN doxygen)
if (AH_DOXYGEN)
    add_custom_target(documentation
        doxygen
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/doxygen)
endif()

# Compiler warnings
option(AH_WARNINGS_AS_ERRORS "Enable -Werror" Off)
include(cmake/Warnings.cmake)

# Build the source files and tests
add_subdirectory(mock)
add_subdirectory(src)
add_subdirectory(test)
