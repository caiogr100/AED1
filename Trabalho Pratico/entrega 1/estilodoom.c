#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct body {
  int inicio;
  int fim;
};

int divideString(char* c, int inicio, int fim) {
  bool* minuscula = (bool*)calloc(26, sizeof(bool));
  bool* maiuscula = (bool*)calloc(26, sizeof(bool));

  // Marca as letras minúsculas e maiúsculas e salva elas na variável acima
  for (int i = inicio; i < fim; i++) {
    if (c[i] >= 'A' && c[i] <= 'Z') {
      maiuscula[c[i] - 'A'] = true;
    } else {
      minuscula[c[i] - 'a'] = true;
    }
  }

  // percorrer até encontrar um ponto de divisão da string
  for (int i = inicio; i < fim; i++) {
    if (c[i] >= 'A' && c[i] <= 'Z') {
      if (minuscula[c[i] - 'A'] == false) return i;
    } else {
      if (maiuscula[c[i] - 'a'] == false) return i; 
    }
  }

  // se não encontrar nenhum ponto de divisão, significa que a string já está correta
  return -1;
}

struct body encontrarSubstring(char* s, int inicio, int fim) {
  struct body res;
  res.inicio = inicio;
  res.fim = fim;

  // Decidir o ponto de divisão da string
  int ponto = divideString(s, inicio, fim);

  // se o ponto de divisão for -1 significa que já achou uma string correta
  // dai retorno ela
  if (ponto == -1) {
    return res;
  }

  struct body esquerda;
  struct body direita;

  esquerda = encontrarSubstring(s, inicio, ponto);
  direita = encontrarSubstring(s, ponto + 1, fim);

  res = (esquerda.fim - esquerda.inicio) >= (direita.fim - direita.inicio) ? esquerda : direita;
  return res;
}

char* longestNiceSubstring(char* s) {
  int len = strlen(s);

  // Encontrar o início e o fim da substring
  struct body pair = encontrarSubstring(s, 0, len);

  // Copiar a resposta para retorná-la
  char* res = (char*)malloc(sizeof(char) * ((pair.fim - pair.inicio) + 1));
  res[(pair.fim - pair.inicio)] = '\0';
  memcpy(res, &(s[pair.inicio]), (pair.fim - pair.inicio) * sizeof(char));
  return res;
}

int main(void) {
  printf("Hello World\n");
  return 0;
}
