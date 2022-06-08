#include "../include/pilha.h"

#include <stdio.h>

int main(){
    Pilha* pilha = Inicializa_pilha();

    int i;
    for(i=1; i<27; i++){
        Push_pilha(pilha, i);
    }
    Imprime_pilha(pilha);
    for(i=0; i<5; i++){
        Pop_pilha(pilha);
    }
    Imprime_pilha(pilha);
    for(i=1; i<7; i++){
        Push_pilha(pilha, i);
    }
    Imprime_pilha(pilha);
    Libera_pilha(pilha);
    Imprime_pilha(pilha);
    for(i=1; i<10; i++){
        Push_pilha(pilha, i);
    }
    Imprime_pilha(pilha);
    Destroi_pilha(pilha);
}