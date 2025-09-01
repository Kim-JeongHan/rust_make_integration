#ifndef RUST_MATH_INTERFACE_H
#define RUST_MATH_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Calculate the nth value of Fibonacci sequence
 * @param n Index (starting from 0)
 * @return nth Fibonacci number
 */
int fibonacci(int n);

#ifdef __cplusplus
}
#endif

#endif // RUST_MATH_INTERFACE_H
