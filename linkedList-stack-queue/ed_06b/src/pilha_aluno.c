#define MAX 25 // Aloca 25 espacos por vez
#include "../include/pilha_aluno.h"

#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int tamanho;
    Aluno** alunos;
};


Pilha* Inicializa_pilha(){
    Pilha* pilha = malloc(sizeof(pilha));
    pilha->tamanho = 0;
    pilha->alunos= malloc(sizeof(Aluno*)*MAX);
    return pilha;
}
void Destroi_pilha(Pilha* pilha){
    if(pilha->tamanho > 0){
        Libera_pilha(pilha);
    }
    free(pilha);
}
void Libera_pilha(Pilha* pilha){
    int i, i_Max = pilha->tamanho;
    for(i=0; i<i_Max; i++){
        Pop_pilha(pilha);
    }
    free(pilha->alunos);
}
Aluno* Retorna_topo_pilha(Pilha* pilha){
    return pilha->alunos[pilha->tamanho-1];
}
int Retorna_tamanho_pilha(Pilha* pilha){
    return pilha->tamanho;
}
int Verifica_lista(Pilha* pilha){
    if(pilha->tamanho > 0){
        return 1;
    }
    return 0;
}
void Push_pilha(Pilha* pilha, int x){
    pilha->tamanho++;
    /* caso exceda o tamanho do vetor itens */
    if(pilha->tamanho % 25 == 1){
        pilha->itens = realloc(pilha->itens, sizeof(int)*(pilha->tamanho + 25));
    }
    pilha->itens[pilha->tamanho-1] = x;
}
int Pop_pilha(Pilha* pilha){
    int valor;
    if(Verifica_lista(pilha) == 1){
        valor = pilha->itens[pilha->tamanho-1];
        pilha->tamanho--;
        return valor;
    }
    return -1;
}

void Imprime_pilha(Pilha* pilha){
    int i;
    if(Verifica_lista(pilha) == 1){
        for(i=0; i<pilha->tamanho; i++){
            printf("%d ", pilha->itens[i]);
        }
        printf("\n");
    }
    else{
        printf("Lista vazia!\n");
    }
}