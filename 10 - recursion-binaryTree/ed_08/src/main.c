/*
Implemente o TAD árvore do vídeo com a seguinte modificação: faça um TAD árvore de alunos (e não de char, como no vídeo). Use o nome do aluno como chave de busca na função pertence. Além disto, faça as funções:
- int folhas (Arv* a); //retorna o número de folhas da árvore
- int ocorrencias (Arv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
- int altura (Arv* a); retorna a altura da árvore

Inclua todos os arquivos (.c e .h) que você utilizou para fazer este exercício.

Divirta-se!!! :-)
*/

#include "../include/arvore.h"
#include <stdio.h>

int main()
{
  Aluno *Joao = Constroi_aluno("Joao", 1, 10, 10, 10), *Talles = Constroi_aluno("Talles", 2, 10, 10, 10), *Celso = Constroi_aluno("Celso", 3, 10, 10, 10), *Bruno = Constroi_aluno("Bruno", 3, 10, 10, 10), *Afonso = Constroi_aluno("Afonso", 3, 10, 10, 10), *Matheus = Constroi_aluno("Matheus", 3, 10, 10, 10), *Ariane = Constroi_aluno("Ariane", 3, 10,10,10);

  Arv *vazia = arv_criavazia();
  
  Arv *arvore = arv_cria(Joao, arv_cria(Talles, arv_cria(Celso, arv_cria(Bruno, vazia, vazia), arv_cria(Matheus, vazia, vazia)), vazia), arv_cria(Afonso, arv_cria(Ariane, vazia, vazia), vazia));

  Arv *arvoreCelso = arv_cria(Celso, arv_cria(Celso, arv_cria(Celso, arv_cria(Celso, vazia, vazia), arv_cria(Celso, vazia, vazia)), vazia), arv_cria(Celso, arv_cria(Celso, vazia, vazia), vazia));

  arv_imprime(arvore);
  printf("\nPai Celso: %s\n", Retorna_nome_aluno(info(arv_pai(arvore, "Celso"))));
  printf("\nArvore Celso:\nAltura: %d\nFolhas: %d\nCelsos: %d\n", altura(arvoreCelso), folhas(arvoreCelso), ocorrencias(arvoreCelso, "Celso"));

  imprimeCodigo(arvore);
}
