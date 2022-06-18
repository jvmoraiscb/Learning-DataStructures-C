#include "Fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char* string;
    struct lista* prox;
}Lista;
/*Tipo que define a fila de strings (tipo opaco).
 * Esta fila NÃO tem limite de tamanho */
struct fila{
    Lista* inicio;
    Lista* final;
};
/*Cria uma fila vazia
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia */
Fila* criaFila(){
    Fila* fila = malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->final = NULL;
    if(fila != NULL){
        return fila;
    }
    printf("ERRO: Fila nao foi alocada!\n");
    return NULL;
}

Lista* criaLista(char* string){
    Lista* lista = malloc(sizeof(Lista));
    lista->prox = NULL;
    lista->string = string;
    return lista;
}

/*Insere uma string na fila (lembre-se, fila e' FIFO).
* inputs: string a ser inserida na fila (do tipo char*) e a fila
* output: nenhum
* pre-condicao: a string deve ter sido alocada dinamicamente!
* pos-condicao: fila contém string na ultima posição */
void insereFila (Fila* f, char* string){
    Lista* novoItem = criaLista(string);
    if(f->inicio == NULL){
        f->inicio = novoItem;
        f->final = novoItem;
    }
    else{
        f->final->prox = novoItem;
        f->final = novoItem;
    }
}

/*Retira uma string da fila (usando FIFO). Retorna NULL se vazia
* inputs: a fila
* output:a string do final (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila não nula (porém pode ser vazia)
* pos-condicao: fila não contém string que estava na ultima posição */
char* retiraFila (Fila* f){
    if(f == NULL){
        return NULL;
    }
    Lista* listaTemp = f->inicio;
    char* stringTemp = listaTemp->string;
    
    /*Caso seja o ultimo elemento da fila*/
    if(f->inicio->prox == NULL){
        f->inicio = NULL;
        f->final = NULL;
    }
    else{
        f->inicio = f->inicio->prox;
        if(f->inicio->prox == NULL){
            f->final = f->inicio;
        }
    }
    free(listaTemp);
    return stringTemp;
}

/*Verifica se a fila esta ou nao vazia
* inputs: a fila de strings
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila não eh nula
* pos-condicao: nenhuma */
int vaziaFila (Fila* f){
    if(f->inicio == NULL)
        return 1;
    return 0;
}

/*Imprime as strings da fila (do inicio ao fim da fila!).
* inputs: a fila de strings
* output: nenhum
* pre-condicao: fila não nula
* pos-condicao: strings são impressas na saida padrao
*/
void imprimeFila (Fila* f){
    Lista* listaTemp = f->inicio;
    while(listaTemp != NULL){
        printf("\t%s\n", listaTemp->string);
        listaTemp = listaTemp->prox;
    }
    printf("\n");
}

/*Libera toda a memoria alocada para a fila (use o valgrind)".
* inputs: a fila de strings (strings precisam ser alocadas dinamicamente)
* output: NULL
* pre-condicao: fila não nula
* pos-condicao: toda memoria alocada liberada (inclusive das strings)*/
Fila* liberaFila (Fila* f){
    Lista* listaTemp = f->inicio;
    Lista* proxListaTemp = NULL;
    while(listaTemp != NULL){
        proxListaTemp = listaTemp->prox;
        free(listaTemp->string);
        free(listaTemp);
        listaTemp = proxListaTemp;
    }
    free(f);
    return NULL;
}
