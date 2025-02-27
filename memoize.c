#include "memoize.h"

#include <stdio.h>

#include "fib.h"

#define MAX 93

long long int memo[MAX];

function_ptr original_provider;  // point to fib
function_ptr fib_provider;       // point to cache

long long int memoize(int number) {
    if (number > MAX)
        return (*original_provider)(number);
    if (memo[number] == -1)
        memo[number] = (*original_provider)(number);
    return memo[number];
}

function_ptr intialize_memo(function_ptr op) {
    for (int ix = 0; ix <= MAX; ix++)
        memo[ix] = -1;
    original_provider   = op;
    return fib_provider = memoize;
}

long long int search_cache(int number) {
    if (number > MAX || number < 0)
        return -1;
    return memo[number];
}
