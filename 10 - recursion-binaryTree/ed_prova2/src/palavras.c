// JOÃO VICTOR MORAIS COIMBRA DE BRITO

#include "../include/palavras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/abb.h"

#define MAX_PALAVRAS 512
#define MAX_PALAVRA 128

static void ordena_palavras(Palavras* palavras);
static void insere_ocorrencias(Arv* a, Palavras* palavras);
static void insere_palavras(Arv* a, Palavras* palavras);
static void insere_palavra(Palavras *palavras, char *palavra);
static int verifica_palavra(Palavras *palavras, char *palavra);

struct palavra{
    char palavra[MAX_PALAVRA];
    int ocorrencias;
};

struct palavras{
    struct palavra palavras[MAX_PALAVRAS];
    int qtd_palavras;
    int qtd_palavras_total;

};

Palavras * constroi_palavras(char* fileName){
    Arv * arv_palavras = arv_criavazia();
    FILE * file = fopen(fileName, "r");
    if(file == NULL){
        printf("ERRO: ARQUIVO NAO ENCONTRADO!\n");
        exit(1);
    }
    char palavra[128];
    while(fscanf(file,"%s", palavra) != EOF){
        arv_palavras = arv_insere(arv_palavras, palavra);
    }
    fclose(file);

    Palavras* palavras = malloc(sizeof(Palavras));
    palavras->qtd_palavras = 0;
    palavras->qtd_palavras_total = 0;
    insere_palavras(arv_palavras, palavras);
    insere_ocorrencias(arv_palavras, palavras);
    ordena_palavras(palavras);

    arv_libera(arv_palavras);
    
    return palavras;
}

void constroi_saida(char* fileName, Palavras* palavras){
    FILE * saida = fopen(fileName, "w");
    int i;
    for(i = 0; i<palavras->qtd_palavras; i++){
        fprintf(saida, "%s %d\n", palavras->palavras[i].palavra, palavras->palavras[i].ocorrencias);
    }
    fprintf(saida, "------------------------\n");
    fprintf(saida, "%d palavras distintas encontradas\n", palavras->qtd_palavras);
    fprintf(saida, "%d palavras no total\n", palavras->qtd_palavras_total);
    fprintf(saida, "%s é a palavra de maior frequencia (%d)\n", palavras->palavras[palavras->qtd_palavras - 1].palavra, palavras->palavras[palavras->qtd_palavras - 1].ocorrencias);
    fclose(saida);
}

void destroi_palavras(Palavras* palavras){
    free(palavras);
}

void imprime_palavras(Palavras *palavras){
    int i;
    for(i = 0; i<palavras->qtd_palavras; i++){
        printf("%s %d\n", palavras->palavras[i].palavra, palavras->palavras[i].ocorrencias);
    }
    printf("----------------------------\n");
    printf("%d palavras distintas encontradas\n", palavras->qtd_palavras);
    printf("%d palavras no total\n", palavras->qtd_palavras_total);
    printf("%s é a palavra de maior frequencia (%d)\n", palavras->palavras[palavras->qtd_palavras - 1].palavra, palavras->palavras[palavras->qtd_palavras - 1].ocorrencias);
}

static void ordena_palavras(Palavras* palavras){
    int i, j;
    for(i = 0; i<palavras->qtd_palavras; i++)
    {
        int lowerValue = palavras->palavras[i].ocorrencias;
        int i_lowerValue = 0;
        for(j = i+1; j<palavras->qtd_palavras; j++)
        {
            if (palavras->palavras[j].ocorrencias < lowerValue)
            {
                lowerValue = palavras->palavras[j].ocorrencias;
                i_lowerValue = j;
            }
        }
        if (lowerValue != palavras->palavras[i].ocorrencias)
        {
            Palavra palavra_temp = palavras->palavras[i];
            palavras->palavras[i] = palavras->palavras[i_lowerValue];
            palavras->palavras[i_lowerValue] = palavra_temp;
        }
    }
}

static void insere_ocorrencias(Arv* a, Palavras* palavras){
    int i;
    for(i = 0; i<palavras->qtd_palavras; i++){
        palavras->palavras[i].ocorrencias = ocorrencias(a, palavras->palavras[i].palavra);
    }
}

static void insere_palavras(Arv* a, Palavras* palavras){
  if (a != NULL)
  {
    insere_palavras(getSae(a), palavras);
    palavras->qtd_palavras_total += 1;
    if(!verifica_palavra(palavras, getPalavra(a)))
        insere_palavra(palavras, getPalavra(a));
    insere_palavras(getSad(a), palavras);
  }
}

static void insere_palavra(Palavras *palavras, char *palavra){
    Palavra nova_palavra;
    strcpy(nova_palavra.palavra, palavra);
    nova_palavra.ocorrencias = 0;

    palavras->palavras[palavras->qtd_palavras] = nova_palavra;
    palavras->qtd_palavras += 1;
}

static int verifica_palavra(Palavras *palavras, char *palavra){
    int i;
    for(i = 0; i < palavras->qtd_palavras; i++){
        if(!strcmp(palavras->palavras[i].palavra, palavra))
            return 1;
    }
    return 0;
}