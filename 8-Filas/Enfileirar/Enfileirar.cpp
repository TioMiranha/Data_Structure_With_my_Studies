#include <iostream>
#include <stdlib.h>
#include <string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM], int tamFila);
void filaConstructor(int *frente, int *tras);
void filaEnfileirar(int fila[TAM], int valor, int *tras);
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
  filaEnfileirar(fila, 5, &tras);
  filaEnfileirar(fila, 7, &tras);
  filaEnfileirar(fila, 8, &tras);
  filaEnfileirar(fila, 5, &tras);
  filaEnfileirar(fila, 7, &tras);
  filaEnfileirar(fila, 8, &tras);

  tamanhoFila = filaTam(tras, frente);
  imprimeVetor(fila, tamanhoFila);

  return 0;
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

void filaConstructor(int *frente, int *tras)
{
  *frente = 0;
  *tras = -1;
}

void filaEnfileirar(int fila[TAM], int valor, int *tras)
{
  if (*tras == (TAM - 1))
  {
    printf("Fila cheia \n");
  }
  else
  {
    *tras = *tras + 1;
    fila[*tras] = valor;
  }
}

int filaTam(int tras, int frente)
{
  return (tras - frente) + 1;
}