#!/bin/bash
# run.sh - Script to build and run the project with Google Test support on Linux systems
set -e

echo "Installing dependencies..."
sudo apt-get update
sudo apt-get install -y g++ make libgtest-dev cmake

echo "Building Google Test (if needed)..."
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp *.a /usr/lib
cd -

echo "Building project..."
make

echo "Running main executable..."
if [ -f "./main" ]; then
    ./main
else
    echo "No main executable found. Please check your makefile."
fi

echo "Running tests (if available)..."
if [ -f "./test/hello_gtest" ]; then
    ./test/hello_gtest
else
    echo "No test executable found. Skipping tests."
fi