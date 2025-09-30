#include <iostream>
#include <stdlib.h>
#include <string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM], int topo);
void pilhaPush(int pilha[TAM], int valor, int *topo);
void pilhaPop(int pilha[TAM], int *topo);

int main()
{
  int pilha[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int topo = -1; // Topo da pilha

  imprimeVetor(pilha, topo);

  pilhaPush(pilha, 20, &topo);
  imprimeVetor(pilha, topo);

  pilhaPush(pilha, 7, &topo);
  imprimeVetor(pilha, topo);

  pilhaPop(pilha, &topo);
  imprimeVetor(pilha, topo);
}

void imprimeVetor(int vetor[TAM], int topo)
{
  int i;

  printf("\n");
  // Imprime o vetor
  for (i = 0; i < TAM; i++)
  {
    printf("V[%d] \n", vetor[i]);
  }

  printf("Topo: %d", topo);
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

void pilhaPop(int pilha[TAM], int *topo)
{
  if (*topo == -1)
  {
    printf("A pilha ja esta vazia");
  }
  else
  {
    printf("Valor removido: %d \n", pilha[*topo]);
    pilha[*topo] = 0;
    *topo = *topo - 1;
  }
}