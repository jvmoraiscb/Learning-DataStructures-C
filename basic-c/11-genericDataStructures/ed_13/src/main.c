/*
A ideia do exercício de hoje é implementar uma ABB Genérica! Escolham uma das opções abaixo:
=> opção1 (mais rápida): 1 tad genérico e 1 cliente implementando todos os callbacks
=> opção2 (mais demorada, porém com modularização): 1 tad genérico e 1 tad para cada uso específico da árvore e 1 cliente.

Testem a árvore genérica com 2 tipos de chave de busca. Por exemplo, em uma árvore de alunos, deve-se fazer busca por nome ou por matrícula. 

BOA AULA!!! :-)
*/
#include "../include/aluno-abb.h"
#include <stdio.h>

int main()
{
  Aluno *Joao = Constroi_aluno("Joao", 1), *Talles = Constroi_aluno("Talles", 2), *Celso = Constroi_aluno("Celso", 3), *Bruno = Constroi_aluno("Bruno", 4), *Afonso = Constroi_aluno("Afonso", 5), *Matheus = Constroi_aluno("Matheus", 6), *Ariane = Constroi_aluno("Ariane", 7);

  Arv *arvore = arv_aluno_criavazia();
  arvore = arv_aluno_insere_matricula(arvore, Afonso);
  arvore = arv_aluno_insere_matricula(arvore, Ariane);
  arvore = arv_aluno_insere_matricula(arvore, Matheus);
  arvore = arv_aluno_insere_matricula(arvore, Talles);
  arvore = arv_aluno_insere_matricula(arvore, Celso);
  arvore = arv_aluno_insere_matricula(arvore, Joao);
  arvore = arv_aluno_insere_matricula(arvore, Bruno);

  arvore = arv_aluno_retira_matricula(arvore, 7);
  arvore = arv_aluno_retira_matricula(arvore, 2);

  arv_aluno_imprimeCodigo(arvore);

  arv_aluno_libera(arvore);
  Libera_aluno(Afonso);
  Libera_aluno(Joao);
  Libera_aluno(Talles);
  Libera_aluno(Bruno);
  Libera_aluno(Celso);
  Libera_aluno(Matheus);
  Libera_aluno(Ariane);

  return 0;
}
