// search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//Abhi Mohnani
//amohnan1


#include <stdio.h>
#include "search_functions.h"
#include <string.h>


/* 
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the actual grid dimension. 
 * If filename_to_read_from can't be opened, this function returns -1.
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(char grid[][MAX_SIZE], char filename_to_read_from[]){
  FILE *input = fopen(filename_to_read_from, "r");
  if (input == NULL){ //checks if file exists
    printf("Grid file failed to open.\n");
    return -1;
  }
  int line = 0;
  int lengths[10] = {0};
  char temp = ' ';
  while(fscanf(input,"%c", &temp) ==  1){
    if ((temp > 64 && temp < 91) || (temp > 96 && temp < 123)){
      if (temp < 91){
	temp += 32;
      }
      grid[line][lengths[line]] = temp;
      lengths[line]++;
      if (lengths[line] > 10){ //checks for grid that is too wide
	printf("Invalid grid.\n");
	fclose(input);
	return -2;
      }
    }
    if (temp == '\n'){
      line++; //checks for grid that is too large
      if (line > 10){
	printf("Invalid grid.\n");
	fclose(input);
	return -2;
      }
    }
  }
  for (int i = 0; i < line; i++){
    if (lengths[i] != line){ //checks for unequal number of letters
      printf("Invalid grid.\n");
      fclose(input);
      return -2;
    }
  }
  fclose(input);
  return line; //returns number of rows

}

/* 
 * Finds all occurences of the word going right
   The function checks for the first letter of the word at every position
   Then, the function checks if the word continues in that direction
 */
int find_right(char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  int word_len = strlen(word);
  int counter = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n-word_len+1; j++){
      int found_word = 1;
      if (grid[i][j] == word[0]){
	for (int k = 1; k < word_len; k++){
	  if (grid[i][j+k] != word[k]){
	    found_word = 0;
	    break;
	  }
	}
	if (found_word == 1){
	  fprintf(write_to, "%s %d %d R\n", word, i, j);
	  counter++;
	}
      }
    }
  }
  return counter; 

}


/* 
 * Finds all occurences of the word going left
   The function checks for the first letter of the word at every position
   Then, the function checks if the word continues in that direction 
 */
int find_left (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  int word_len = strlen(word);
  int counter = 0;
  for (int i = 0; i < n; i++){
    for (int j = word_len-1; j < n; j++){
      int found_word = 1;
      if (grid[i][j] == word[0]){
	for (int k = 1; k < word_len; k++){
	  if (grid[i][j-k] != word[k]){
	    found_word = 0;
	    break;
	  }
	}
	if (found_word == 1){
	  fprintf(write_to, "%s %d %d L\n", word, i, j);
	  counter++;
	}
      }
    }
  }
  return counter; // replace this stub
}


/* 
 * Finds all occurences of the word going down
   The function checks for the first letter of the word at every position
   Then, the function checks if the word continues in that direction
 */
int find_down (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  int word_len = strlen(word);
  int counter = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n-word_len+1; j++){
      int found_word = 1;
      if (grid[j][i] == word[0]){
	for (int k = 1; k < word_len; k++){
	  if (grid[j+k][i] != word[k]){
	    found_word = 0;
	    break;
	  }
	}
	if (found_word == 1){
	  fprintf(write_to, "%s %d %d D\n", word, j, i);
	  counter++;
	}
      }
    }
  }
  return counter; // replace this stub

}


/* 
 * Finds all occurences of the word going up
   The function checks for the first letter of the word at every position
   Then, the function checks if the word continues in that direction
 */
int find_up   (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
   int word_len = strlen(word);
  int counter = 0;
  for (int i = 0; i < n; i++){
    for (int j = word_len-1; j < n; j++){
      int found_word = 1;
      if (grid[j][i] == word[0]){
	for (int k = 1; k < word_len; k++){
	  if (grid[j-k][i] != word[k]){
	    found_word = 0;
	    break;
	  }
	}
	if (found_word == 1){
	  fprintf(write_to, "%s %d %d U\n", word, j, i);
	  counter++;
	}
      }
    }
  }
  return counter; 
}


/* 
 * Calls all helper functions, and finds all occurences of the word
 If none are found, the function outputs not found
 */
int find_all  (char grid[][MAX_SIZE], int n, char word[], FILE *write_to) {
  int total = 0;
  total += find_right(grid, n, word, write_to); 
  total += find_left(grid, n, word, write_to);
  total += find_down(grid, n, word, write_to);
  total += find_up(grid, n, word, write_to);
  if (total == 0){
    fprintf(write_to, "%s - Not Found\n", word);
  }
  return total; // replace this stub

} 


/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided 
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]) {
  FILE* lhs = fopen(lhs_name, "r");
  FILE* rhs = fopen(rhs_name, "r");

  // don't compare if we can't open the files
  if (lhs == NULL || rhs == NULL) return 0;

  int match = 1;
  // read until both of the files are done or there is a mismatch
  while (!feof(lhs) || !feof(rhs)) {
	if (feof(lhs) ||                      // lhs done first
		feof(rhs) ||                  // rhs done first
		(fgetc(lhs) != fgetc(rhs))) { // chars don't match
	  match = 0;
	  break;
	}
  }
  fclose(lhs);
  fclose(rhs);
  return match;
}

