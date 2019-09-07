# cmdgen by (c) Matthew James Briggs
cmake_minimum_required(VERSION 3.0)
project(cmdgen LANGUAGES CXX VERSION 0.0.1)

# Variables
set(DEBUG_INFO "cmdgen/src/CMakeLists.txt")
set(CORE_LIBRARY_NAME cmdgen_core)
set(MAIN_PROGRAM_NAME cmdgen)
set(TEST_PROGRAM_NAME cmdgen_test)
message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} cmdgen cmake file starting")

# Options
option(CMDGEN_ENABLE_TESTS "Enable tests" OFF)

# Directories
set(DIR_CMDGEN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/private")
set(DIR_CMDGEN_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/lib/include")
set(DIR_MAIN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}")
set(DIR_MAIN_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}")
set(DIR_TEST "${CMAKE_CURRENT_SOURCE_DIR}/test")

# File Sets
file(GLOB_RECURSE FILES_CMDGEN_SOURCES ${DIR_CMDGEN_SOURCES}/*.cpp)
file(GLOB_RECURSE FILES_CMDGEN_HEADERS ${DIR_CMDGEN_INCLUDE}/*.h*)
file(GLOB_RECURSE FILES_MAIN_SOURCES ${DIR_MAIN_SOURCES}/*.cpp)
file(GLOB_RECURSE FILES_MAIN_HEADERS ${DIR_MAIN_INCLUDE}/*.h*)
file(GLOB_RECURSE FILES_CMDGEN_TEST_SOURCES ${DIR_TEST}/*.cpp)
file(GLOB_RECURSE FILES_CMDGEN_TEST_HEADERS ${DIR_TEST}/*.h*)

# Create core library
add_library(${CORE_LIBRARY_NAME} "${FILES_CMDGEN_SOURCES}")
target_include_directories(${CORE_LIBRARY_NAME} PUBLIC "${DIR_CMDGEN_INCLUDE}")
target_include_directories(${CORE_LIBRARY_NAME} PRIVATE "${DIR_CMDGEN_SOURCES}")
set_property(TARGET ${CORE_LIBRARY_NAME} PROPERTY CXX_STANDARD 17)
add_subdirectory(./lib/extern/ezxml)
target_link_libraries(${CORE_LIBRARY_NAME} ezxml)
target_include_directories(${CORE_LIBRARY_NAME} PRIVATE ./lib/extern/ezxml/src/include)
target_include_directories(${CORE_LIBRARY_NAME} PRIVATE ./lib/extern/ezxml/src/private)

# Create main program
add_executable(${MAIN_PROGRAM_NAME} "${FILES_MAIN_SOURCES}")
target_include_directories(${MAIN_PROGRAM_NAME} PRIVATE "${DIR_MAIN_INCLUDE}")
target_include_directories(${MAIN_PROGRAM_NAME} PRIVATE "${DIR_CMDGEN_INCLUDE}")
target_include_directories(${MAIN_PROGRAM_NAME} PRIVATE "${DIR_CMDGEN_SOURCES}")
target_include_directories(${MAIN_PROGRAM_NAME} PRIVATE ./lib/extern/ezxml/src/include)
target_link_libraries(${MAIN_PROGRAM_NAME} ${CORE_LIBRARY_NAME})
set_property(TARGET ${MAIN_PROGRAM_NAME} PROPERTY CXX_STANDARD 17)

if (${CMDGEN_ENABLE_TESTS})
    message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} compiling tests")
    enable_testing()
    file(GLOB_RECURSE TEST_SOURCES "${DIR_TEST}/*.cpp")
    add_executable(${TEST_PROGRAM_NAME} ${TEST_SOURCES})
    set_property(TARGET ${TEST_PROGRAM_NAME} PROPERTY CXX_STANDARD 17)
    target_link_libraries(${TEST_PROGRAM_NAME} ${CORE_LIBRARY_NAME})
    target_include_directories(${TEST_PROGRAM_NAME} PRIVATE ${DIR_CMDGEN_INCLUDE})
    target_include_directories(${TEST_PROGRAM_NAME} PRIVATE ${DIR_CMDGEN_SOURCES})
    target_include_directories(${TEST_PROGRAM_NAME} PRIVATE ${DIR_MAIN_SOURCES})
    target_include_directories(${TEST_PROGRAM_NAME} PRIVATE ${DIR_MAIN_INCLUDE})
    add_test(NAME ${TEST_PROGRAM_NAME} COMMAND ${TEST_PROGRAM_NAME})
endif ()

message(STATUS "${DEBUG_INFO} Line:${CMAKE_CURRENT_LIST_LINE} cmdgen cmake file done ")