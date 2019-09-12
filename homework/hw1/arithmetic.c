// Abhi Mohnani
// JHED: amohnan1

#include <stdio.h>

int main(void){
  printf("Please enter an arithmetic expression using * and / only:\n");
  float next_number;
  char operator;
  float answer;
  int end_of_file = 2;
  if (scanf("%f", &answer) != 1){ //checks if first input is an integer
    printf("malformed expression \n");
      return 1;
  }
  while (end_of_file == 2){ //repeats while user is entering valid inputs
    end_of_file = scanf(" %c %f", &operator, &next_number); 
    if (end_of_file == EOF){ //if user presses ctrl-D
      break;
    }
    if (end_of_file != 2){ //checks if user inputs an invalid expression
	 printf("malformed expression \n");
	 return 1;
      }
    if (operator ==  '*'){ //case of multiplication
      answer = answer * next_number;
    }else if (operator == '/') {
      if (next_number == 0){ //checks for dividing by 0
	printf("division by 0\n");
	return 2;
      }
      answer = answer / next_number;
    }else{
      printf("malformed expression\n");
      return 1;
    }
  }
  printf("%f \n", answer); //outputs final result
  return 0;
}
