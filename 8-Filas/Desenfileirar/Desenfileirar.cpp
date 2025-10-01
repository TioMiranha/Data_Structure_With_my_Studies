#include <iostream>
#include <stdlib.h>
#include <string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM], int tamFila);
void filaConstructor(int *frente, int *tras);
int filaVazia(int frente, int tras);
int filaCheia(int tras);
void filaEnfileirar(int fila[TAM], int valor, int *tras);
void fialDesenfileirar(int fila[TAM], int *frente, int tras);
int filaTam(int tras, int frente);

int main()
{
  int fila[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int frente, tras;
  int valor, tamanhoFila;

  filaConstructor(&frente, &tras);

  filaEnfileirar(fila, 5, &tras);
  filaEnfileirar(fila, 7, &tras);
  filaEnfileirar(fila, 8, &tras);
  filaEnfileirar(fila, 34, &tras);

  fialDesenfileirar(fila, &frente, tras);
  fialDesenfileirar(fila, &frente, tras);
  fialDesenfileirar(fila, &frente, tras);
  fialDesenfileirar(fila, &frente, tras);
  fialDesenfileirar(fila, &frente, tras);

  filaEnfileirar(fila, 98, &tras);
  filaEnfileirar(fila, 5, &tras);
  filaEnfileirar(fila, 7, &tras);
  filaEnfileirar(fila, 8, &tras);
  filaEnfileirar(fila, 34, &tras);

  tamanhoFila = filaTam(tras, frente);
  imprimeVetor(fila, tamanhoFila);

  return 0;
}

void imprimeVetor(int vetor[TAM], int tamFila)
{
  int i;

  printf("\n");
  // Imprime o vetor
  for (i = 0; i < TAM; i++)
  {
    printf("V[%d] \n", vetor[i]);
  }
}

void filaConstructor(int *frente, int *tras)
{
  *frente = 0;
  *tras = -1;
}

int filaVazia(int frente, int tras)
{
  if (frente > tras)
  {
    printf("A fila esta vazia \n");
    return 1;
  }
  else
  {
    return -1;
  }
}

int filaCheia(int tras)
{
  if (tras > (TAM - 1))
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

void filaEnfileirar(int fila[TAM], int valor, int *tras)
{
  int isFull = filaCheia(*tras);

  if (isFull == 1)
  {
    printf("Fila cheia \n");
  }
  else
  {
    *tras = *tras + 1;
    fila[*tras] = valor;
  }
}

void fialDesenfileirar(int fila[TAM], int *frente, int tras)
{

  int isEmpty = filaVazia(*frente, tras);

  if (isEmpty == 1)
  {
    printf("A fila ja está vazia");
  }
  else
  {
    printf("O valor %d foi retirado da fila \n", fila[*frente]);
    fila[*frente] = 0;
    *frente = *frente + 1;
  }
}

int filaTam(int tras, int frente)
{
  return (tras - frente) + 1;
}