#!/bin/bash

cd pikt-core
rm ./CMakeCache*
cmake .
cmake --build . -j8
cd ..

cd pikt-basics
rm ./CMakeCache*
cmake .
cmake --build . -j8
cd ..

cd pikt-io
rm ./CMakeCache*
cmake .
cmake --build . -j8
cd ..

cd pikt-openmp
rm ./CMakeCache*
cmake .
cmake --build . -j8
cd ..