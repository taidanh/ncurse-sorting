CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: sorting

sorting: sorting.o bubble.o shell.o quick.o stack.o heap.o set.o tools.o curse_lib.o
	$(CC) $(CFLAGS) -o sorting sorting.o bubble.o shell.o quick.o stack.o heap.o set.o tools.o curse_lib.o -lncurses

sorting.o: sorting.c
	$(CC) $(CFLAGS) -g -c sorting.c

curse_lib.o: curse_lib.c
	clang -c curse_lib.c

bubble.o: bubble.c
	$(CC) $(CFLAGS) -g -c bubble.c

shell.o: shell.c
	$(CC) $(CFLAGS) -g -c shell.c
	
quick.o: quick.c
	$(CC) $(CFLAGS) -g -c quick.c

stack.o: stack.c
	$(CC) $(CFLAGS) -g -c stack.c

heap.o: heap.c
	$(CC) $(CFLAGS) -g -c heap.c

set.o: set.c
	$(CC) $(CFLAGS) -g -c set.c

tools.o: tools.c
	$(CC) $(CFLAGS) -g -c tools.c

clean:
	rm -f *.o sorting

format:
	clang-format -i -style=file *.c
