#!/bin/bash

bin="trebuchet"

# Remove build directory
if [ -d "build" ]; then
  rm -rf build
fi

# Remove binary
if [ -f $bin ]; then
  rm $bin
fi
