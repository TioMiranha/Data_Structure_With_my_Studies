#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; // para utilizar cout
int buscaSimples(int vetor[TAM], int valorProcurado, int *posEncontrada);
void imprimeVetor(int vetor[TAM]);

int main()
{
  int vetor[TAM] = {10, 32, 83, 43, 25, 78, 90, 123, 99, 200};
  int valorProcurado;
  int i, posEncontrada;

  // Função criada para imprimir o vetor
  imprimeVetor(vetor);

  printf("Qual número você deseja encontrar? ");
  scanf("%d", &valorProcurado);

  int resultBusca = buscaSimples(vetor, valorProcurado, &posEncontrada);

  if (resultBusca == 1)
  {
    printf("O valor foi encontrado na posição: V[%d] \n", posEncontrada);
  }
  else
  {
    printf("Valor não encontrado \n");
  }

  return 0;
}

int buscaSimples(int vetor[TAM], int valorProcurado, int *posEncontrada)
{
  // Verifica se o valor foi encontrado
  int i, valorFoiEncontrado;

  // Percorre a lista em busca do valor
  for (i = 0; i < TAM; i++)
  {
    if (vetor[i] == valorProcurado)
    {
      valorFoiEncontrado = 1;
      *posEncontrada = i;
    }
  }

  if (valorFoiEncontrado == 1)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

void imprimeVetor(int vetor[TAM])
{
  int i;

  // Imprime o vetor
  for (i = 0; i < TAM; i++)
  {
    printf("V[%d] \n", vetor[i]);
  }
}