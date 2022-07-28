#include "../include/arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv
{
  Aluno *aluno;
  Arv *sae;
  Arv *sad;
};

static void imprimeArvore (Arv* arv);

// Cria uma árvore vazia
Arv *arv_criavazia(void)
{
  return NULL;
}

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_cria(Aluno *aluno, Arv *e, Arv *d)
{
  Arv *newArv = malloc(sizeof(Arv));
  newArv->aluno = aluno;
  newArv->sae = e;
  newArv->sad = d;
  return newArv;
}

// libera o espaço de memória ocupado pela árvore a
Arv *arv_libera(Arv *a)
{
  if (!arv_vazia(a))
  {
    arv_libera(a->sae);
    arv_libera(a->sad);
    free(a);
  }
  return NULL;
}

// retorna true se a árvore estiver vazia e false
// caso contrário
int arv_vazia(Arv *a)
{
  return (a == NULL);
}

// indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence(Arv *a, char *nome)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    return (strcmp(Retorna_nome_aluno(a->aluno), nome) == 0 || arv_pertence(a->sae, nome) || arv_pertence(a->sad, nome));
  }
}

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a)
{
  if (!arv_vazia(a))
  {
    printf("%s\n", Retorna_nome_aluno(a->aluno));
    arv_imprime(a->sae);
    arv_imprime(a->sad);
  }
}

void imprimeCodigo(Arv* arv){
    printf("\nstrict graph{\n");
    imprimeArvore(arv);
    printf("}\n");
    return;
}

static void imprimeArvore (Arv* arv){
    
    if(arv != NULL){
        if(arv->sae!=NULL){
        printf("%s -- %s\n",Retorna_nome_aluno(arv->aluno),Retorna_nome_aluno(arv->sae->aluno));
        }
        if(arv->sad!=NULL){
        printf("%s -- %s\n",Retorna_nome_aluno(arv->aluno),Retorna_nome_aluno(arv->sad->aluno));
        }
        imprimeArvore(arv->sae);
        imprimeArvore(arv->sad);
    }
    return;
}

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, char *nome)
{
  if (arv_vazia(a))
  {
    return NULL;
  }
  else
  {
    if(a->sae != NULL && (!strcmp(Retorna_nome_aluno(a->sae->aluno), nome))){
      return a;
    }
    else if (a->sad != NULL && (!strcmp(Retorna_nome_aluno(a->sad->aluno), nome))){
      return a;
    }
    else{
      Arv *sae = arv_pai(a->sae, nome);
      Arv *sad = arv_pai(a->sad, nome);
      if(sae != NULL){
        return sae;
      }
      else if(sad != NULL){
        return sad;
      }
    }
  }
  return NULL;
}

// retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv *a)
{
  if (a == NULL)
  {
    return 0;
  }
  else if (a->sae == NULL && a->sad == NULL)
  {
    return 1;
  }
  else
  {
    return (folhas(a->sae) + folhas(a->sad));
  }
}

// retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias(Arv *a, char *nome)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    if(!strcmp(Retorna_nome_aluno(a->aluno), nome)){
      return (1 + ocorrencias(a->sae, nome) + ocorrencias(a->sad, nome));
    }
    return (ocorrencias(a->sae, nome) + ocorrencias(a->sad, nome));
  }
}

// retorna o campo informacao de um dado no
Aluno *info(Arv *a)
{
  return a->aluno;
}

int altura(Arv *a){
  if(a==NULL){
    return -1;
  }
  else{
    int sae = altura(a->sae);
    int sad = altura(a->sad);
    if(sae > sad){
      return 1 + sae;
    }
    else{
      return 1+ sad;
    }
  }
}