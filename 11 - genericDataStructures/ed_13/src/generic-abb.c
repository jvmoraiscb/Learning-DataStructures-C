#include "../include/generic-abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv
{
  void *item;
  Arv *sae;
  Arv *sad;
};

static void imprimeArvore(Arv *arv, void(*print_func)(void*));

// Cria uma árvore vazia
Arv *arv_criavazia(void)
{
  return NULL;
}

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_cria(void *item, Arv *e, Arv *d)
{
  Arv *newArv = malloc(sizeof(Arv));
  newArv->item = item;
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
int arv_pertence(Arv *a, int(*cmp_func)(void*, void*), void *chave)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    return (cmp_func(a->item, chave) == 0 || arv_pertence(a->sae, cmp_func, chave) || arv_pertence(a->sad, cmp_func, chave));
  }
}

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a, void(*print_func)(void*))
{
  if (!arv_vazia(a))
  {
    arv_imprime(a->sae, print_func);
    print_func(a->item);
    arv_imprime(a->sad, print_func);
  }
}

Arv *arv_busca(Arv *r, int(*cmp_func)(void*, void*), void *chave)
{
  if (r == NULL)
    return NULL;
  else if (cmp_func(chave, r->item) < 0)
    return arv_busca(r->sae, cmp_func, chave);
  else if (cmp_func(chave, r->item) > 0)
    return arv_busca(r->sad, cmp_func, chave);
  
  return r;
}

Arv *arv_insere(Arv *a, int(*cmp_func)(void*, void*), void *item)
{
  if (a == NULL)
  {
    a = malloc(sizeof(Arv));
    a->item = item;
    a->sae = NULL;
    a->sad = NULL;
  }
  else if (cmp_func(item, a->item) < 0)
    a->sae = arv_insere(a->sae, cmp_func, item);
  else
    a->sad = arv_insere(a->sad, cmp_func, item);
  return a;
}

Arv *arv_retira(Arv *a, int(*cmp_func)(void*, void*), void* chave)
{
  if (a == NULL)
    return NULL;
  else if (cmp_func(chave, a->item) < 0)
    a->sae = arv_retira(a->sae, cmp_func, chave);
  else if (cmp_func(chave, a->item) > 0)
    a->sad = arv_retira(a->sad, cmp_func, chave);
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
      void *temp = a->item;
      a->item = f->item;
      f->item = temp;
      // chama recursivamente para o nó agora em alguma das situações anteriores
      a->sae = arv_retira(a->sae, cmp_func, chave);
    }
  }
  return a;
}

void imprimeCodigo(Arv *arv, void(*print_func)(void*))
{
  printf("\nstrict graph{\n");
  imprimeArvore(arv, print_func);
  printf("}\n");
  return;
}

static void imprimeArvore(Arv *arv, void(*print_func)(void*))
{

  if (arv != NULL)
  {
    if (arv->sae != NULL)
    {
      print_func(arv->item);
      printf(" -- ");
      print_func(arv->sae->item);
      printf("\n");
    }
    if (arv->sad != NULL)
    {
      print_func(arv->item);
      printf(" -- ");
      print_func(arv->sad->item);
      printf("\n");
    }
    imprimeArvore(arv->sae, print_func);
    imprimeArvore(arv->sad, print_func);
  }
  return;
}

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, int(*cmp_func)(void*, void*), void *chave)
{
  if (arv_vazia(a))
  {
    return NULL;
  }
  else
  {
    if (a->sae != NULL && (!cmp_func(a->sae->item, chave)))
    {
      return a;
    }
    else if (a->sad != NULL && (!cmp_func(a->sad->item, chave)))
    {
      return a;
    }
    else
    {
      Arv *sae = arv_pai(a->sae, cmp_func, chave);
      Arv *sad = arv_pai(a->sad, cmp_func, chave);
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
int ocorrencias(Arv *a, int(*cmp_func)(void*, void*), void *chave)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    if (!cmp_func(a->item, chave))
    {
      return (1 + ocorrencias(a->sae, cmp_func, chave) + ocorrencias(a->sad, cmp_func, chave));
    }
    return (ocorrencias(a->sae, cmp_func, chave) + ocorrencias(a->sad, cmp_func, chave));
  }
}

// retorna o campo informacao de um dado no
void *info(Arv *a)
{
  return a->item;
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