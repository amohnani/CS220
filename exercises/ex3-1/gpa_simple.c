//Ex3-1: gpa_simple.c

/* The purpose of this program is to compute GPAs for simple letter
   grades - no +/-, only A, B, C, D, F. Credits may be rational
   numbers.  Also determine and display notices for Dean's List
   (>=3.5) and Academic Probation (< 2.0).

SAMPLE RUN:

Welcome to the GPA calculator!
Enter grade and credits for each course below (ctrl-d to end):
course 1: A 4.0
course 2: b 2.7
course 3: B 3.5
course 4: c 3.0
course 5: f 1
course 6: a 3
course 7: 
Your GPA is 3.06

-----
PSEUDOCODE:

point_sum gets 0
credit_sum gets 0
points gets 0
gpa gets 0

display “Welcome to GPA calculator!”
prompt for list of grade/credits pairs

count gets 1
display "course #", count

repeat while there is a grade and credits to read
    convert grade to points
    add points * credits to point_sum
    add credits to credit_sum
    add 1 to count
    display "course #", count

if credit_sum > 0
   set gpa to point_sum / credit_sum
   display "GPA is ", gpa
   if gpa >= 3.5
      display "Dean's List"
   otherwise if gpa <= 2.0
      display "Uh-oh, Academic Probation..."
otherwise
   display "No credits attempted; no GPA to report"

*/


#include <stdio.h>

int main() {

  //TO DO: add your code here so that your program
  printf("Welcome to the GPA calculator!");
  printf("Enter grade and credits for each course below (ctrl-d to end)");
  float credits;
  char grade;
  int course_num = 0;
  float total_credits = 0;
  float grade_point = 0;
  while (!EOF){
    course_num++;
    printf("course %d: ", course_num);
    scanf("%c %f", &grade, &credits);
    if (grade == 'A' || grade == 'a'){
      grade_point += 4.0 * credits;
    } else if(grade == 'B' || grade == 'b') {
      grade+= 3.0 * credits;
    } else if (grade == 'C' || grade == 'c'){
      grade += 2.0 * credits;
    } else if (grade == 'D' || grade == 'd'){
      grade += 1.0 * credits;
    } 
    total_credits += credits;
  }  
  printf("Your GPA is %f", (grade_point/total_credits));
 return 0;
}
