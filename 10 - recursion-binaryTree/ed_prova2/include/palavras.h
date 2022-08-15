// JOÃO VICTOR MORAIS COIMBRA DE BRITO

#ifndef PALAVRAS_H
#define PALAVRAS_H

typedef struct palavras Palavras;
typedef struct palavra Palavra;

Palavras * constroi_palavras(char* fileName);
void constroi_saida(char* fileName, Palavras* palavras);
void destroi_palavras(Palavras* palavras);
void imprime_palavras(Palavras *palavras);

#endif