#ifndef generic_abb
#define generic_abb

typedef struct arv Arv;

// cria uma árvore vazia
Arv *arv_criavazia(void);

// cria uma árvore com a informação do nó raiz c, e
// com subárvore esquerda e e subárvore direita d
Arv *arv_cria(void *item, Arv *e, Arv *d);

// libera o espaço de memória ocupado pela árvore a
Arv *arv_libera(Arv *a);

// retorna true se a árvore estiver vazia e false
// caso contrário
int arv_vazia(Arv *a);

// indica a ocorrência (1) ou não (0) do item chave
int arv_pertence(Arv *a, int(*cmp_func)(void*, void*), void *chave);

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a, void(*print_func)(void*));

// busca um determinado item
Arv *arv_busca(Arv *r, int(*cmp_func)(void*, void*), void *chave);

// insere um determinado item
Arv *arv_insere(Arv *a, int(*cmp_func)(void*, void*), void *item);

// retira um determinado item
Arv *arv_retira(Arv *a, int(*cmp_func)(void*, void*), void* chave);

// imprime graphviz online
void imprimeCodigo(Arv *arv, void(*print_func)(void*));

// retorna a mãe de um dado no
Arv *arv_pai(Arv *a, int(*cmp_func)(void*, void*), void *chave);

// retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv *a);

// retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias(Arv *a, int(*cmp_func)(void*, void*), void *chave);

// retorna o campo informacao de um dado no
void *info(Arv *a);

// retorna a altura da árvore
int altura(Arv *a);

#endif /* generic_abb */