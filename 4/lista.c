#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    Aluno* aluno;
    Lista* next;
};

struct sentinela{
    Lista* first;
    Lista* last;
};

Sentinela* Constroi_sentinela(){
    Sentinela* sentinela = malloc(sizeof(Sentinela));
    sentinela->first = NULL;
    sentinela->last = NULL;
    return sentinela;
}
Lista* Constroi_lista(Aluno* aluno){
    Lista* lista = malloc(sizeof(Lista));
    lista->aluno = aluno;
    lista->next = NULL;
    return lista;
}
void Insere_aluno(Sentinela* sentinela, Aluno* aluno){
    Lista* lista_temp = NULL;
    if(sentinela->first == NULL){
        sentinela->first = Constroi_lista(aluno);
        sentinela->last = sentinela->first;
    }
    else{
        sentinela->last = Constroi_lista(aluno);
        lista_temp = sentinela->first;
        while(lista_temp != NULL){
            if(lista_temp->next == NULL){
                lista_temp->next = sentinela->last;
                break;
            }
            lista_temp = lista_temp->next;
        }
    }
}
void Retira_aluno(Sentinela* sentinela, char* nome){
    Lista* lista_temp = sentinela->first;
    Lista* lista_temp_anterior = NULL;
    while(lista_temp != NULL && strcmp(Retorna_nome(lista_temp->aluno), nome) != 0){
        lista_temp_anterior = lista_temp;
        lista_temp = lista_temp->next;
    }
    if(strcmp(Retorna_nome(lista_temp->aluno), nome) == 0){
        if(lista_temp_anterior == NULL){ //PRIMEIRO DA LISTA
            sentinela->first = lista_temp->next;
            Libera_lista(lista_temp);
        }
        else if(lista_temp->next == NULL){ //ULTIMO DA LISTA
            sentinela->last = lista_temp_anterior;
            lista_temp_anterior->next = NULL;
            Libera_lista(lista_temp);
        }
        else{
            lista_temp_anterior->next = lista_temp->next;
            Libera_lista(lista_temp);
        }
    }
}
void Imprime_aluno(Sentinela* sentinela){
    Lista* lista_temp = sentinela->first;
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome(lista_temp->aluno));
        lista_temp = lista_temp->next;
    }
    printf("\n");
}
void Libera_sentinela(Sentinela* sentinela){
    Lista* lista_temp = sentinela->first;
    Lista* lista_temp_next;
    while(lista_temp != NULL){
        lista_temp_next = lista_temp->next;
        Libera_lista(lista_temp);
        lista_temp = lista_temp_next;
    }
    free(sentinela);
}
void Libera_lista(Lista* lista){
    Libera_aluno(lista->aluno);
    free(lista);
}