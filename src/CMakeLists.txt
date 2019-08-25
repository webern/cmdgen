# cppcmd by (c) Matthew James Briggs
cmake_minimum_required(VERSION 3.0)
project(cppcmd VERSION 0.0.1)
set(DEBUG_INFO "cppcmd/src/CMakeLists.txt")
message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} cppcmd cmake file starting")

option(XJEN_ENABLE_TESTS "Enable tests" OFF)
option(XJEN_ENABLE_CMD "When ON, builds the cppcmd executable, when off only the cppcmd library is built" ON)

# Directories

set(DIR_CPPCMD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/private")
set(DIR_CPPCMD_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/lib/include")
set(DIR_EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/example")
set(DIR_EXAMPLE_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}")
set(DIR_XJEN_TEST "${CMAKE_CURRENT_SOURCE_DIR}/test")

add_library(cppcmd "${DIR_CPPCMD_SOURCES}/Hello.cpp")
target_include_directories(cppcmd PUBLIC "${DIR_CPPCMD_INCLUDE}")
target_include_directories(cppcmd PRIVATE "${DIR_CPPCMD_SOURCES}")
set_property(TARGET cppcmd PROPERTY CXX_STANDARD 17)

if (${XJEN_ENABLE_TESTS})
    message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} compiling cmd")
	add_executable(cppcmd "${DIR_EXAMPLE_SOURCES}/main.cpp")
	set_property(TARGET cppcmd PROPERTY CXX_STANDARD 17)
endif()

if (${XJEN_ENABLE_TESTS})
    message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} compiling tests")
    enable_testing()
    file(GLOB_RECURSE XCOREJEN_TEST_SOURCES "${DIR_XJEN_TEST}/*.cpp")
    message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} XCOREJEN_TEST_SOURCES    = ${XCOREJEN_TEST_SOURCES}")
    add_executable(cppcmd_test ${XCOREJEN_TEST_SOURCES})
    set_property(TARGET cppcmd_test PROPERTY CXX_STANDARD 17)
    target_link_libraries(cppcmd_test cppcmd)
    target_include_directories(cppcmd_test PRIVATE ${DIR_CPPCMD_INCLUDE})
    target_include_directories(cppcmd_test PRIVATE ${DIR_CPPCMD_SOURCES})
    add_test(NAME cppcmd_test COMMAND cppcmd_test)
endif()

message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} cppcmd cmake file done")