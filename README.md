# Rust-CMake Integration with Corrosion

A simple example demonstrating how to integrate Rust libraries into CMake-based C++ projects using **Corrosion**.

## Purpose

Modern systems (robotics, embedded, etc.) are primarily built with C/C++ and CMake. While Rust offers memory safety and concurrency benefits, integrating it with existing CMake projects traditionally requires:

- Manually registering Cargo-built `.a`/`.so` libraries in CMake
- Synchronizing build configurations between Cargo and CMake
- Managing complex cross-compilation scripts

**Corrosion** automates this integration process.

## How It Works

Corrosion automatically:
- Converts Rust crates into CMake targets
- Handles cross-compilation and multi-platform builds  
- Links Rust libraries directly with C++ executables
- Synchronizes Debug/Release build configurations

## Project Structure

```
├── CMakeLists.txt                # CMake configuration with Corrosion
├── include/rust_math_interface.h # C FFI header for Rust functions  
├── rust_math/                    # Rust crate
│   ├── Cargo.toml
│   └── src/lib.rs               # Fibonacci implementation
└── src/main.cpp                 # C++ main program
```

## Build & Run

```bash
mkdir build && cd build
cmake ..
make
./math_calculator
```

if you fail to build this package, you can use the script/build.sh

```bash
cdmodx +x script/build.sh && cd script
./build.sh --run
```


## Output

```
=== Rust-CMake Integration Example ===

Fibonacci Sequence (first 15 numbers):
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377

Individual Fibonacci calculations:
   fibonacci(5) = 5
   fibonacci(10) = 55
   fibonacci(15) = 610
   fibonacci(20) = 6765

=== Test Completed! ===
```

## Key Integration Points

1. **FetchContent**: Automatically downloads Corrosion (no manual installation)
2. **`corrosion_import_crate()`**: Converts Rust crate to CMake target
3. **`target_link_libraries()`**: Links Rust library with C++ executable
4. **Rust FFI**: `#[no_mangle]` + `extern "C"` provides C-compatible interface

This example shows how to easily integrate Rust's safety and performance into existing CMake projects.
