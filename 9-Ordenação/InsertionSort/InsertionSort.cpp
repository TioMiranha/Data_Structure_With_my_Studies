#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[]);
void insertionSort(int vetor[TAM]);

int main()
{
  int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  insertionSort(vetor);
  imprimeVetor(vetor);
  return 0;
}

void imprimeVetor(int vetor[])
{
  int i;
  printf("\n");
  for (i = 0; i < TAM; i++)
  {
    printf(" | %d | ", vetor[i]);
  }
}

void insertionSort(int vetor[TAM])
{
  int i, j, atual;

  for (i = 1; i < TAM; i++)
  {
    // Elemento atual
    atual = vetor[i];
    // Elemento anterior
    j = i - 1;

    // Analisando membros anteriores
    while (j >= 0 && (atual < vetor[j]))
    {
      // Posiciona os elementos uma posição para frente
      vetor[j + 1] = vetor[j];
      // Faço o j andar para tras
      j = j - 1;
    }

    // Agora que o espaço foi aberto colocamos o atual (menor numero) no espaço aberto
    vetor[j + 1] = atual;
  }
}