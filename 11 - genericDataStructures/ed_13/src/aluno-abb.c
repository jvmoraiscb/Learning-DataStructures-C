#include "../include/aluno-abb.h"
#include <stdio.h>
#include <string.h>

static int cmp_matricula(void *mat1, void *mat2);
static int cmp_nome(void *nome1, void *nome2);
static int cmp_matricula_inserir(void *aluno, void *mat);
static int cmp_nome_inserir(void *aluno, void *nome);
static void print_aluno(void *item);

// busca um determinado aluno
Arv *arv_aluno_busca_matricula(Arv *r, int matricula){
    return arv_busca(r, cmp_matricula, (void*)&matricula);
}
Arv *arv_aluno_busca_nome(Arv *r, char* nome){
    return arv_busca(r, cmp_nome, (void*)nome);
}

// retira um determinado aluno
Arv *arv_aluno_retira_matricula(Arv *a, int matricula){
    return arv_retira(a, cmp_matricula, (void*)&matricula);
}
Arv *arv_aluno_retira_nome(Arv *a, char* nome){
    return arv_retira(a, cmp_nome, (void*)nome);
}

// insere um determinado aluno
Arv *arv_aluno_insere_nome(Arv *a, Aluno *aluno){
    return arv_insere(a, cmp_nome_inserir, (void*)aluno);
}
Arv *arv_aluno_insere_matricula(Arv *a, Aluno *aluno){
    return arv_insere(a, cmp_matricula_inserir, (void*)aluno);
}

// Cria uma árvore vazia
Arv *arv_aluno_criavazia(void){
    return arv_criavazia();
}

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_aluno_cria(Aluno *aluno, Arv *e, Arv *d){
    return arv_cria((void*)aluno, e, d);
}

// libera o espaço de memória ocupado pela árvore a
Arv *arv_aluno_libera(Arv *a){
    return arv_libera(a);
}

// retorna true se a árvore estiver vazia e false
// caso contrário
int arv_aluno_vazia(Arv *a){
    return arv_vazia(a);
}

// indica a ocorrência (1) ou não (0)
int arv_aluno_pertence_matricula(Arv *a, int matricula){
    return arv_pertence(a, cmp_matricula, (void*)&matricula);
}
int arv_aluno_pertence_nome(Arv *a, char* nome){
    return arv_pertence(a, cmp_nome, (void*)nome);
}

// imprime as informações dos nós da árvore
void arv_aluno_imprime(Arv *a){
    arv_imprime(a, print_aluno);
}

// imprime graphviz online
void arv_aluno_imprimeCodigo(Arv *arv){
    imprimeCodigo(arv, print_aluno);
}

// retorna a mãe de um dado no
Arv *arv_aluno_pai_matricula(Arv *a, int matricula){
    return arv_pai(a, cmp_matricula, (void*)&matricula);
}
Arv *arv_aluno_pai_nome(Arv *a, char *nome){
    return arv_pai(a, cmp_nome, (void*)nome);
}

// retorna a quantidade de folhas de uma arvore binaria
int arv_aluno_folhas(Arv *a){
    return folhas(a);
}

// retorna o numero de ocorrencias de uma informacao na arvore
int arv_aluno_ocorrencias_matricula(Arv *a, int matricula){
    return ocorrencias(a, cmp_matricula, (void*)&matricula);
}
int arv_aluno_ocorrencias_nome(Arv *a, char *nome){
    return ocorrencias(a, cmp_nome, (void*)nome);
}

// retorna o campo informacao de um dado no
Aluno *arv_aluno_info(Arv *a){
    return ((Aluno*)info(a));
}

// retorna a altura da árvore
int arv_aluno_altura(Arv *a){
    return altura(a);
}

static int cmp_matricula(void *mat1, void *mat2){
    int mat1temp = *((int*)mat1), mat2temp = *((int*)mat2);

    if(mat1temp > mat2temp)
        return 1;
    else if(mat1temp < mat2temp)
        return -1;
    else
        return 0;
}
static int cmp_nome(void *nome1, void *nome2){
    return strcmp((char*)nome1, (char*)nome2);
}
static int cmp_matricula_inserir(void *aluno, void *mat){
    int mat1temp = Retorna_matricula_aluno((Aluno*)aluno), mat2temp = *((int*)mat);

    if(mat1temp > mat2temp)
        return 1;
    else if(mat1temp < mat2temp)
        return -1;
    else
        return 0;
}
static int cmp_nome_inserir(void *aluno, void *nome){
    return strcmp(Retorna_nome_aluno((Aluno*)aluno), (char*)nome);
}
static void print_aluno(void *item){
    printf("%s", Retorna_nome_aluno((Aluno*)item));
}