PROJECT(pikt_gl)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl")
set(OpenGL_GL_PREFERENCE GLVND)

set(local_src
    _factory.cpp
)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../bin/plugins/)

find_package(OpenMP)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

ADD_LIBRARY(pikt_gl SHARED ${local_src})

target_link_libraries(pikt_gl PUBLIC OpenMP::OpenMP_CXX glfw ${GLEW_LIBRARIES} ${OPENGL_LIBRARY})