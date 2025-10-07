#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct
{
  char nomeDoTitular[20];
  int numeroDaConta;
  int idade;
  double saldo;
} Conta;

void menu();
void cadastrar(Conta cadastro[], int tam);
void listaPessoasCadastradas(Conta pessoas[], int tam);
void transferir(Conta contaDestino[], int tam, int valor);
void saque(Conta contaParaSaque[], int tam);
void deposito(Conta contaParaSaque[], int tam);