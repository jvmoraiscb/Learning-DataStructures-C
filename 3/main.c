// Joao Victor Morais - 12/05/2022
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    Matriz* mat1 = inicializaMatriz(3, 4);
    int x=1;
    for(int i=0; i<recuperaNLinhas(mat1); i++){
        for(int j=0; j<recuperaNColunas(mat1); j++){
            modificaElemento(mat1, i, j, x);
            x++;
        }
    }
    printf("Matriz:\n");
    imprimeMatriz(mat1);
    Matriz* mat2 = transposta(mat1);
    printf("Matriz transposta:\n");
    imprimeMatriz(mat2);
    Matriz* mat3 = multiplicacao(mat1, mat2);
    printf("Matriz x Matriz transposta:\n");
    imprimeMatriz(mat3);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);
    return 0;
}