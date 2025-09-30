#include <iostream>
#include <stdlib.h>
#include <string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM]);
void pilhaPush(int pilha[TAM], int valor, int *topo);

int main()
{
  int pilha[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int topo = -1; // Topo da pilha
  printf("Primeira impressão: \n");
  imprimeVetor(pilha);

  pilhaPush(pilha, 20, &topo);
  pilhaPush(pilha, 7, &topo);

  printf("Segunda impressão: \n");
  imprimeVetor(pilha);
}

void imprimeVetor(int vetor[TAM])
{
  int i;

  printf("\n");
  // Imprime o vetor
  for (i = 0; i < TAM; i++)
  {
    printf("V[%d] \n", vetor[i]);
  }
}

void pilhaPush(int pilha[TAM], int valor, int *topo)
{

  // Caso não possa colocar mais valores
  if (*topo == (TAM - 1))
  {
    printf("Pilha cheia");
  }
  else
  {
    *topo = *topo + 1;
    pilha[*topo] = valor;
  }
}