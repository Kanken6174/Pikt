cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl")

set(CMAKE_CXX_STANDARD 17)

set(local_src
    cimg.h
)

add_library(dependencies ${local_src})

set_target_properties(dependencies PROPERTIES LINKER_LANGUAGE CXX)