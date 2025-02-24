#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../memoize.h"
#include "../fib.h"

function_ptr fibonacci_provider;


//one long test case function which checks given input and output with the memoize() function and with the search_cache function. 
int test_given_input(int input, long long int expected_value) {
    printf("--------------------\n");
    printf("Running test_given_input(%d)...\n", input);
    long long int result = (*fibonacci_provider)(input);
    printf("Running: memoize(%d)\n", input);
    printf("Expected Output: Fibonacci(%d) = %lld\n", input, expected_value);
    printf("Actual Output: Fibonacci(%d) = %lld\n", input, result);
    if (result == expected_value)
        printf("memoize(%d) passed.\n", input);
    if (result != expected_value)
        printf("memoize(%d) failed.\n", input);
    // now check from cache
    printf("Checking cache for input and expected output ...\n");
    printf("Running search_cache(%d)\n", input);
    long long int cache_result = search_cache(input);
    printf("Expected Output: %lld\n", expected_value);
    printf("Actual Output: %lld\n", cache_result);
    if (cache_result == expected_value)
        printf("search_cache(%d) passed.\n", input);
    if (cache_result != expected_value)
        printf("search_cache(%d) failed.\n", input);
    return 0;
}


int main() {
    fibonacci_provider = intialize_memo();

    test_given_input(10, 55);
    test_given_input(20, 6765);
    test_given_input(30, 832040);
    test_given_input(40, 102334155);
    test_given_input(50, 12586269025);
    test_given_input(60, 1548008755920);
    test_given_input(70, 190392490709135);
    test_given_input(80, 23416728348467685);
    test_given_input(90, 2880067194370816120);
    test_given_input(92, 7540113804746346429);
// 55
// 6765
// 832040
// 102334155
// 12586269025
// 1548008755920
// 190392490709135
// 23416728348467685 -- 80
// 2880067194370816120 -- 90
// 7540113804746346429 -- 92
}
