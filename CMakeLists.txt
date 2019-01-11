cmake_minimum_required(VERSION 3.0)
project(chara)

set(CMAKE_CXX_STANDARD 14)
link_libraries(pthread)
add_definitions("-g")

#aux_source_directory()

add_executable(chara chara.cc)