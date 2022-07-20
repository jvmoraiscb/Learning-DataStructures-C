/*
Implemente um TAD Lista Encadeada Genérica. Para testar a lista genérica, implemente um TAD de algum tipo específico,
por exemplo, um TAD Lista de Alunos (usando o TAD Genérico, é claro). Implemente um cliente final para testar seus TAD's.
Use suas implementações antigas de listas para agilizar o laboratório... 

BOA AULA!!! :-)
*/
#include <stdio.h>
#include <stdlib.h>
#include "../include/lista-aluno.h"

int main(){
    Lista_aluno* lista = Constroi_lista_aluno();

    Aluno* Joao = Constroi_aluno("Joao", 1, 10,10,10);
    Aluno* Talles = Constroi_aluno("Talles", 2, 10,10,10);
    Aluno* Celso = Constroi_aluno("Celso", 3, 10,10,10);
    Aluno* Bruno = Constroi_aluno("Bruno", 4, 10,10,10);

    Insere_lista_aluno(lista, Joao);
    Insere_lista_aluno(lista, Talles);
    Insere_lista_aluno(lista, Celso);
    Insere_lista_aluno(lista, Bruno);
    Imprime_lista_aluno(lista);
    printf("//--------------//\n\n");

    Retira_lista_aluno(lista, "Joao");
    Retira_lista_aluno(lista, "Celso");
    Retira_lista_aluno(lista, "Bruno");
    Imprime_lista_aluno(lista);
    printf("//--------------//\n\n");

    Insere_lista_aluno(lista, Celso);
    Insere_lista_aluno(lista, Bruno);
    Insere_lista_aluno(lista, Joao);
    Imprime_lista_aluno(lista);

    Destroi_lista_aluno(lista);
    Destroi_aluno(Joao);
    Destroi_aluno(Talles);
    Destroi_aluno(Celso);
    Destroi_aluno(Bruno);
    return 0;
}
