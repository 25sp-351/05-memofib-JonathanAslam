#include <stdio.h>
#include <stdlib.h>

#include "fib.h"
#include "memoize.h"

#define MAX_INPUT_LENGTH 4

int main() {
    function_ptr fibonacci_provider = intialize_memo();

    char input[4];
    int converted_int = 0;
    printf("Enter an integer (n) to return value of Fibonacci(n): ");

    while (fgets(input, MAX_INPUT_LENGTH, stdin) != NULL) {
        sscanf(input, "%d", &converted_int);
        printf("Fibonacci(%d) = %lld\n", converted_int,
               (*fibonacci_provider)(converted_int));
        printf("Enter an integer (n) to return value of Fibonacci(n): ");
    }

    return 0;
}
