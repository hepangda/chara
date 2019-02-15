cmake_minimum_required(VERSION 3.0)
project(chara)

set(CMAKE_CXX_STANDARD 14)
link_libraries(pthread)
add_definitions("-g")

aux_source_directory(src/ SOURCE_MAIN)

add_executable(chara
        ${SOURCE_MAIN}
        )