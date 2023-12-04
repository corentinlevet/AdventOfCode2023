#!/bin/bash

bin="trebuchet"

# Remove old build
if [ -d "build" ]; then
  rm -rf build
fi

# Create build directory
mkdir build

# Change directory and build
cd build
cmake ..

# Compile binary
make

# Move binary to root directory
mv $bin ../
