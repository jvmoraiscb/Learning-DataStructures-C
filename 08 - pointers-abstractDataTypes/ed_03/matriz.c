// Joao Victor Morais - 12/05/2022
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int l;
    int c;
    int **mat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    if(nlinhas == 0 || ncolunas == 0){
        printf("ERRO! LINHA OU COLUNA INVALIDA\n");
        return NULL;
    }
    Matriz* matriz = malloc(sizeof(Matriz));
    matriz->l = nlinhas;
    matriz->c = ncolunas;
    matriz->mat = malloc(sizeof(int*)*nlinhas);
    for(int i=0; i<nlinhas;i++){
        matriz->mat[i] = malloc(sizeof(int)*ncolunas);
    }

    for(int i=0; i<(matriz->l); i++){
        for(int j=0; j<(matriz->c); j++){
            matriz->mat[i][j] = 0;
        }
    }

    return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return;
    }
    if(linha > (mat->l) || linha < 0 || coluna > (mat->c) || coluna < 0){
        printf("ERRO! LINHA OU COLUNA INVALIDA\n");
        return;
    }
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return 1;
    }
    if(linha > (mat->l) || linha < 0 || coluna > (mat->c) || coluna < 0){
        printf("ERRO! LINHA OU COLUNA INVALIDA\n");
        return 1;
    }

    return mat->mat[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return 1;
    }
    
    return mat->c;
}

int recuperaNLinhas (Matriz* mat){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return 1;
    }
    
    return mat->l;
}

Matriz* transposta (Matriz* mat){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return NULL;
    }

    Matriz* mat_trans = inicializaMatriz(mat->c, mat->l);

    for(int i=0; i<mat->l;i++){
        for(int j=0; j<mat->c; j++){
            mat_trans->mat[j][i] = mat->mat[i][j];
        }
    }

    return mat_trans;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1 == NULL || mat2 == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return NULL;
    }
    if(mat1->c != mat2->l){
        printf("ERRO! ESSAS MATRIZES NAO PODEM SER MULTIPLICADAS\n");
        return NULL;
    }

    Matriz* mat_mult = inicializaMatriz(mat1->l, mat2->c);

    int i, j, x, aux = 0;
    for(i=0; i<mat_mult->l; i++){
        for(j=0; j<mat_mult->c; j++){
            for(x=0; x<mat1->c; x++){
                aux += mat1->mat[i][x] * mat2->mat[x][j];
            }
            mat_mult->mat[i][j] = aux;
            aux = 0;    
        }
    }

    return mat_mult;
}

void imprimeMatriz(Matriz* mat){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return;
    }

    for(int i=0; i<(mat->l); i++){
        for(int j=0; j<(mat->c); j++){
            printf("%d ", recuperaElemento(mat, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

void destroiMatriz(Matriz* mat){
    if(mat == NULL){
        printf("ERRO! MAT NAO EXISTE\n");
        return;
    }
    for(int i=0; i<mat->l; i++){
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}