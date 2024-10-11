CC=gcc
CFLAGS=-lncurses -Wall -Wextra -pedantic -std=c17

all: todolist

todolist: main.o todolist.o file_utils.o
	$(CC) $(CFLAGS) -o todolist main.o todolist.o file_utils.o

main.o: main.c todolist.h file_utils.h
	$(CC) $(CFLAGS) -c main.c

todolist.o: todolist.c todolist.h
	$(CC) $(CFLAGS) -c todolist.c

file_utils.o: file_utils.c file_utils.h
	$(CC) $(CFLAGS) -c file_utils.c

clean: 
	rm -f *.o todolist