#!/bin/bash

echo "Building Mini Shell..."

make

if [ $? -eq 0 ]; then
    echo "Build successful."
    echo "Starting Mini Shell..."
    ./bin/my_shell
else
    echo "Build failed."
fi
