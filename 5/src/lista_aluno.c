#include "../include/lista_aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_lista_aluno
{
    Aluno* aluno;
    Lista_aluno* prox;
    Lista_aluno* anterior;
};


Lista_aluno* Inicializa_lista_aluno(){
    return NULL;
}
void Destroi_lista_aluno(Lista_aluno* lista){
    if(lista == NULL){
        printf("ERRO: Lista vazia!\n");
        return;
    }
    Lista_aluno* lista_temp = lista;
    Lista_aluno* lista_temp_prox = NULL;
    /*PROCURA O ULTIMO ELEMENTO DA LISTA*/
    while(lista_temp != NULL){
        lista_temp_prox = lista_temp->prox;
        free(lista_temp);
        lista_temp = lista_temp_prox;
    }
}
Lista_aluno* Insere_lista_aluno(Lista_aluno* lista, Aluno* aluno){
    Lista_aluno* nova_lista = malloc(sizeof(Lista_aluno));
    nova_lista->aluno = aluno;
    nova_lista->prox = NULL;
    
    /*CASO A LISTA ESTEJA VAZIA*/
    if(lista == NULL){
        lista = nova_lista;
        lista->anterior = NULL;
    }
    else{
        Lista_aluno* lista_temp = lista;
        
        /*PROCURA O ULTIMO ELEMENTO DA LISTA*/
        while(lista_temp->prox != NULL){
            lista_temp = lista_temp->prox;
        }
        /*INSERE A NOVA LISTA*/
        lista_temp->prox = nova_lista;
        nova_lista->anterior = lista_temp;
    }
    return lista;
}
Lista_aluno* Remove_lista_aluno(Lista_aluno* lista, char* nome){
    Lista_aluno* lista_alvo = Encontra_lista_aluno(lista, nome);
    if(lista_alvo != NULL){
        /*CASO SEJA O UNICO DA LISTA*/
        if(lista_alvo->anterior == NULL && lista_alvo->prox == NULL){
            lista = NULL;
        }
        /*CASO SEJA O PRIMEIRO DA LISTA*/
        else if(lista_alvo->anterior == NULL){
            (lista_alvo->prox)->anterior = NULL;
            lista = lista_alvo->prox;
        }
        /*CASO SEJA O ULTIMO DA LISTA*/
        else if(lista_alvo->prox == NULL){
            (lista_alvo->anterior)->prox = NULL;
        }
        else{
            (lista_alvo->anterior)->prox = lista_alvo->prox;
            (lista_alvo->prox)->anterior = lista_alvo->anterior;
        }
    free(lista_alvo);
    }
    return lista;
}
Lista_aluno* Encontra_lista_aluno(Lista_aluno* lista, char* nome){
    Lista_aluno* lista_temp = lista;
    while(lista_temp != NULL && strcmp(Retorna_nome_aluno(lista_temp->aluno), nome) != 0){
        lista_temp = lista_temp->prox;
    }
    if(lista_temp == NULL){
        return NULL;
    }
    return lista_temp;
}
void Imprime_lista_aluno_crescente(Lista_aluno* lista){
    Lista_aluno* lista_temp = lista;
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome_aluno(lista_temp->aluno));
        lista_temp = lista_temp->prox;
    }
    printf("\n");
}
void Imprime_lista_aluno_decrescente(Lista_aluno* lista){
    Lista_aluno* lista_temp = lista;
    /*ENCONTRA ULTIMO DA LISTA*/
    while(lista_temp->prox != NULL){
        lista_temp = lista_temp->prox;
    }
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome_aluno(lista_temp->aluno));
        lista_temp = lista_temp->anterior;
    }
    printf("\n");
}