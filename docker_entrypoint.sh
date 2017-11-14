#!/bin/bash

if [ "$1" = 'cmake' ]; then
    cmake . -GNinja
elif [ "$1" = 'make' ]; then
    ninja openclonk
elif [ "$1" = 'run' ]; then
    /opt/code/openclonk
else
  echo "unknown command: $1. Possible commands: cmake, makei, run"
fi
