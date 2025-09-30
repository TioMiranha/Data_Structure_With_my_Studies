#include <iostream>
#include <stdlib.h>
#include <string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM], int topo);
int isVectorEmpty(int topo);
int isVectorFull(int topo);
int tamPilha(int topo);
int pilhaGet(int pilha[TAM], int *topo);
void pilhaPush(int pilha[TAM], int valor, int *topo);
void pilhaPop(int pilha[TAM], int *topo);
void pilhaConstructor(int pilha[TAM], int *topo);

int main()
{
  int pilha[TAM];
  int topo, initalTamPilha, getLastElement; // Topo da pilha

  pilhaConstructor(pilha, &topo);
  imprimeVetor(pilha, topo);
  pilhaPush(pilha, 20, &topo);
  getLastElement = pilhaGet(pilha, &topo);
  printf("O último elemento inserido na pilha foi: %d", getLastElement);
  imprimeVetor(pilha, topo);

  initalTamPilha = tamPilha(topo);
  printf("Tamanho da pilha: %d", initalTamPilha);

  pilhaPush(pilha, 20, &topo);
  pilhaPush(pilha, 20, &topo);
  pilhaPush(pilha, 20, &topo);
  pilhaPush(pilha, 7, &topo);
  pilhaPush(pilha, 7, &topo);
  pilhaPush(pilha, 7, &topo);
  pilhaPush(pilha, 7, &topo);
  pilhaPush(pilha, 7, &topo);
  pilhaPush(pilha, 7, &topo);

  imprimeVetor(pilha, topo);

  pilhaPop(pilha, &topo);
  imprimeVetor(pilha, topo);
}

// Imprime valores da pilha
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

// Adiciona valores na pilha
void pilhaPush(int pilha[TAM], int valor, int *topo)
{
  int isFull;
  isFull = isVectorFull(*topo);
  // Caso não possa colocar mais valores
  if (isFull == 1)
  {
    printf("Pilha cheia");
  }
  else
  {
    *topo = *topo + 1;
    pilha[*topo] = valor;
  }
}

// REmove valor da pilha
void pilhaPop(int pilha[TAM], int *topo)
{
  int isEmpty;
  isEmpty = isVectorEmpty(*topo);

  if (isEmpty == 1)
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

// Pilha vazia
int isVectorEmpty(int topo)
{
  int isEmpty;

  if (topo == -1)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

// Pilha cheia
int isVectorFull(int topo)
{
  if (topo == (TAM - 1))
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

// Retorna o tamanho da pilha
int tamPilha(int topo)
{
  return topo + 1;
}

// Retorna o último valor da pilha
int pilhaGet(int pilha[TAM], int *topo)
{
  int pilhaIsempty = isVectorEmpty(*topo);
  if (pilhaIsempty == 1)
  {
    return printf("A pilha esta vazia ");
    return 0;
  }
  else
  {
    return pilha[*topo];
  }
}

// Constrói a pilha com base no seu tamanho e limpa ela
void pilhaConstructor(int pilha[TAM], int *topo)
{
  // Topo negativo para indicar uma pilha vazia
  *topo = -1;
  int i;

  // Imprime o vetor
  for (i = 0; i < TAM; i++)
  {
    pilha[i] = 0;
  }
}