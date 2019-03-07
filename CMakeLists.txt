cmake_minimum_required(VERSION 3.0)
project(chara)

set(CMAKE_CXX_STANDARD 14)
link_libraries(pthread)
add_definitions("-g")

aux_source_directory(src/core SOURCE_CORE)
aux_source_directory(src/protocol SOURCE_PROTOCOL)
aux_source_directory(src/utils SOURCE_UTILS)
include_directories(src)

add_executable(chara
        src/chara.cc
        ${SOURCE_CORE}
        ${SOURCE_PROTOCOL}
        ${SOURCE_UTILS})