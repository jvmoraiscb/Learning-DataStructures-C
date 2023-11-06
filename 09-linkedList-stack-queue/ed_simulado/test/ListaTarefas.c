#include "ListaTarefas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"
/*Tipo que define a Tarefa (tipo opaco)
 * Uma tarefa deve ter um nome e uma fila de procedimentos (fila sem limite de tamanho)
 * O fila.h a ser implementada também é fornecido
 * */
struct tarefa{
    char* nome;
    Fila* procedimentos;
};

typedef struct celulaLista{
    Tarefa *tarefa;
    struct celulaLista *prox, *anterior;
}CelulaLista;

/*Tipo que define a Lista de Tarefas (tipo opaco)
 * Defina uma lista encadeada
 * */
struct listatarefas{
    CelulaLista *primeiro, *ultimo;
};


/*------------ funcoes relacionadas a tarefa e procedimentos -----------*/

/*Cria uma tarefa vazia, com uma fila de procedimentos vazia
* inputs: nome da tarefa (char*). Esta função deve alocar dinamicamente o nome da tarefa.
* output: tarefa alocada e vazia, com fila de procedimentos ainda vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia,  */
Tarefa* criaTarefa(char* nome){
    Tarefa* tarefa = malloc(sizeof(Tarefa));
    tarefa->nome = strdup(nome);
    tarefa->procedimentos = criaFila();
    return tarefa;
}

/*Insere um procedimento na fila de procedimentos de uma tarefa
* inputs: Endereço da tarefa e a string que define o procedimento. Esta função deve alocar dinamicamente esta string.
* output: nao tem
* pre-condicao:tarefa e procedimento nao nulos
* pos-condicao: procedimento inserido na ultima posicao da fila de procedimentos desta tarefa */
void insereProcedimentoTarefa (Tarefa* tarefa, char* procedimento){
    insereFila(tarefa->procedimentos, strdup(procedimento));
}

/*------------ funcoes relacionadas a lista de tarefas -----------*/

/* Cria uma lista de tarefas vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nao tem
* pos-condicao: lista alocada e vazia,  */
ListaTarefas* criaListaTarefas (){
    ListaTarefas *listaTarefas = malloc(sizeof(ListaTarefas));
    listaTarefas->primeiro = NULL;
    listaTarefas->ultimo = NULL;
    return listaTarefas;
}

/* Insere uma tarefa na PRIMEIRA posicao da lista de tarefas.
* inputs: a lista de tarefas e a tarefa a ser inserida
* output: nao tem
* pre-condicao: lista e tarefa nao nulas
* pos-condicao: tarefa incluida na primeira posicao da lista*/
void insereTarefaLista (ListaTarefas* lista, Tarefa* tarefa){
    CelulaLista *celula = malloc(sizeof(CelulaLista));
    celula->tarefa = tarefa;
    celula->anterior = NULL; 
    if(lista->primeiro == NULL){
        lista->primeiro = celula;
        lista->ultimo = celula;
        celula->prox = NULL;
    }
    else{
        lista->primeiro->anterior = celula;
        celula->prox = lista->primeiro;
        lista->primeiro = celula;
    }
}


/* Retira uma determinada tarefa da lista de tarefas e a retorna.
* inputs: a lista de tarefas e o nome da tarefa a ser retirada
* output: Endereco da tarefa retirada
* pre-condicao: lista e nome nao nulos
* pos-condicao: tarefa retirada da lista e ponteiros da lista ficam consistentes */
Tarefa* retiraTarefaLista (ListaTarefas* lista, char* nome){
    Tarefa *tarefaAlvo = NULL;
    CelulaLista *listaTemp = lista->primeiro;
    while(listaTemp != NULL && strcmp(listaTemp->tarefa->nome, nome) != 0){
        listaTemp = listaTemp->prox;
    }
    if(listaTemp == NULL){
        //printf("Tarefa nao encontrada!\n");
        return NULL;
    }
    else{
        tarefaAlvo = listaTemp->tarefa;
        if(listaTemp->prox == NULL && listaTemp->anterior == NULL){
            lista->primeiro = NULL;
            lista->ultimo = NULL;
        }
        else if(listaTemp->anterior == NULL){
            lista->primeiro = listaTemp->prox;
            listaTemp->anterior = NULL;
        }
        else if(listaTemp->prox == NULL){
            lista->ultimo = listaTemp->anterior;
            listaTemp->prox = NULL;
        }
        else{
            listaTemp->anterior->prox = listaTemp->prox;
            listaTemp->prox->anterior = listaTemp->anterior;
        }
        free(listaTemp);
        return tarefaAlvo;
    }
}

/* Imprime a lista de tarefas e todos os procedimentos de cada tarefa.
 * (Formato: Nome da Tarefa: EstudarProvaED.
 *           Procedimentos: Pegar material no site
 *                           Baixar os slides
 *                           Refazer todos os labs
 * )
* inputs: a lista de tarefas
* output: nao tem
* pre-condicao: lista nao nula
* pos-condicao: tarefas e procedimentos impressos na saida padrao */
void imprimeListaTarefas (ListaTarefas* lista){
    CelulaLista *listaTemp = lista->primeiro;
    while(listaTemp != NULL){
        printf("Nome da Tarefa: %s\n", listaTemp->tarefa->nome);
        printf("Procedimentos: \n");
        imprimeFila(listaTemp->tarefa->procedimentos);
        listaTemp = listaTemp->prox;
    }
    /*
    printf("\n\n");
    listaTemp = lista->primeiro;
    while(listaTemp->prox != NULL){
        listaTemp = listaTemp->prox;
    }
    while(listaTemp != NULL){
        printf("Nome da Tarefa: %s\n", listaTemp->tarefa->nome);
        printf("Procedimentos: \n");
        imprimeFila(listaTemp->tarefa->procedimentos);
        listaTemp = listaTemp->anterior;
    }
    */
}

/* Libera toda a memoria alocada (use valgrind)!
* inputs: a lista de tarefas
* output: NULL
* pre-condicao: lista nao nula
* pos-condicao: toda a memoria eh liberada, inclusive das strings e dos procedimentos. */
ListaTarefas* liberaListaTarefas(ListaTarefas* lista){
    CelulaLista *listaTemp = lista->primeiro;
    CelulaLista *listaTempProx = NULL;
    while(listaTemp != NULL){
        listaTempProx = listaTemp->prox;
        liberaFila(listaTemp->tarefa->procedimentos);
        free(listaTemp->tarefa->nome);
        free(listaTemp->tarefa);
        free(listaTemp);
        listaTemp = listaTempProx;
    }
    free(lista);
    return NULL;
}