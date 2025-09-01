#!/bin/bash

# Simple Rust-CMake Integration Build Script

set -e  # Exit on error

echo "=== Rust-CMake Integration Build Started ==="

# Navigate to project root directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
cd "$PROJECT_ROOT"

echo "Project Directory: $PROJECT_ROOT"

# Create build directory
if [ -d "build" ]; then
    echo "Cleaning existing build directory..."
    rm -rf build
fi

mkdir build
cd build

echo "Running CMake configuration..."
# Ensure CMAKE can find rustc in /usr/local/bin
env PATH="/usr/local/bin:$PATH" cmake ..

echo "Building project..."
make -j$(nproc)

echo ""
echo "=== Build Complete! ==="
echo ""
echo "Run the executable:"
echo "  cd $PROJECT_ROOT/build"
echo "  ./math_calculator"
echo ""
echo "Or directly:"
echo "  $PROJECT_ROOT/build/math_calculator"
echo ""

# Auto-run if requested
if [ "$1" = "--run" ]; then
    echo "=== Auto-running ==="
    ./math_calculator
fi
