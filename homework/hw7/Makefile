#Abhi Mohnani
#amohnan1
#Makefile

CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

# Links together files needed to create executable
cTreeTest: CTreeTest.o CTree.o
	$(CC) -o cTreeTest CTreeTest.o CTree.o

# Compiles cTreeTest.o
CTreeTest.o: CTreeTest.cpp CTree.h
	$(CC) $(CFLAGS) -c CTreeTest.cpp

#Compiles CTree.o
CTree.o: CTree.cpp CTree.h
	$(CC) $(CFLAGS) -c CTree.cpp

# Links together files needed to create executable
tTreeTest: TTreeTest.o Tree.o
	$(CC) -o tTreeTest TTreeTest.o Tree.o

# Compiles TTreeTest.o
TTreeTest.o: TTreeTest.cpp Tree.h
	$(CC) $(CFLAGS) -c TTreeTest.cpp

#Compiles CTree.o
CTree.o: Tree.inc Tree.h
	$(CC) $(CFLAGS) -c Tree.inc


# Removes all object files,
# so we can start fresh
clean:
	rm -f *.o
