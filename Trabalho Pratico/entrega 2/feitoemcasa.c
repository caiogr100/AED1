#include <stdio.h>
#include <stdbool.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
  // variável pra contar quantos estudantes não conseguiram um sanduiche
  int count = 0;

  int student[studentsSize];
  int sandwich[sandwichesSize];

  // loops  copiam os valores das variáveis para as cópias que fizemos(vamos usar elas como apoio)
  for (int i = 0; i < studentsSize; i++) {
      student[i] = students[i];
  }
  for (int i = 0; i < sandwichesSize; i++) {
      sandwich[i] = sandwiches[i];
  }

  while (studentsSize > 0 && count < studentsSize) {
    // verificando se o primeiro estudante da fila gosta do primeiro sanduiche
    if (student[0] == sandwich[0]) {
      // se sim tiramos os 2 da fila
      for (int j = 0; j < studentsSize - 1; j++) {
        student[j] = student[j + 1];//pulando pro proximo estudante
      }
      for (int j = 0; j < sandwichesSize - 1; j++) {
        sandwich[j] = sandwich[j + 1];// e pulando pro proximo sanduiche
      }
      
      count = 0;
      studentsSize--;
      sandwichesSize--;
    }
    else {
      // final da fila se nao gosta do sanduiche do topo
      int x = student[0];
      for (int j = 0; j < studentsSize - 1; j++) {
        student[j] = student[j + 1];
      }
      student[studentsSize - 1] = x;
      count++;
    }
  }
  // retorna o numero de estudantes
  return studentsSize;
}

int main() {
  int students[] = {1, 1, 0, 0};
  int sandwiches[] = {0, 1, 0, 1};
  int studentsSize = sizeof(students) / sizeof(students[0]);
  int sandwichesSize = sizeof(sandwiches) / sizeof(sandwiches[0]);

  int result = countStudents(students, studentsSize, sandwiches, sandwichesSize);
  if(result == 0){
    printf("Nao sobrou nenhum estudante sem lanche\n");
  }else{
     printf("%d estudante(s) sobrou(ram) sem lanche.\n", result);
  }
  return 0;
}
