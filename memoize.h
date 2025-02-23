#ifndef MEMOIZE_H
#define MEMOIZE_H

long long int fib(int n);                    // good
typedef long long int (*function_ptr)(int);  // good

////

long long int memoize(int number);  // memoize function
function_ptr intialize_memo();  // initialize to -1 and assign the ptr functions


//// for test file only
long long int search_cache(int number);

#endif  // MEMOIZE_H
