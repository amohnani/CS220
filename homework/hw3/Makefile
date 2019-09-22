# Sample Makefile

CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra

# Links together files needed to create executable
word_search: word_search.o search_functions.o
	$(CC) -o word_search search_functions.o word_search.o

#Links files together to create test target
test: test_search_functions.o search_functions.o
	$(CC) -o test search_functions.o test_search_functions.o
	./test

# Compiles mainFile.c to create mainFile.o
# Note that we list functions.h here as a file that
# main_file.c depends on, since main_file.c #includes it
search_functions.o: search_functions.c search_functions.h
	$(CC) $(CFLAGS) -c search_functions.c

#Compiles test_search_functions.o
test_search_functions.o: test_search_functions.c search_functions.h
	$(CC) $(CFLAGS) -c test_search_functions.c

# Compiles functions.c to create functions.o
# Note that we list functions.h here as a file that
# functions.c depends on, since functions.c #includes it
word_functions.o: word_search.c search_functions.h
	$(CC) $(CFLAGS) -c search_functions.c

# Removes all object files and the executable named main,
# so we can start fresh
clean:
	rm -f *.o main
