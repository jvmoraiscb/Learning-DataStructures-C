// JOÃO VICTOR MORAIS COIMBRA DE BRITO

#ifndef ABB_H
#define ABB_H

#include <stdio.h>

typedef struct arv Arv;

Arv *arv_busca(Arv *r, char* palavra);
Arv *arv_insere(Arv *a, char *palavra);
Arv *arv_retira(Arv *a, char *palavra);

// Cria uma árvore vazia
Arv *arv_criavazia(void);

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_cria(char *palavra, Arv *e, Arv *d);

// libera o espaço de memória ocupado pela árvore a
Arv *arv_libera(Arv *a);

// retorna true se a árvore estiver vazia e false
// caso contrário
int arv_vazia(Arv *a);

// indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence(Arv *a, char *nome);

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a);

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, char *nome);

// retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv *a);

// retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias(Arv *a, char *nome);

// retorna o campo informacao de um dado no
char *info(Arv *a);

// retorna a altura da árvore
int altura(Arv *a);

// getters
char* getPalavra(Arv* arv);
Arv* getSae(Arv* arv);
Arv* getSad(Arv* arv);

#endif /* arvore_h */