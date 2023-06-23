#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho;
  int par;
  int impar;
  printf("Digita o tamanho ai\n");
  scanf("%d", &tamanho);
  int *recebido;
  recebido = (int *)malloc(tamanho * sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &recebido[i]);
    system("clear");
  }
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", recebido[i]);
  }
  printf("\n");
  for (int i = 0; i < tamanho; i++) {
    if (recebido[i] % 2 == 0) {
      par++;
    } else {
      impar++;
    }
  }
  printf("pares : %d  impares : %d", par, impar);
  free(recebido);
}