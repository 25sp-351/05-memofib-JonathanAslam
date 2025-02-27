#ifndef MEMOIZE_H
#define MEMOIZE_H

typedef long long int (*function_ptr)(int);  // good

extern function_ptr fib_provider;

long long int memoize(int number);  // memoize function
function_ptr intialize_memo(function_ptr op);  // initialize to -1 and assign the ptr functions

//// for test file only
long long int search_cache(int number);

#endif  // MEMOIZE_H
