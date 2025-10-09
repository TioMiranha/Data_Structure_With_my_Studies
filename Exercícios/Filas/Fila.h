#include <stdio.h>
#include <stdlib.h>

#define TAM1 2
#define TAM2 2

typedef struct
{
  char nome[40];
  int idade;
} Pessoa;

typedef struct
{
  Pessoa dados[TAM1];
  int inicio;
  int tam;
} Fila;

typedef struct
{
  Pessoa dados[TAM2];
  int inicio;
  int tam;
} FilaPreferencial;

void menu();
void imprimeDados(Pessoa p);
void imprimeDadosPreferencial(Pessoa pPreferencial);
void listarFilas(Fila *f, FilaPreferencial *fPreferencial);
void inicializarConstrutorDaFila(Fila *fila, FilaPreferencial *filaPreferencial);
void inserirDados(Fila *f, Pessoa d);
void inserirDadosPreferencial(FilaPreferencial *f, Pessoa d);
void remover(Fila *f, FilaPreferencial *fPreferencial);
void removerDadosNormal(Fila *f);
void removerDadosPreferencial(FilaPreferencial *fPreferencial);
Pessoa entrarNaFila(Fila *f, FilaPreferencial *fPreferencial);
int filaNormalIsFull(Fila *f);
int filaPreferencialIsFull(FilaPreferencial *fPreferencial);
int filaNormalIsEmpty(Fila *f);
int filaPreferencialIsEmpty(FilaPreferencial *fPreferencial);