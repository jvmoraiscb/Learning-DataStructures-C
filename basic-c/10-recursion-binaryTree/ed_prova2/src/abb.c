// JOÃO VICTOR MORAIS COIMBRA DE BRITO

#include "../include/abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv
{
  char *palavra;
  Arv *sae;
  Arv *sad;
};

// Cria uma árvore vazia
Arv *arv_criavazia(void)
{
  return NULL;
}

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_cria(char *palavra, Arv *e, Arv *d)
{
  Arv *newArv = malloc(sizeof(Arv));
  newArv->palavra = strdup(palavra);
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
    free(a->palavra);
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
int arv_pertence(Arv *a, char *palavra)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    return (strcmp(palavra, a->palavra) == 0 || arv_pertence(a->sae, palavra) || arv_pertence(a->sad, palavra));
  }
}

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a)
{
  if (!arv_vazia(a))
  {
    arv_imprime(a->sae);
    printf("%s\n", a->palavra);
    arv_imprime(a->sad);
  }
}

Arv *arv_busca(Arv *r, char* palavra)
{
  if (r == NULL)
    return NULL;
  else if (strcmp(palavra, r->palavra) < 0)
    return arv_busca(r->sae, palavra);
  else if (strcmp(palavra, r->palavra) > 0)
    return arv_busca(r->sad, palavra);
  else
    return r;
}

Arv *arv_insere(Arv *a, char *palavra)
{
  if (a == NULL)
  {
    a = malloc(sizeof(Arv));
    a->palavra = strdup(palavra);
    a->sae = NULL;
    a->sad = NULL;
  }
  else if (strcmp(palavra, a->palavra) < 0)
    a->sae = arv_insere(a->sae, palavra);
  else
    a->sad = arv_insere(a->sad, palavra);
  return a;
}

Arv *arv_retira(Arv *a, char* palavra)
{
  if (a == NULL)
    return NULL;
  else if (strcmp(palavra, a->palavra) < 0)
    a->sae = arv_retira(a->sae, palavra);
  else if (strcmp(palavra, a->palavra) > 0)
    a->sad = arv_retira(a->sad, palavra);
  else
  {
    // sem filhos (folha)
    if (a->sae == NULL && a->sad == NULL)
    {
      free(a);
      a = NULL;
    }
    // filho somente a esquerda
    else if (a->sad == NULL)
    {
      Arv *temp = a;
      a = a->sae;
      free(temp);
    }
    // filho somente a direita
    else if (a->sae == NULL)
    {
      Arv *temp = a;
      a = a->sad;
      free(temp);
    }
    // dois filhos
    else
    {
      // acha o antecessor do nó
      Arv *f = a->sae;
      while (f->sad != NULL)
        f = f->sad;
      // faz a troca das informações
      char *temp = a->palavra;
      a->palavra = f->palavra;
      f->palavra = temp;
      // chama recursivamente para o nó agora em alguma das situações anteriores
      a->sae = arv_retira(a->sae, palavra);
    }
  }
  return a;
}

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, char *palavra)
{
  if (arv_vazia(a))
  {
    return NULL;
  }
  else
  {
    if (a->sae != NULL && (!strcmp(a->sae->palavra, palavra)))
    {
      return a;
    }
    else if (a->sad != NULL && (!strcmp(a->sad->palavra, palavra)))
    {
      return a;
    }
    else
    {
      Arv *sae = arv_pai(a->sae, palavra);
      Arv *sad = arv_pai(a->sad, palavra);
      if (sae != NULL)
      {
        return sae;
      }
      else if (sad != NULL)
      {
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
int ocorrencias(Arv *a, char *palavra)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    if (!strcmp(a->palavra, palavra))
    {
      return (1 + ocorrencias(a->sae, palavra) + ocorrencias(a->sad, palavra));
    }
    return (ocorrencias(a->sae, palavra) + ocorrencias(a->sad, palavra));
  }
}

// retorna o campo informacao de um dado no
char* info(Arv *a)
{
  return a->palavra;
}

int altura(Arv *a)
{
  if (a == NULL)
  {
    return -1;
  }
  else
  {
    int sae = altura(a->sae);
    int sad = altura(a->sad);
    if (sae > sad)
    {
      return 1 + sae;
    }
    else
    {
      return 1 + sad;
    }
  }
}

char* getPalavra(Arv* arv){
    return arv->palavra;
}

Arv* getSae(Arv* arv){
    return arv->sae;
}

Arv* getSad(Arv* arv){
    return arv->sad;
}