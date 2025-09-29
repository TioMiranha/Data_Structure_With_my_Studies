#include <stdio.h>
#include <stdlib.h>
#include <new>

// C++ é abstraído pakas

int main()
{
  int tam, cont;

  // Lendo o tamanho
  printf("Digite o tamanho: \n");
  scanf("%d", &tam);

  // Criando um ponteiro que recebe o novo vetor vazio
  int *vetor = new int(tam);

  // Imprimindo e modificando valores
  for (cont = 0; cont < tam; cont++)
  {
    vetor[cont] = cont;
    printf("\n %d", vetor[cont]);
  }
  return 0;
}