// word_search.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
// Abhi Mohnani
// amohnan1


#include <stdio.h>
#include "search_functions.h"


/*
 * This is the HW3 main function that performs a word search.
 */
int main(int argc, char* argv[]) {
  
  // Fill in your main code here!
  if (argc != 2){
    printf("Please enter a command line argument.");
    return 1;
  }
  char * filename = argv[1];
  char word_grid[MAX_SIZE][MAX_SIZE];
  int grid_status = populate_grid(word_grid, filename);
  if (grid_status != 0){
    return grid_status;
  }

  return 0;

}

