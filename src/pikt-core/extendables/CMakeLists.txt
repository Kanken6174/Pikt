cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl")

set(CMAKE_CXX_STANDARD 17)

set(local_src
    imgProcessor.hpp
    plugin.hpp
    plugin.cpp
    pluginManager.hpp
    pluginManager.cpp
)

add_library(extendables ${local_src})

set_target_properties(extendables PROPERTIES LINKER_LANGUAGE CXX)