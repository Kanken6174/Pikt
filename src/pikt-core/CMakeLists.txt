cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl -rdynamic")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl -rdynamic")

project(pikt)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../../bin")

set(local_source_files
    main.cpp
    cmdParser.cpp
    cmdParser.hpp
)

find_package(OpenMP)

add_subdirectory(extendables)
add_subdirectory(dependencies)



add_executable(pikt ${local_source_files})

target_link_libraries(pikt extendables dependencies)

if (OpenMP_CXX_FOUND)
    target_link_libraries(pikt OpenMP::OpenMP_CXX)
endif()

MESSAGE(STATUS "CMAKE FLAGS : ${LINK_OPTIONS}")