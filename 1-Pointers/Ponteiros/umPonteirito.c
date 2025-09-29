#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
  // Variável
  int a = 20;
  // Imprimindo o valor da variável
  printf("Valor de a: %d \n", a);

  printf("Endereço de a: %d \n", &a);

  // Lendo o valor de uma variável
  // Operador de endereço de memória
  scanf("%d", &a);

  printf("Novo valor de a: %d \n", a);

  // Variáveis armazenam valores
  int b = 10;
  // Ponteiros armazenam posições da memória
  int *ponteiro;

  // Ponteiro recebendo a posição da memória da variável b
  ponteiro = &b;

  // Imprimindo o valor da  variável b
  printf("Valor de b: %d \n", b);

  //* -> pode ser lido como conteúdo apontado por
  *ponteiro = 40;

  printf("Valor de b: %d \n", b);

  /*
  VARIAVEL
  [VALOR QUE ARMAZENA]
  [POSIÇÃO NA MEMMORIA]

  PONTEIRO
  [POSIÇÃO DA MEMORIA QUE ESTA ARMAZENANDO]
  [POSIÇÃO NA MEMORIA]
  */

  return 0;
}