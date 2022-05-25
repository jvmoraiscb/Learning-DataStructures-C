#if !defined(LISTA_H)
#define LISTA_H

#include "aluno.h"

typedef struct sentinela Sentinela;
typedef struct lista Lista;

Sentinela* Constroi_sentinela();
Lista* Constroi_lista(Aluno* aluno);
void Insere_aluno(Sentinela* sentinela, Aluno* aluno);
void Retira_aluno(Sentinela* sentinela, char* nome);
void Imprime_aluno(Sentinela* sentinela);
void Libera_sentinela(Sentinela* sentinela);
void Libera_lista(Lista* lista);

#endif // LISTA_H
