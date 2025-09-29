#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int tam);

int main()
{
  int *vetor, tam, cont;

  // Lendo o tamanho do vetor pelo usuário
  printf("Digite um tamanho para o vetor: \n");
  scanf("%d", &tam);

  // Ponteiro recebe o endereço de memória que foi alocado para o vetor
  vetor = alocaVetor(tam);

  /*
  Memória
        ESPAÇO RESERVADO
[] [] { v[0] v[1] v[2] v[3] } [] []
  */

  vetor[0] = 0;
  vetor[1] = 10;
  vetor[2] = 20;
  vetor[3] = 30;

  // Coloca valores no vetor
  for (cont = 0; cont < tam; cont++)
  {
    vetor[cont] = 90;
  }

  // Imprime Vetor
  for (cont = 0; cont < tam; cont++)
  {
    printf("%d\n", vetor[cont]);
  }

  free(vetor);

  return 0;
}

int *alocaVetor(int tam)
{
  // Criando um ponteiro auxiliar
  int *aux;

  // Alocação dinâmica de memória
  aux = (int *)malloc(tam * sizeof(int)); //(INT *) == Cast

  // Retorna o ponteiro aponta para a primeira posição da memória do vetor alocado
  return aux;
}