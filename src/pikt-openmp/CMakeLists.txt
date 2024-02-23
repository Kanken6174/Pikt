PROJECT(pikt_openmp)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl")

set(local_src
    _factory.cpp
)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../bin/plugins/)

find_package(OpenMP)

ADD_LIBRARY(pikt_openmp SHARED ${local_src})

target_link_libraries(pikt_openmp PUBLIC OpenMP::OpenMP_CXX)