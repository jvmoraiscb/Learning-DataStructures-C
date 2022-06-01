#include <stdio.h>
#include "aluno.h"
#include "../include/aluno.h"
#include "../include/lista_aluno.h"

int main(){
    Aluno* Joao = Constroi_aluno("Joao", 1, 10, 10, 10);
    Aluno* Talles = Constroi_aluno("Talles", 2, 1.5, 0, 0);
    Aluno* Bruno = Constroi_aluno("Bruno", 3, 10, 10, 10);
    Aluno* Celso = Constroi_aluno("Celso", 4, 10, 10, 10);

    Lista_aluno* lista = Inicializa_lista_aluno();
    lista = Insere_lista_aluno(lista, Joao);
    lista = Insere_lista_aluno(lista, Talles);
    lista = Insere_lista_aluno(lista, Bruno);
    lista = Insere_lista_aluno(lista, Celso);

    Imprime_lista_aluno_crescente(lista);
    printf("\n");
    Imprime_lista_aluno_decrescente(lista);

    lista = Remove_lista_aluno(lista, "Joao");
    lista = Remove_lista_aluno(lista, "Bruno");

    Imprime_lista_aluno_crescente(lista);
    printf("\n");
    Imprime_lista_aluno_decrescente(lista);

    Libera_aluno(Joao);
    Libera_aluno(Talles);
    Libera_aluno(Bruno);
    Libera_aluno(Celso);

    Destroi_lista_aluno(lista);
    return 0;
}