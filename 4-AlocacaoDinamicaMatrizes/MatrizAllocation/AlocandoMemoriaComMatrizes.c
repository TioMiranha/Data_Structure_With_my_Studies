#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Definindo variáveis
  int linhas = 3, colunas = 3, i, j;
  int **matriz; // ponteiro para ponteiro: p->p

  // Lendo o tamanho da matriz pelo usuário
  printf("Digite o número de linhas: ");
  scanf("%d", &linhas);

  printf("\n Digite o número de colunas: \n");
  scanf("%d", &colunas);

  // Alocando as linhas
  matriz = (int **)malloc(linhas * sizeof(int *));

  // Alocando memória para as colunas de cada linha
  for (i = 0; i < linhas; i++)
  {
    matriz[i] = (int *)malloc(colunas * sizeof(int));
  }

  // Montando a matriz
  for (i = 0; i < linhas; i++)
  {
    for (j = 0; j < colunas; j++)
    {
      matriz[i][j] = i;
      printf("%d", matriz[i][j]);
    }
    printf("\n");
  }

  // Libera a memória
  free(matriz);
  return 0;
}