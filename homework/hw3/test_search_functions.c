// test_search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//Abhi Mohnani
//amohnan1



#include <stdio.h>
#include <assert.h>
#include "search_functions.h"


/* 
 * Declarations for tester functions whose definitions appear below.
 * (You will need to fill in the function definition details, at the
 * end of this file, and add comments to each one.) 
 * Additionally, for each helper function you elect to add to the 
 * provided search_functions.h, you will need to supply a corresponding
 * tester function in this file.  Add a declaration for it here, its
 * definition below, and a call to it where indicated in main.
 */
void test_file_eq();      // This one is already fully defined below.
void test_populate_grid();
void test_find_right();
void test_find_left();
void test_find_down();
void test_find_up();
void test_find_all();


/*
 * Main method which calls all test functions.
 */
int main() {
  printf("Testing file_eq...\n");
  test_file_eq();
  printf("Passed file_eq test.\n\n");

  printf("Running search_functions tests...\n");
  test_populate_grid();
  test_find_right();
  test_find_left();
  test_find_down();
  test_find_up();
  test_find_all();

  /* You may add calls to additional test functions here. */

  printf("Passed search_functions tests!!!\n");
}



/*
 * Test file_eq on same file, files with same contents, files with
 * different contents and a file that doesn't exist.
 * Relies on files test1.txt, test2.txt, test3.txt being present.
 */
void test_file_eq() {
  FILE* fptr = fopen("test1.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  fptr = fopen("test2.txt", "w");
  fprintf(fptr, "this\nis\na different test\n");
  fclose(fptr);

  fptr = fopen("test3.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  assert( file_eq("test1.txt", "test1.txt"));
  assert( file_eq("test2.txt", "test2.txt"));
  assert(!file_eq("test2.txt", "test1.txt"));
  assert(!file_eq("test1.txt", "test2.txt"));
  assert( file_eq("test3.txt", "test3.txt"));
  assert( file_eq("test1.txt", "test3.txt"));
  assert( file_eq("test3.txt", "test1.txt"));
  assert(!file_eq("test2.txt", "test3.txt"));
  assert(!file_eq("test3.txt", "test2.txt"));
  assert(!file_eq("", ""));  // can't open file
}


//tests the function_populate grid
//passes a nonexistent file, a file with an invalid grid, and a valid grid
//also checks if the function returns the correct dimension
void test_populate_grid(){
  char grid[MAX_SIZE][MAX_SIZE];
  char fakefilename[20] = "doesntexist.txt";
  char  badformatfile[20] = "test1.txt";
  char goodfile[20] = "goodformat.txt";
  int test1 = populate_grid(grid, fakefilename);
  assert(test1 == -1);  //replace this stub
  test1 = populate_grid(grid, badformatfile);
  assert (test1 == -2);
  test1 = populate_grid(grid, goodfile);
  assert (test1 == 4);

}

//tests the function find_right
//creates a grid with multiple occurences of word, and sends to function
//checks with a word that isn't in the grid
void test_find_right(){
  char grid[MAX_SIZE][MAX_SIZE] = {"atip", "blah", "tipa", "ftip"};
  int counter = find_right(grid, 4, "tip", stdout);
  assert(counter == 3);  
  counter = find_right(grid, 4, "abcd", stdout);
  assert (counter == 0);
}

//tests the function find_left
//creates a grid with multiple occurences of word, and sends to function
//checks with a word that isn't in the grid
void test_find_left(){
  char grid[MAX_SIZE][MAX_SIZE] = {"atip", "blah", "tipa", "ftip"};
  int counter = find_left(grid, 4, "pit", stdout);
  assert(counter == 3);
  counter = find_left(grid, 4, "nahy", stdout);
  assert(counter == 0);  
}

//tests the function find_down
//creates a grid with multiple occurences of word, and sends to function
//checks with a word that isn't in the grid
void test_find_down(){
  char grid[MAX_SIZE][MAX_SIZE] = {"abcd", "baba", "cbca", "dcef"};
  int counter = find_down(grid, 4, "abc", stdout);
  assert(counter == 2);  
  counter = find_down(grid, 4, "blah", stdout);
  assert(counter == 0);
}

//tests the function find_up
//creates a grid with multiple occurences of word, and sends to function
//checks with a word that isn't in the grid
void test_find_up(){
  char grid[MAX_SIZE][MAX_SIZE] = {"abcd", "baba", "cbca", "dcef"};
  int counter = find_up(grid, 4, "cba", stdout);
  assert(counter == 2);  
  counter = find_up(grid, 4, "blah", stdout);
  assert(counter == 0);
}

//tests the function find_all
//Uses a larger grid with many intertwined occurences of word
//Then checks with a word that isn't in the grid
void test_find_all(){
  char grid[MAX_SIZE][MAX_SIZE] ={"dogbf", "oaoce", "goddg", "efoho", "bagod"};
  int counter = find_all(grid, 5, "dog", stdout);
  assert(counter == 7);
  counter = find_all(grid, 5, "blahb", stdout);
  assert(counter == 0);
}

