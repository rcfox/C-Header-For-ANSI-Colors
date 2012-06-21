all: test.c ansi_color.h
	gcc -Wall -Wextra test.c -o test

test: all
	./test

clean:
	rm -f test
