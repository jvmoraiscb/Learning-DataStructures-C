/* 
Problema: (BOCA: P3_2018_Q4_a) Faça um programa que leia uma lista com um
número par de palavras e analise cada par de palavras consecutivas (ex. palavra 0
com a 1, a 2 com a 3, a 4 com a 5, etc.). O programa deverá imprimir uma lista de
palavras resultantes contendo a maior palavra de cada par, ou não imprimir
nenhuma das palavras do par se elas forem de tamanhos iguais. Por fim, o programa
deverá imprimir a primeira ocorrência da palavra de maior tamanho da lista de
palavras resultante, ou imprimir “--” caso não haja uma palavra nessa lista.
• Entrada: Uma lista com um número par de palavras, sendo uma em cada linha. As palavras
não conterão espaço, e podem conter caracteres que não são letras.
• Saída: A saída será composta por uma lista de palavras resultante, sendo uma palavra em
cada linha e uma palavra para cada par de palavras da entrada que tenha uma palavra
maior do que a outra. Além disso, a última linha apresentará a primeira ocorrência da maior
palavra da lista de palavras resultante (ex. “MAX:DonaFlorinda”), ou “--” caso não haja
palavras na lista de palavras resultantes (ex. “MAX:--”). Veja a formatação nos exemplos
abaixo.
OBS: Pode utilizar a biblioteca string.h. Não precisa utilizar ou separar em tipos.
• Exemplo de Entrada:
TripaSeca
QuasiNada
SeuMadruga
DonaFlorinda
ChapoLiiiiin
ElChapo
Test123
Teeest123
TripaSeca
QuasiNada
DonaFlorinda
ChapoLiiiiin
ElChapo
Test123
SeuMadruga
DonaFlor
ChapoLiiiiin
ElChapo
Test123
Teeest123
• Exemplo de Saída:
DonaFlorinda
ChapoLiiiiin
Teeest123
MAX:DonaFlorinda
MAX:--
SeuMadruga
ChapoLiiiiin
Teeest123
MAX:ChapoLiiiiin
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char palavra[100];

} tTexto;


int main()
{
    int i = 0;
    tTexto palavras[100], palavraAtual;

    while(scanf("%s", palavraAtual.palavra) == 1)
    {
        palavras[i] = palavraAtual;
        i++;
    }
    verificaPalavras(palavras, i);

    return 0;
}

void verificaPalavras(tTexto *palavras, int qtdPalavras)
{
    tTexto maiorPalavra;
    int tamanhoMaiorPalavra = 0;
    int i;

    for(i = 0; i < qtdPalavras; i = i+2)
    {
        if(strlen(palavras[i].palavra) > strlen(palavras[i+1].palavra))
        {
            printf("%s\n", palavras[i].palavra);
            if(strlen(palavras[i].palavra) > tamanhoMaiorPalavra)
            {
                tamanhoMaiorPalavra = strlen(palavras[i].palavra);
                maiorPalavra = palavras[i];
            }
        }
        else if(strlen(palavras[i].palavra) < strlen(palavras[i+1].palavra))
        {
            printf("%s\n", palavras[i+1].palavra);
            if(strlen(palavras[i+1].palavra) > tamanhoMaiorPalavra)
            {
                tamanhoMaiorPalavra = strlen(palavras[i+1].palavra);
                maiorPalavra = palavras[i+1];
            }
        }
    }
    if(tamanhoMaiorPalavra != 0)
        printf("MAX:%s\n", maiorPalavra.palavra);
    else
        printf("MAX:--\n");
}