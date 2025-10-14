#include <stdio.h>
#include <stdlib.h>

// Cria função de incremento baseada em ponteiro
void funct(int *pointer)
{
  ++(*pointer);
  printf("Incrementando o ponteiro da funct: %d\n", *pointer);
}

int main()
{
  int x = 5; // cria variável x com valor 5
  printf("Valor de x: %d \n", x);
  int *py = &x; // Cria um ponteiro e indica o endereço de x na memória
  // Ao indicar o endereço de x na memória o ponteiro passa a ter o mesmo valor de x

  funct(&x); // Enviando o endereço de memória para a funct
  printf("Valor de x após ser incrementada sem a necessidade de um retorno(return): %d \n", *py);

  printf("Incrementando o ponteiro do main: \n");
  funct(py); // Enviando o ponteiro main
  printf("Ponteiro do main: %d", *py);

  return 0;
}
