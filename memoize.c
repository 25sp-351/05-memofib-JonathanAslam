#include "memoize.h"

#include <stdio.h>

#define MAX 92

long long int memo[MAX];

function_ptr original_provider;  // point to fib
function_ptr fib_provider;       // point to cache

long long int fib(int n) {
    if (n <= 1)
        return n;
    return (*fib_provider)(n - 1) + (*fib_provider)(n - 2);
}

long long int memoize(int number) {
    if (number > MAX)
        return (*original_provider)(number);
    if (memo[number] == -1)
        memo[number] = (*original_provider)(number);
    return memo[number];
}

function_ptr intialize_memo() {
    for (int ix = 0; ix <= MAX; ix++)
        memo[ix] = -1;
    original_provider   = fib;
    return fib_provider = memoize;
}


long long int search_cache(int number){
    if (memo[number] != -1) {
        return memo[number]; // if found
    }
    return -1; // if not found
}
