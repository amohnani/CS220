// Abhi Mohnani
// JHED: amohnan1

#include <stdio.h>

int main(void){
  printf("Please enter an arithmetic expression using * and / only:\n");
  float next_number;
  char operator;
  float answer;
  int end_of_file = 2;
  if (scanf("%f", &answer) != 1){
    printf("The expression must start with a number \n");
      return 1;
  }
  while (end_of_file == 2){
    end_of_file = scanf(" %c %f", &operator, &next_number);
      if (end_of_file != 2){
	 printf("malformed expression \n");
	 return 1;
      }
    if (operator ==  '*'){
      answer = answer * next_number;
    }else if (operator == '/') {
      if (next_number == 0){
	printf("division by 0\n");
	return 2;
      }
      answer = answer / next_number;
    }else{
      printf("malformed expression\n");
      return 1;
    }
  }
  printf("%f \n", answer);
  return 0;
}
