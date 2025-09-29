#include <stdio.h>
#include <stdlib.h>

int retornaComMaisDez(int numero);
void aumentaDezComPonteiro(int *numero);

int main()
{
  // Definindo variáveis
  int a = 5;

  // Mostrando o valor
  printf("%d \n", a);

  // Aumenta 10
  a = retornaComMaisDez(a);

  // Retornando valor
  printf("%d \n", a);

  // Função que aumenta 10 diretamente
  aumentaDezComPonteiro(&a);

  // Mostrando valor
  printf("%d \n", a);

  return 0;
}

int retornaComMaisDez(int numero)
{
  return numero + 10;
}

void aumentaDezComPonteiro(int *numero)
{
  *numero = *numero + 10;
}