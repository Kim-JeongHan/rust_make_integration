cmake_minimum_required(VERSION 3.15)
project(rust_cmake_integration)

# C++ standard configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Corrosion using FetchContent
include(FetchContent)

FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.4.7
)
FetchContent_MakeAvailable(Corrosion)

# Import Rust crate using Corrosion
corrosion_import_crate(MANIFEST_PATH rust_math/Cargo.toml)

# Include directory configuration
include_directories(include)

# Create C++ executable
add_executable(math_calculator
  src/main.cpp
)

# Link with Rust library (Corrosion automatically handles everything)
target_link_libraries(math_calculator
  rust_math_lib  # Target automatically created by Corrosion
)

# Installation configuration
install(TARGETS math_calculator
  RUNTIME DESTINATION bin
)
