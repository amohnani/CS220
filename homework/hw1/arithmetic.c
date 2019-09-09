// Abhi Mohnani
// JHED: amohnan1

#include <stdio.h>

int main(void){
  printf("Please enter an arithmetic expression using * and / only:\n");
  float number, next_number;
  char operator;
  float answer;
  int end_of_file = 1;
  end_of_file = scanf("%f", number);
  while (end_of_file == 1){
    end_of_file = scanf("%c", operator);
    if (operator != '*' || operator != '/'){
      printf("malformed expression\n");
      return 1;
    }
  }
  return 0;
}
