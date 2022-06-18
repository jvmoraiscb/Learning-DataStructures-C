#if !defined(PILHA_H)
#define PILHA_H

#include "aluno.h"

typedef struct pilha Pilha;

Pilha* Inicializa_pilha();
void Destroi_pilha(Pilha* pilha);
void Libera_pilha(Pilha* pilha);
Aluno* Retorna_topo_pilha(Pilha* pilha);
int Retorna_tamanho_pilha(Pilha* pilha);
int Verifica_lista(Pilha* pilha);
void Push_pilha(Pilha* pilha, Aluno* aluno);
int Pop_pilha(Pilha* pilha);
void Imprime_pilha(Pilha* pilha);


#endif // PILHA_H