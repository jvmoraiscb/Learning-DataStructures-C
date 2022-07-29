//
//  arvore.h
//  Arvores
//
//  Created by Patricia Dockhorn Costa on 14/11/20.
//

#ifndef arvore_h
#define arvore_h

#include <stdio.h>
#include "aluno.h"

typedef struct arv Arv;

Arv *arv_busca(Arv *r, int chave);
Arv *arv_insere(Arv *a, Aluno *aluno);
Arv *arv_retira(Arv *a, int chave);

// Cria uma árvore vazia
Arv *arv_criavazia(void);

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_cria(Aluno *aluno, Arv *e, Arv *d);

// libera o espaço de memória ocupado pela árvore a
Arv *arv_libera(Arv *a);

// retorna true se a árvore estiver vazia e false
// caso contrário
int arv_vazia(Arv *a);

// indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence(Arv *a, char *nome);

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a);

// imprime graphviz online
void imprimeCodigo(Arv *arv);

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, char *nome);

// retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv *a);

// retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias(Arv *a, char *nome);

// retorna o campo informacao de um dado no
Aluno *info(Arv *a);

// retorna a altura da árvore
int altura(Arv *a);

#endif /* arvore_h */