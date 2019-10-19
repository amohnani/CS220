#Abhi Mohnani
#amohnan1
#Makefile

CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

# Links together files needed to create executable
digraphAnalyzer: digraphAnalyzer.o digraph.o
	$(CC) -o digraphAnalyzer digraphAnalyzer.o digraph.o

# Compiles digraphAnalyzer.c to create digraphAnalyzer.o
digraphAnalyzer.o: digraphAnalyzer.cpp digraph.h
	$(CC) $(CFLAGS) -c digraphAnalyzer.cpp

#Compiles digraph.o
digraph.o: digraph.cpp digraph.h
	$(CC) $(CFLAGS) -c digraph.cpp

# Removes all object files,
# so we can start fresh
clean:
	rm -f *.o
