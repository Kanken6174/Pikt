PROJECT(pikt_basics)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl")

set(local_src
    _factory.cpp
    cimgLoader.hpp
    cimgSaver.hpp
)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../bin/plugins/)

link_directories(../pikt-core/extendables)

ADD_LIBRARY(pikt_basics SHARED ${local_src})

target_link_libraries(pikt_basics extendables)