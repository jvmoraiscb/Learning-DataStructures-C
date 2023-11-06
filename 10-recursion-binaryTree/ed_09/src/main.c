/*
Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, impressão, inserção, retirada e liberação.

Implemente um testador para sua implementação.

Boa AULA! :-)
*/
#include "../include/abb.h"
#include <stdio.h>

int main()
{
  Aluno *Joao = Constroi_aluno("Joao", 1), *Talles = Constroi_aluno("Talles", 2), *Celso = Constroi_aluno("Celso", 3), *Bruno = Constroi_aluno("Bruno", 4), *Afonso = Constroi_aluno("Afonso", 5), *Matheus = Constroi_aluno("Matheus", 6), *Ariane = Constroi_aluno("Ariane", 7);

  Arv *arvore = arv_criavazia();
  arvore = arv_insere(arvore, Afonso);
  arvore = arv_insere(arvore, Ariane);
  arvore = arv_insere(arvore, Matheus);
  arvore = arv_insere(arvore, Talles);
  arvore = arv_insere(arvore, Celso);
  arvore = arv_insere(arvore, Joao);
  arvore = arv_insere(arvore, Bruno);

  arvore = arv_retira(arvore, 7);
  arvore = arv_retira(arvore, 2);

  imprimeCodigo(arvore);

  arv_libera(arvore);
  Libera_aluno(Afonso);
  Libera_aluno(Joao);
  Libera_aluno(Talles);
  Libera_aluno(Bruno);
  Libera_aluno(Celso);
  Libera_aluno(Matheus);
  Libera_aluno(Ariane);

  return 0;
}
