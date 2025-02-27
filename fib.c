#include "fib.h"

#include "memoize.h"  // want to use the extern function_ptr

long long int fib(int n) {
    if (n <= 1)
        return n;
    return (*fib_provider)(n - 1) + (*fib_provider)(n - 2);
}
