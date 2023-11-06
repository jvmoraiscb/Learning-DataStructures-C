/*
Implemente uma lista simplesmente (ou duplamente se quiser um desafio um pouco maior) encadeada com
sentinela, usando recursão! A lista pode ser de qualquer tipo que você quiser. As seguintes funcionalidades são esperadas:

Básicas: Criação, inserção, retirada, impressão e liberação da memória.


Extra: Função que verifica se duas listas são iguais (estrutura e conteúdo).

Bom exercício!
*/
#include "../include/nodeList.h"
#include <stdio.h>

int main()
{
  List *list = ListConstructor(), *list2 = ListConstructor(), *list3 = ListConstructor();

  ListInsert(list, "1");
  ListInsert(list, "2");
  ListInsert(list, "3");
  ListInsert(list, "4");
  ListInsert(list, "5");
  ListDisplay(list);
  printf("\n");

  ListRemove(list, "1");
  ListRemove(list, "5");
  ListRemove(list, "3");
  ListDisplay(list);
  printf("\n");

  ListInsert(list, "10");
  ListDisplay(list);
  printf("\n");

  ListInsert(list2, "2");
  ListInsert(list2, "4");
  ListInsert(list2, "10");

  ListInsert(list3, "4");

  printf("%d %d\n", ListCmp(list, list2), ListCmp(list, list3));

  ListDestructor(list);
  ListDestructor(list2);
  ListDestructor(list3);
  return 0;
}