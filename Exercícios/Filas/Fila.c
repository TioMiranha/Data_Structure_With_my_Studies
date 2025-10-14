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
#include "Fila.h"

int main()
{
  int op;
  Fila fila;
  FilaPreferencial fPreferencial;
  inicializarConstrutorDaFila(&fila, &fPreferencial);

  do
  {
    menu();
    scanf("%d", &op);

    if (op == 1)
      entrarNaFila(&fila, &fPreferencial);
    if (op == 2)
      remover(&fila, &fPreferencial);
    if (op == 8)
      listarFilas(&fila, &fPreferencial);

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

void inicializarConstrutorDaFila(Fila *fila, FilaPreferencial *filaPreferencial)
{
  fila->tam = 0;
  fila->inicio = 0;

  filaPreferencial->tam = 0;
  filaPreferencial->inicio = 0;
}

void inserirDados(Fila *f, Pessoa d)
{
  f->dados[(f->tam + f->inicio) % TAM1] = d;
  f->tam++;
}

void inserirDadosPreferencial(FilaPreferencial *f, Pessoa d)
{
  f->dados[(f->tam + f->inicio) % TAM2] = d;
  f->tam++;
}

void remover(Fila *f, FilaPreferencial *fPreferencial)
{
  Pessoa atendido;

  if (!filaPreferencialIsEmpty(fPreferencial))
  {
    atendido = fPreferencial->dados[fPreferencial->inicio];
    imprimeDadosPreferencial(atendido);
    removerDadosPreferencial(fPreferencial);
  }
  else if (!filaNormalIsEmpty(f))
  {
    atendido = f->dados[f->inicio];
    imprimeDados(atendido);
    removerDadosNormal(f);
  }
  else
  {
    printf("Nenhuma pessoa na fila.\n");
  }
}

void removerDadosNormal(Fila *f)
{
  f->tam--;
  f->inicio = (f->inicio + 1) % TAM1;
}

void removerDadosPreferencial(FilaPreferencial *fPreferencial)
{
  fPreferencial->tam--;
  fPreferencial->inicio = (fPreferencial->inicio + 1) % TAM2;
}

Pessoa entrarNaFila(Fila *f, FilaPreferencial *fPreferencial)
{
  Pessoa p;
  getchar();

  printf("Digite o seu nome:");
  fgets(p.nome, sizeof(p.nome), stdin);

  printf("Digite a sua idade: \n");
  scanf("%d", &p.idade);

  if (p.idade >= 60)
  {
    if (!filaPreferencialIsFull(fPreferencial))
    {
      inserirDadosPreferencial(fPreferencial, p);
    }
    else
    {
      printf("Fila preferêncial cheia, inserindo dados na fila normal... \n");
      if (!filaNormalIsFull(f))
      {
        inserirDados(f, p);
      }
      else
      {
        printf("Fila normal cheia");
      }
    }
  }
  else
  {
    if (!filaNormalIsFull(f))
    {
      inserirDados(f, p);
    }
    else
    {
      printf("Fila normal cheia");
    }
  }

  return p;
}

int filaNormalIsFull(Fila *f)
{
  if (f->tam == TAM1)
    return 1;
  else
    return 0;
}

int filaPreferencialIsFull(FilaPreferencial *fPreferencial)
{
  if (fPreferencial->tam == TAM2)
    return 1;
  else
    return 0;
}

int filaNormalIsEmpty(Fila *f)
{
  if (f->tam == 0)
    return 1;
  else
    return 0;
}

int filaPreferencialIsEmpty(FilaPreferencial *fPreferencial)
{
  if (fPreferencial->tam == 0)
    return 1;
  else
    return 0;
}

void imprimeDados(Pessoa p)
{
  printf("Nome da pessoa: %s \n", p.nome);
  printf("Idade da pessoa: %d \n", p.idade);
}

void imprimeDadosPreferencial(Pessoa pPreferencial)
{
  printf("Nome da pessoa: %s \n", pPreferencial.nome);
  printf("Idade da pessoa: %d \n", pPreferencial.idade);
}

void listarFilas(Fila *f, FilaPreferencial *fPreferencial)
{
  int i, j, k, l;
  for (i = 0, j = f->inicio; i < f->tam; i++, j = (j + 1) % TAM1)
  {
    printf("Dados da fila normal: \n");
    imprimeDados(f->dados[j]);
  }

  for (k = 0, l = fPreferencial->inicio; k < fPreferencial->tam; k++, l = (l + 1) % TAM2)
  {
    printf("Dados da fila preferêncial: \n");
    imprimeDadosPreferencial(fPreferencial->dados[l]);
  }
}