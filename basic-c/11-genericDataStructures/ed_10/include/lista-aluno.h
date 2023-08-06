#if !defined(LISTA_ALUNO_H)
#define LISTA_ALUNO_H

#include "aluno.h"
#include "lista-generica.h"

typedef Lista Lista_aluno;

Lista_aluno* Constroi_lista_aluno();
void Destroi_lista_aluno(Lista* lista);
void Insere_lista_aluno(Lista* lista, Aluno* aluno);
int Retira_lista_aluno(Lista* lista, char* nome);
void Imprime_lista_aluno(Lista* lista);

#endif // LISTA_ALUNO_H