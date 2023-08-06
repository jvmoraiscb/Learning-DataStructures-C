#ifndef arvore_h
#define arvore_h

#include "aluno.h"
#include "generic-abb.h"

typedef Arv Arv_aluno;

// busca um determinado aluno
Arv *arv_aluno_busca_matricula(Arv *r, int matricula);
Arv *arv_aluno_busca_nome(Arv *r, char* nome);

// retira um determinado aluno
Arv *arv_aluno_retira_matricula(Arv *a, int matricula);
Arv *arv_aluno_retira_nome(Arv *a, char* nome);

// insere um determinado aluno
Arv *arv_aluno_insere_matricula(Arv *a, Aluno *aluno);
Arv *arv_aluno_insere_nome(Arv *a, Aluno *aluno);

// Cria uma árvore vazia
Arv *arv_aluno_criavazia(void);

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_aluno_cria(Aluno *aluno, Arv *e, Arv *d);

// libera o espaço de memória ocupado pela árvore a
Arv *arv_aluno_libera(Arv *a);

// retorna true se a árvore estiver vazia e false
// caso contrário
int arv_aluno_vazia(Arv *a);

// indica a ocorrência (1) ou não (0)
int arv_aluno_pertence_matricula(Arv *a, int matricula);
int arv_aluno_pertence_nome(Arv *a, char* nome);

// imprime as informações dos nós da árvore
void arv_aluno_imprime(Arv *a);

// imprime graphviz online
void arv_aluno_imprimeCodigo(Arv *arv);

// retorna a mãe de um dado no
Arv *arv_aluno_pai_matricula(Arv *a, int matricula);
Arv *arv_aluno_pai_nome(Arv *a, char *nome);

// retorna a quantidade de folhas de uma arvore binaria
int arv_aluno_folhas(Arv *a);

// retorna o numero de ocorrencias de uma informacao na arvore
int arv_aluno_ocorrencias_matricula(Arv *a, int matricula);
int arv_aluno_ocorrencias_nome(Arv *a, char *nome);

// retorna o campo informacao de um dado no
Aluno *arv_aluno_info(Arv *a);

// retorna a altura da árvore
int arv_aluno_altura(Arv *a);

#endif /* arvore_h */