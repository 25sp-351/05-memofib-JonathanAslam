CC = clang
CFLAGS = -g -Wall
RM = rm -f

main: main.c memoize.c 
	$(CC) $(CFLAGS) -o main main.c memoize.c 

test_memo: test/test_fib_memo.c memoize.c 
	$(CC) $(CFLAGS) -o test_memo test/test_fib_memo.c memoize.c

clean:
	$(RM) main

test: test_memo
	./test_memo > test_output.txt
	cat test_output.txt