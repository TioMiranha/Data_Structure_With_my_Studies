#include "Conta.h"

int main()
{
  Conta newConta[4];
  int i, op;
  double valor;

  do
  {
    menu();
    scanf("%d", &op);

    if (op == 1)
      cadastrar(newConta, TAM);
    if (op == 2)
      listaPessoasCadastradas(newConta, TAM);
    if (op == 3)
    {
      int contaDeTransferência;

      printf("Digite o numero da sua conta: ");
      scanf("%d", &contaDeTransferência);

      for (i = 0; i < TAM; i++)
      {
        if (contaDeTransferência == newConta[i].numeroDaConta)
        {
          printf("Digite o valor que você deseja transferir para a conta: \n");
          scanf("%lf", &valor);
          transferir(newConta, TAM, valor);
          newConta[i].saldo -= valor;
        }
      }
    }
    if (op == 4)
      saque(newConta, TAM);
    if (op == 5)
      deposito(newConta, TAM);

  } while (op != 9);
}

void cadastrar(Conta cadastro[], int tam)
{
  int i;

  for (i = 0; i < tam; i++)
  {
    getchar();

    printf("Digite o seu nome: \n");
    fgets(cadastro[i].nomeDoTitular, sizeof(cadastro[i].nomeDoTitular), stdin);
    cadastro[i].nomeDoTitular[strcspn(cadastro[i].nomeDoTitular, "\n")] = '\0';

    puts("Digite o numero da sua conta");
    scanf("%d", &cadastro[i].numeroDaConta);

    puts("Digite a sua idade");
    scanf("%d", &cadastro[i].idade);

    puts("Insira o seu saldo inicial");
    scanf("%lf", &cadastro[i].saldo);
  }
}

void listaPessoasCadastradas(Conta pessoas[], int tam)
{
  int i;

  for (i = 0; i < tam; i++)
  {
    printf("Pessoa: %d { \n", i);
    printf("Nome: %s \n", pessoas[i].nomeDoTitular);
    printf("Numero da conta: %d \n", pessoas[i].numeroDaConta);
    printf("Idade: %d \n", pessoas[i].idade);
    printf("Saldo: %lf \n", pessoas[i].saldo);
    printf("Fim dos dados da pessoa: %d } \n", i);
    printf("\n");
  }
}

void menu()
{
  printf("Escolha uma das opções abaixo: \n");
  printf("Cadastrar: 1 \n");
  printf("Listar Cadastros: 2 \n");
  printf("Transferir: 3 \n");
  printf("Saque: 4 \n");
  printf("Depósito: 5 \n");
  printf("Sair: 9 \n");
}

void transferir(Conta contaDestino[], int tam, int valor)
{
  int numeroContaDestino, i;

  printf("Digite o número da conta da pessoa a qual você quer transferir \n");
  scanf("%d", &numeroContaDestino);

  for (i = 0; i < tam; i++)
  {

    if (numeroContaDestino == contaDestino[i].numeroDaConta)
    {
      contaDestino[i].saldo += valor;
    }
    else
    {
      printf("Numero da conta de destino: %d", contaDestino[i].numeroDaConta);
    }
  }
}

void saque(Conta contaParaSaque[], int tam)
{
  int i, numeroConta;
  double valor;

  printf("Digite o numero da sua conta: \n");
  scanf("%d", &numeroConta);

  printf("Digite o valor que você deseja sacar: \n");
  scanf("%lf", &valor);

  for (i = 0; i < tam; i++)
  {
    if (contaParaSaque[i].numeroDaConta == numeroConta)
    {

      if (contaParaSaque[i].saldo < valor)
      {
        printf("Você não pode realizar o saque, pois o saldo é insuficiente \n");
      }
      else
      {
        printf("Saque realizado com sucesso \n");
        contaParaSaque[i].saldo -= valor;
      }
    }
  }
}

void deposito(Conta contaParaSaque[], int tam)
{
  int i, numeroConta;
  double valor;

  printf("Digite o numero da conta que você deseja realizar o depósito: \n");
  scanf("%d", &numeroConta);

  printf("Digite o valor que você deseja depositar: \n");
  scanf("%lf", &valor);

  for (i = 0; i < tam; i++)
  {
    if (contaParaSaque[i].numeroDaConta == numeroConta)
    {
      printf("Depósito realizado com sucesso \n");
      contaParaSaque[i].saldo += valor;
    }
  }
}