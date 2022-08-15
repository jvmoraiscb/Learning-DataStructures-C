// JOÃO VICTOR MORAIS COIMBRA DE BRITO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/palavras.h"


int main()
{
    Palavras* palavras = constroi_palavras("entrada.txt");
    //imprime_palavras(palavras);
    constroi_saida("saida.txt", palavras);
    destroi_palavras(palavras);
    return 0;
}