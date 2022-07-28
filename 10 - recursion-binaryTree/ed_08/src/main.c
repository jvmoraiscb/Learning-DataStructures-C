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
  Aluno *Joao = Constroi_aluno("Joao", 1, 10, 10, 10), *Talles = Constroi_aluno("Talles", 2, 10, 10, 10), *Celso = Constroi_aluno("Celso", 3, 10, 10, 10);

  Arv *arvore = arv_cria(Joao, arv_cria(Talles, arv_cria(Celso, arv_criavazia(), arv_criavazia()), arv_criavazia()), arv_criavazia());

  arv_imprime(arvore);
}