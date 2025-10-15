#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
  int id;
  char nomeDaTarefa[255];
} ListaDeTarefa;

typedef struct
{
  ListaDeTarefa dados[MAX]; // CARGA DE DADOS
  int tam;
} LISTA;
