#include "../include/lista-aluno.h"
#include "../include/lista-generica.h"

#include <stdio.h>

Lista_aluno* Constroi_lista_aluno(){
    return Constroi_lista();
}
void Destroi_lista_aluno(Lista* lista){
    Destroi_lista(lista);
}
void Insere_lista_aluno(Lista* lista, Aluno* aluno){
    Insere_item_lista(lista, (void*)aluno);
}
int Retira_lista_aluno(Lista* lista, char* nome){
    return Retira_item_lista(lista, Cmp_nome_aluno, (void*)nome); 
}
void Imprime_lista_aluno(Lista* lista){
    Percorre_lista(lista, Imprime_aluno);
}