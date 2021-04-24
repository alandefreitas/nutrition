#######################################################
### Project information                             ###
#######################################################
# Project information
cmake_minimum_required(VERSION 3.17)
project(modern-nutrition
        VERSION 0.0.0
        DESCRIPTION "Modern Nutrition"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(MODERN_NUTRITION_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# CMake dependencies for installer
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# To avoid csvlibs gcov error
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# To find or download packages
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
message("CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}")
option(CPM_USE_LOCAL_PACKAGES "Try `find_package` before downloading dependencies" ON)
include(cmake/CPM.cmake)

#######################################################
### Dependencies                                    ###
#######################################################
CPMAddPackage(
        NAME matplot
        GITHUB_REPOSITORY alandefreitas/matplotplusplus
        GIT_TAG origin/master # or whatever tag you want
)

CPMAddPackage(
        NAME cereal
        VERSION 1.3.0
        GITHUB_REPOSITORY USCiLab/cereal
        DOWNLOAD_ONLY TRUE
)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_library(cereal INTERFACE)
target_include_directories(cereal INTERFACE ${cereal_SRC_DIR}/include)

# CSV: https://github.com/vincentlaucsb/csv-parser
CPMAddPackage(NAME csv-parser GITHUB_REPOSITORY vincentlaucsb/csv-parser GIT_TAG 65e4fa544c0dccc9db7a6eb7f5f360688d3ae457 VERSION 1.1.1)
if (csv-parser_ADDED)
    if (TARGET csv AND NOT TARGET csv::csv)
        add_library(csv::csv ALIAS csv)
    endif()
else ()
    message(FATAL_ERROR "Cannot find or download csv-parser")
endif ()

#######################################################
### Options                                         ###
#######################################################
# Check if this is a master project or a subdirectory of another project
if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(MASTER_PROJECT ON)
else ()
    set(MASTER_PROJECT OFF)
endif ()
set(MATPLOT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Check if we are in debug mode
if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(DEBUG_MODE ON)
    set(NOT_DEBUG_MODE OFF)
else()
    set(DEBUG_MODE OFF)
    set(NOT_DEBUG_MODE ON)
endif()

# What to build
option(BUILD_STANDALONE "Build standalone command line application" ${MASTER_PROJECT})
option(BUILD_EXAMPLES "Build examples" ${MASTER_PROJECT})
option(BUILD_TESTS "Build tests" ${MASTER_PROJECT})
option(BUILD_INSTALLER "Build installer target" ${MASTER_PROJECT})
option(BUILD_PACKAGE "Build package" ${MASTER_PROJECT})

# How to build
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_WITH_PEDANTIC_WARNINGS "Build with pedantic warnings." ${DEBUG_MODE})
option(BUILD_WITH_UTF8 "Accept utf-8 in MSVC by default." ON)

if (BUILD_WITH_PEDANTIC_WARNINGS)
    if (MSVC)
        add_compile_options(/W4 /WX)
    else()
        add_compile_options(-Wall -Wextra -pedantic -Werror)
    endif()
endif()

if (BUILD_WITH_UTF8 AND MSVC)
    set(CMAKE_CXX_FLAGS "/utf-8")
endif ()

#######################################################
### Library                                         ###
#######################################################
add_subdirectory(source)

#######################################################
### Tests                                           ###
#######################################################
#if (BUILD_TESTS)
    add_subdirectory(test)
#endif ()

#######################################################
### Examples                                        ###
#######################################################
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()

#######################################################
### Examples                                        ###
#######################################################
if (BUILD_STANDALONE)
    add_subdirectory(standalone)
endif ()

#######################################################
### Installer                                       ###
#######################################################