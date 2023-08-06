#include <stdio.h>
#include <stdbool.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {

  int count = 0;
  int student[studentsSize];
  int sandwich[sandwichesSize];

  
  for (int i = 0; i < studentsSize; i++) {
      student[i] = students[i];
  }
  for (int i = 0; i < sandwichesSize; i++) {
      sandwich[i] = sandwiches[i];
  }
    
  int n = studentsSize;
  int i = 0; 
  while (studentsSize > 0 && count < studentsSize) {
    if (student[0] == sandwich[0]) {
      for (int j = 0; j < studentsSize - 1; j++) {
        student[j] = student[j + 1];
      }
      for (int j = 0; j < sandwichesSize - 1; j++) {
        sandwich[j] = sandwich[j + 1];
      }
      count = 0;
      studentsSize--;
      sandwichesSize--;
    }
    else {
      int x = student[0];
      for (int j = 0; j < studentsSize - 1; j++) {
          student[j] = student[j + 1];
      }
      student[studentsSize - 1] = x;
      count++;
    }
  }
  return studentsSize;
}

int main(void) {
  printf("Hello World\n");
  return 0;
}