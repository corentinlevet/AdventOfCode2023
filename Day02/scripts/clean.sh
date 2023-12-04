#!/bin/bash

bin="cubeConundrum"

# Remove build directory
if [ -d "build" ]; then
  rm -rf build
fi

# Remove binary
if [ -f $bin ]; then
  rm $bin
fi
