#if !defined(LISTA_ALUNO_H)
#define LISTA_ALUNO_H

#include "aluno.h"

typedef struct st_lista_aluno Lista_aluno;

Lista_aluno* Inicializa_lista_aluno();
void Destroi_lista_aluno(Lista_aluno* lista);
Lista_aluno* Insere_lista_aluno(Lista_aluno* lista, Aluno* aluno);
Lista_aluno* Remove_lista_aluno(Lista_aluno* lista, char* nome);
Lista_aluno* Encontra_lista_aluno(Lista_aluno* lista, char* nome);
void Imprime_lista_aluno_crescente(Lista_aluno* lista);
void Imprime_lista_aluno_decrescente(Lista_aluno* lista);

#endif // LISTA_ALUNO_H
