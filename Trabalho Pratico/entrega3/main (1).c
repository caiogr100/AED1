#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// inclusive eu tava pesquisando na aula sobre DFS pq n lembrava perfeitamente e nao sabia 
// que nao podia, peço perdao por isso
struct TreeNode{
    int val; // Valor do nó
    struct TreeNode *left; // Ponteiro para o filho esquerdo
    struct TreeNode *right; // Ponteiro para o filho direito
};

// Definindo uma estrutura para armazenar informações sobre um nó durante a DFS
struct Result {
    struct TreeNode* parent; // Ponteiro para o nó pai
    int depth; // Profundidade do nó na árvore
};

// Função para realizar a depth first search (DFS) para encontrar um nó na árvore binária
struct Result* dfs(struct TreeNode* node, struct TreeNode* parent, int depth, int value) {
    if (!node) {
        return NULL; // Se o nó for NULL, retorna NULL
    }

    if (node->val == value) {
        // Se o valor do nó corresponder ao valor cria uma estrutura result
        // para armazenar informações sobre o nó pai e a profundidade, e retornar ela
        struct Result* result = (struct Result*)malloc(sizeof(struct Result));
        result->parent = parent;
        result->depth = depth;
        return result;
    }

    // Busca recursivamente nas subárvores 
    struct Result* left_result = dfs(node->left, node, depth + 1, value);
    struct Result* right_result = dfs(node->right, node, depth + 1, value);
      
    return right_result; // Se encontrado no subárvore direita, retorne o resultado
}

bool isCousins(struct TreeNode* root, int x, int y) {
    // Usando o DFS para encontrar informações sobre os nós x e y na árvore binária
    struct Result* x_info = dfs(root, NULL, 0, x);
    struct Result* y_info = dfs(root, NULL, 0, y);

    if (x_info && y_info) {
        struct TreeNode* x_parent = x_info->parent;
        int x_depth = x_info->depth;
        struct TreeNode* y_parent = y_info->parent;
        int y_depth = y_info->depth;

        // Verifica se têm a mesma profundidade e pais diferentes para serem primos
        if (x_depth == y_depth && x_parent != y_parent) {
            return true; // Retorna true se forem primos
        }
    }

    // Se um ou ambos os nós não forem encontrados retorna false
    return false;
}
int main(){
  printf("Hello World");
  return 0;
}
