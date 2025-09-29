#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <new>

using namespace std;

// Struct para frutas
struct fruta
{
  string cor;
  string nome;
};

int main()
{

  // Criando um ponteiro para o struct criado
  fruta *primeiraFruta = new fruta;

  // Modificando valores
  primeiraFruta->cor = "Amarelo";
  primeiraFruta->nome = "banana";

  // Exibindo valores
  cout << "Fruta: " << primeiraFruta->nome << ", Cor: " << primeiraFruta->cor;

  // Criando uma lista de frutas
  fruta *ponteiroListaDeFrutas = new fruta[2];

  ponteiroListaDeFrutas[0].cor = "Vermelho";
  ponteiroListaDeFrutas[0].nome = "Morango";

  ponteiroListaDeFrutas[1].cor = "Verde";
  ponteiroListaDeFrutas[1].nome = "Limão";

  int cont;

  for (cont = 0; cont < 2; cont++)
  {
    // Por ser um vetor não é necessário usar o sinal '->'
    cout << "Fruta: \n"
         << ponteiroListaDeFrutas[cont].nome << ", Cor: \n"
         << ponteiroListaDeFrutas[cont].cor;
  }

  return 0;
}