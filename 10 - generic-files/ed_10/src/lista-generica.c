#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista-generica.h"

typedef struct celula Celula;

struct celula{
    void* item;
    struct celula* prox;
};

struct lista{
    Celula* primeiro;
    Celula* ultimo;
};

// ----------------------------------FUNCOES INTERNAS----------------------------------//

Celula* Constroi_celula(void* item){
    Celula* celula = malloc(sizeof(Celula));
    celula->item = item;
    celula->prox = NULL;
    return celula;
}

void Destroi_celula(Celula* celula){
    free(celula);
}
// ----------------------------------FUNCOES EXTERNAS----------------------------------//

Lista* Constroi_lista(){
    Lista* lista = malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}
void Insere_item_lista(Lista* lista, void* item){
    Celula* newCel = Constroi_celula(item);
    /*CASO SEJA O PRIMEIRO DA LISTA*/
    if(lista->primeiro == NULL){
        lista->primeiro = newCel;
        lista->ultimo = lista->primeiro;
    }  
    else{
        lista->ultimo->prox = newCel;
        lista->ultimo = lista->ultimo->prox;
    }
}
int Retira_item_lista(Lista* lista, int(*Cmp)(void*, void*), void* chave){
    Celula* lista_temp = lista->primeiro;
    Celula* lista_temp_anterior = NULL;
    while(lista_temp != NULL && Cmp(lista_temp->item, chave) != 0){
        lista_temp_anterior = lista_temp;
        lista_temp = lista_temp->prox;
    }
    if(lista_temp != NULL){
        /*CASO SEJA O PRIMEIRO DA LISTA*/  
        if(lista_temp_anterior == NULL){
            lista->primeiro = lista_temp->prox;
            Destroi_celula(lista_temp);
        }
        /*CASO SEJA O ULTIMO DA LISTA*/
        else if(lista_temp->prox == NULL){
            lista->ultimo = lista_temp_anterior;
            lista_temp_anterior->prox = NULL;
            Destroi_celula(lista_temp);
        }
        /*CASO SEJA ENTRE*/
        else{
            lista_temp_anterior->prox = lista_temp->prox;
            Destroi_celula(lista_temp);
        }
        return 0;
    }
    return 1;
}
void Percorre_lista(Lista* lista, void(*fix_it)(void*)){
    Celula* lista_temp = lista->primeiro;
    Celula* lista_temp_prox = NULL;
    while(lista_temp != NULL){
        lista_temp_prox = lista_temp->prox;
        fix_it(lista_temp->item);
        lista_temp = lista_temp_prox;
    }
}
void Destroi_lista(Lista* lista){
    Celula* lista_temp = lista->primeiro;
    Celula* lista_temp_prox = NULL;
    while(lista_temp != NULL){
        lista_temp_prox = lista_temp->prox;
        Destroi_celula(lista_temp);
        lista_temp = lista_temp_prox;
    }
    free(lista);
}