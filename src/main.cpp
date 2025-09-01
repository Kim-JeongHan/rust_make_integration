#include <iostream>
#include "rust_math_interface.h"

int main() {
    std::cout << "=== Rust-CMake Integration Example ===\n\n";

    // Fibonacci sequence test
    std::cout << "Fibonacci Sequence (first 15 numbers):\n";
    std::cout << "   ";
    for (int i = 0; i < 15; ++i) {
        int fib = fibonacci(i);
        std::cout << fib;
        if (i < 14) std::cout << ", ";
    }
    std::cout << "\n\n";

    // Individual Fibonacci calculations
    std::cout << "Individual Fibonacci calculations:\n";
    int test_values[] = {5, 10, 15, 20};
    for (int n : test_values) {
        int result = fibonacci(n);
        std::cout << "   fibonacci(" << n << ") = " << result << "\n";
    }

    std::cout << "\n=== Test Completed! ===\n";
    return 0;
}
