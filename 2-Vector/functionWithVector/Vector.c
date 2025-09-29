#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int tam);
void modificaVetor(int *vetor, int tam);

int main()
{
  // Definindo Vetor
  int v[5] = {1, 2, 3};

  // Mostrando vetor
  imprimeVetor(v, 3);

  modificaVetor(v, 3);

  imprimeVetor(v, 3);

  return 0;
}

void imprimeVetor(int *vetor, int tam)
{
  // Variável Contadora
  int i;

  // Iterando sobre o vetor
  for (i = 0; i < tam; i++)
  {
    printf("%d \n", vetor[i]);
  }
}

void modificaVetor(int *vetor, int tam)
{
  int i;

  for (i = 0; i < tam; i++)
  {
    vetor[i] = vetor[i] + 1;
  }
}