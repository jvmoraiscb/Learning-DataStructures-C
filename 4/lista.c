#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    Aluno* aluno;
    Lista* prox;
};

struct sentinela{
    Lista* primeiro;
    Lista* ultimo;
};

Sentinela* Constroi_sentinela(){
    Sentinela* sentinela = malloc(sizeof(Sentinela));
    sentinela->primeiro = NULL;
    sentinela->ultimo = NULL;
    return sentinela;
}
Lista* Constroi_lista(Aluno* aluno){
    Lista* lista = malloc(sizeof(Lista));
    lista->aluno = aluno;
    lista->prox = NULL;
    return lista;
}
void Insere_aluno(Sentinela* sentinela, Aluno* aluno){
    /*CASO SEJA O PRIMEIRO DA LISTA*/
    if(sentinela->primeiro == NULL){
        sentinela->primeiro = Constroi_lista(aluno);
        sentinela->ultimo = sentinela->primeiro;
    }  
    else{
        (sentinela->ultimo)->prox = Constroi_lista(aluno);
        sentinela->ultimo = (sentinela->ultimo)->prox;
    }
}
void Retira_aluno(Sentinela* sentinela, char* nome){
    Lista* lista_temp = sentinela->primeiro;
    Lista* lista_temp_anterior = NULL;
    while(lista_temp != NULL && strcmp(Retorna_nome(lista_temp->aluno), nome) != 0){
        lista_temp_anterior = lista_temp;
        lista_temp = lista_temp->prox;
    }
    if(strcmp(Retorna_nome(lista_temp->aluno), nome) == 0){
        /*CASO SEJA O PRIMEIRO DA LISTA*/  
        if(lista_temp_anterior == NULL){
            sentinela->primeiro = lista_temp->prox;
            Libera_lista(lista_temp);
        }
        /*CASO SEJA O ULTIMO DA LISTA*/
        else if(lista_temp->prox == NULL){
            sentinela->ultimo = lista_temp_anterior;
            lista_temp_anterior->prox = NULL;
            Libera_lista(lista_temp);
        }
        /*CASO SEJA ENTRE*/
        else{
            lista_temp_anterior->prox = lista_temp->prox;
            Libera_lista(lista_temp);
        }
    }
}
void Imprime_aluno(Sentinela* sentinela){
    Lista* lista_temp = sentinela->primeiro;
    if(lista_temp == NULL){
        printf("-\n");
    }
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome(lista_temp->aluno));
        lista_temp = lista_temp->prox;
    }
    printf("\n");
}
void Libera_sentinela(Sentinela* sentinela){
    Lista* lista_temp = sentinela->primeiro;
    Lista* lista_temp_prox;
    while(lista_temp != NULL){
        lista_temp_prox = lista_temp->prox;
        Libera_lista(lista_temp);
        lista_temp = lista_temp_prox;
    }
    free(sentinela);
}
void Libera_lista(Lista* lista){
    Libera_aluno(lista->aluno);
    free(lista);
}