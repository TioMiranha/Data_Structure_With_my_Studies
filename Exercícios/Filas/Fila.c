/*
Exercício:
 Implementar um sistema de senhas de atendimento com uma fila normal e uma fila de prioridade.
Se a pessoa tiver a idade a partir de 60 anos, ela deverá ser inserida na fila de prioridade.
Se a fila de prioridade estiver cheia, inserir na fila normal.
As demais serão inseridas na fila normal.
Caso a fila normal esteja cheia, não inserir mais elementos.
Se ambas estiverem cheias, não inserir.
Todas as remoções serão feitas primeiro na fila de prioridade.
Quando a fila de prioridade estiver vazia, remover da fila normal.
Ao remover informar os dados da pessoa que será atendida.
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct
{
  char nome[40];
  int idade;
} Pessoa;

typedef struct
{
  Pessoa dados[TAM];
  int inicio;
  int tam;
} Fila;

typedef struct
{
  Pessoa dados[TAM];
  int inicio;
  int tam;
} FilaPreferencial;

void menu();
void imprimeDados(Pessoa p);
void listarFila(Fila *f);
void inicializarConstrutorDaFila(Fila *fila);
void inserirDados(Fila *f, Pessoa d);
void inserirDadosPreferencial(FilaPreferencial *f, Pessoa d);
void remove(Fila *f, FilaPreferencial *fPreferencial);
void removerDadosNormal(Fila *f);
void removerDadosPreferencial(FilaPreferencial *fPreferencial);
Pessoa entrarNaFila();
int filaIsFull(Fila *f);
int filaIsEmpty(Fila *f);

int main()
{
  int i, op;
  Fila fila;
  FilaPreferencial fPreferencial;
  inicializarConstrutorDaFila(&fila);

  do
  {
    menu();
    scanf("%d", &op);

    if (op == 1)
    {
      if (!filaIsFull(&fila))
        entrarNaFila(&fila);
      else
        printf("Fila cheia");
    }
    if (op == 2)
    {
      if (!filaIsEmpty(&fila))
        removerDados(&fila, &fPreferencial);
      else
        printf("A fila ja esta vazia");
    }
    if (op == 8)
      listarFila(&fila);

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

void inicializarConstrutorDaFila(Fila *fila)
{
  fila->tam = 0;
  fila->inicio = 0;
}

void inserirDados(Fila *f, Pessoa d)
{
  f->dados[(f->tam + f->inicio) % TAM] = d;
  f->tam++;
}

void inserirDadosPreferencial(FilaPreferencial *f, Pessoa d)
{
  f->dados[(f->tam + f->inicio) % TAM] = d;
  f->tam++;
}

void remove(Fila *f, FilaPreferencial *fPreferencial)
{

  if (fPreferencial->tam == 0)
    removerDadosNormal(&f);
  else
    removerDadosPreferencial(&fPreferencial);
}

void removerDadosNormal(Fila *f)
{
  f->tam--;
  f->inicio = (f->inicio + 1) % TAM;
}

void removerDadosPreferencial(FilaPreferencial *fPreferencial)
{
  fPreferencial->tam--;
  fPreferencial->inicio = (fPreferencial->inicio + 1) % TAM;
}

Pessoa entrarNaFila(Fila *f)
{
  Pessoa p;
  getchar();

  printf("Digite o seu nome:");
  fgets(p.nome, sizeof(p.nome), stdin);

  printf("Digite a sua idade: \n");
  scanf("%d", &p.idade);

  if (p.idade >= 60)
    inserirDadosPreferencial(&f, p);
  else
    inserirDados(&f, p);

  return p;
}

int filaIsFull(Fila *f)
{
  if (f->tam == TAM)
    return 1;
  else
    return 0;
}

int filaIsEmpty(Fila *f)
{
  if (f->tam == 0)
    return 1;
  else
    return 0;
}

void imprimeDados(Pessoa p)
{
  printf("Nome da pessoa: %s \n", p.nome);
  printf("Idade da pessoa: %d \n", p.idade);
}

void listarFila(Fila *f)
{
  int i, j;
  for (i = 0, j = f->inicio; i < f->tam; i++, j = (j++ % TAM))
  {
    imprimeDados(f->dados[j]);
  }
}
