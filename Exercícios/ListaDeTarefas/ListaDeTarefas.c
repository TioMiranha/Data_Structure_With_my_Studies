#include "ListaDeTarefas.h"

/*
1. Faça um programa que gerenciar uma lista de tarefas para serem executadas.
A tarefas deverão ter um número e uma decrição.
O programa deverá permitir cadastrar tarefas e executar tarefas.
Quando uma tarefa for executada, ela deverá ser removida da lista de tarefas pendentes e inserida e
uma lista de tarefas executadas.
O programa deverá permitir listar as tarefas pendentes e as tarefas executadas.
*/

void imprimirDadosDaTarefaPendente(LISTA *l, ListaDeTarefa *tarefa);
void initializeListasDeTarefas(LISTA *l);
void inserirTarefaPendente(LISTA *l, ListaDeTarefa tP);
void menu();

int main()
{
  ListaDeTarefa tarefa;
  LISTA lista;
  int i, op;

  initializeListasDeTarefas(&lista);
  do
  {
    menu();
    scanf("%d", &op);

    if (op == 1)
    {
      if (!isFull(&lista))
        inserirTarefa(&lista, tarefa);
      else
        printf("A fila de Tarefas esta cheia");
    }
    if (op == 2)
    {
      if (!isEmpty(&lista))
    }

  } while (op != 9);
}

void menu()
{
  printf("Escolha uma das opções abaixo: \n");
  printf("Entrar na fila: 1 \n");
  printf("Sair da fila: 2 \n");
  printf("Listar dados da fila: 8 \n");
  printf("Sair: 9 \n");
}

int isFull(LISTA *l)
{
  if (l->tam == MAX)
    return 1;
  else
    return 0;
}

void imprimirDadosDaTarefaPendente(LISTA *l, ListaDeTarefa *tarefa)
{
  int i;

  for (i = 0; i < l->tam; i++)
  {
    printf("Chave:%d\n", tarefa[i].id);
    printf("Nome:%s", tarefa[i].nomeDaTarefa);
  }
}

void initializeListasDeTarefas(LISTA *l)
{
  l->tam = 0;
}

void inserirTarefaPendente(LISTA *l, TarefaPendente tP)
{
  l->dadosPendente[l->tamPendente] = tP;
  l->tamPendente++;
}