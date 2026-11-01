cmake_minimum_required(VERSION 3.10)

set(ZIMAT_VERSION_HEADER "${CMAKE_CURRENT_LIST_DIR}/include/zimat/zimat.hpp")
foreach(component MAJOR MINOR PATCH)
    file(STRINGS "${ZIMAT_VERSION_HEADER}" ZIMAT_VERSION_${component}_LINE
        REGEX "^#define ZIMAT_VERSION_${component} [0-9]+$")
    if(NOT ZIMAT_VERSION_${component}_LINE)
        message(FATAL_ERROR "Missing ZIMAT_VERSION_${component} in ${ZIMAT_VERSION_HEADER}")
    endif()
    string(REGEX MATCH "[0-9]+$" ZIMAT_VERSION_${component}
        "${ZIMAT_VERSION_${component}_LINE}")
endforeach()

project(ZiMatLib VERSION "${ZIMAT_VERSION_MAJOR}.${ZIMAT_VERSION_MINOR}.${ZIMAT_VERSION_PATCH}" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(zimat INTERFACE)


target_include_directories(zimat INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_subdirectory(examples)
