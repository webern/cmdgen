# cppcmd by (c) Matthew James Briggs
cmake_minimum_required(VERSION 3.0)
project(cppcmd VERSION 0.0.1)
set(DEBUG_INFO "cppcmd/src/CMakeLists.txt")
message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} cppcmd cmake file starting")

option(CPPCMD_ENABLE_TESTS "Enable tests" OFF)
option(CPPCMD_ENABLE_EXAMPLE "When ON, builds the cppcmd_example executable, when off only the cppcmd library is built" OFF)

# Directories

set(DIR_CPPCMD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/private")
set(DIR_CPPCMD_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/lib/include")
set(DIR_EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/example")
set(DIR_EXAMPLE_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}")
set(DIR_CPPCMD_TEST "${CMAKE_CURRENT_SOURCE_DIR}/test")

# File Sets
file(GLOB FILES_CPPCMD_SOURCES ${DIR_CPPCMD_SOURCES}/*.cpp)
file(GLOB FILES_CPPCMD_HEADERS ${DIR_CPPCMD_INCLUDE}/*.h*)
file(GLOB FILES_EXAMPLE_SOURCES ${DIR_EXAMPLE_SOURCES}/*.cpp)
file(GLOB FILES_EXAMPLE_HEADERS ${DIR_EXAMPLE_INCLUDE}/*.h*)
file(GLOB_RECURSE FILES_CPPCMD_TEST_SOURCES ${DIR_CPPCMD_TEST}/*.cpp)
file(GLOB_RECURSE FILES_CPPCMD_TEST_HEADERS ${DIR_CPPCMD_TEST}/*.h*)

add_library(cppcmd "${FILES_CPPCMD_SOURCES}")
target_include_directories(cppcmd PUBLIC "${DIR_CPPCMD_INCLUDE}")
target_include_directories(cppcmd PRIVATE "${DIR_CPPCMD_SOURCES}")
set_property(TARGET cppcmd PROPERTY CXX_STANDARD 17)

if (${CPPCMD_ENABLE_EXAMPLE})
    message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} compiling cppcmd_example")
    add_executable(cppcmd_example ${FILES_EXAMPLE_SOURCES})
    set_property(TARGET cppcmd_example PROPERTY CXX_STANDARD 17)
endif ()

if (${CPPCMD_ENABLE_TESTS})
    message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} compiling tests")
    enable_testing()
    file(GLOB_RECURSE TEST_SOURCES "${DIR_CPPCMD_TEST}/*.cpp")
    add_executable(cppcmd_test ${TEST_SOURCES})
    set_property(TARGET cppcmd_test PROPERTY CXX_STANDARD 17)
    target_link_libraries(cppcmd_test cppcmd)
    target_include_directories(cppcmd_test PRIVATE ${DIR_CPPCMD_INCLUDE})
    target_include_directories(cppcmd_test PRIVATE ${DIR_CPPCMD_SOURCES})
    target_include_directories(cppcmd_test PRIVATE ${DIR_EXAMPLE_SOURCES})
    target_include_directories(cppcmd_test PRIVATE ${DIR_EXAMPLE_INCLUDE})
    add_test(NAME cppcmd_test COMMAND cppcmd_test)
endif ()

message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} cppcmd cmake file done ")