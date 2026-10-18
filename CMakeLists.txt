cmake_minimum_required(VERSION 3.10)

project(ZiMatLib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(zimat INTERFACE)


target_include_directories(zimat INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_subdirectory(examples)