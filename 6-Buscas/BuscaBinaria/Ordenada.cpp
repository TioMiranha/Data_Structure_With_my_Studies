#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; // para utilizar cout
int buscaBinaria(int vetor[TAM], int valorProcurado, int *posEncontrada);
void imprimeVetor(int vetor[TAM]);

int main()
{
  int vetor[TAM] = {10, 32, 83, 43, 25, 78, 90, 123, 99, 200};
  int valorProcurado;
  int posEncontrada;

  // Função criada para imprimir o vetor
  imprimeVetor(vetor);

  // Lendo o número buscado
  printf("Qual número você deseja encontrar? ");
  scanf("%d", &valorProcurado);

  int resultBusca = buscaBinaria(vetor, valorProcurado, &posEncontrada);

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

int busca_binaria(int vetor[TAM], int valorProcurado, int *posicaoEncontrada)
{

  int esquerda = 0;      // Limite da esquerda
  int direita = TAM - 1; // Limite da direita
  int meio;              // O meio onde fica o cursor

  while (esquerda <= direita)
  {

    // Encontra o meio da análise
    meio = (esquerda + direita) / 2;

    // Quando o valor do meio é encontrado
    if (valorProcurado == vetor[meio])
    {
      *posicaoEncontrada = meio;
      return 1;
    }

    // Ajustando os limites laterais
    if (vetor[meio] < valorProcurado)
    {
      esquerda = meio + 1;
    }
    else
    {
      direita = meio - 1;
    }
  }

  return -1;
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