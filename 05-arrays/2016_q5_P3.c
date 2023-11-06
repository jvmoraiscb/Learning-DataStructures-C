/* 
Problema: (BOCA: P3_2016_Q5) Faça um programa que diga se uma palavra alvo
pode ser escrita com as letras de uma palavra fonte ao retirar algumas letras da
palavra fonte. Isso sem alterar a ordem das letras e considerando letras maiúsculas
e minúsculas iguais. Ex. a palavra alvo “Bate” pode ser escrita com a palavra fonte
“Abacate” retirando as letras a, c, a. Já a palavra alvo “alo” não pode ser escrita com a
palavra fonte “ola”, pois apesar de conter todas as letras, elas não obedecem a
ordem necessária.
 Entrada: Um número c de casos a serem tratados seguido de c casos, um cada linha. Cada
caso será descrito por duas palavras (com no máximo 400 caracteres) dadas na ordem,
palavra alvo e palavra fonte.
 Saída: A saída será composta por c linhas, uma para cada caso, com cada linha contendo
“PODE” se a palavra alvo pode ser escrita com as letras da palavra fonte e sem alterar a sua
ordem, e “NÃO PODE” caso contrário.
 Exemplo de Entrada:
10
tia Thiago
Thiago Oliveira
Oliva Oliveira
Oliva Oli
Bate Abacate
Teste teSte
Oliva Oliveir
i Foi
alo ola
dados desafiadores
 Exemplo de Saída:
PODE!
NAO PODE!
PODE!
NAO PODE!
PODE!
PODE!
NAO PODE!
PODE!
NAO PODE!
PODE!
*/

#include <stdio.h>
#include <string.h>

int palavraEstaContida(char * pAlvo, char * pFonte);
int letraEhEquivalente(char pAlvo, char pFonte);
void analisaCaso();

int main()
{
    int nCasos, caso;
    scanf("%d", &nCasos);

    for(caso = 0; caso < nCasos; caso++)
    {
        //printf("caso:%d\n", caso);
        analisaCaso();
    }

    return 0;
}

void analisaCaso()
{
    char palavraAlvo[400], palavraFonte[400];

    scanf("%s%s", palavraAlvo, palavraFonte);

    if(palavraEstaContida(palavraAlvo, palavraFonte) == 1)
        printf("PODE!\n");
    else
        printf("NAO PODE!\n");
}

int palavraEstaContida(char * pAlvo, char * pFonte)
{
    int nCaracteresFonte = strlen(pFonte);
    int nCaracteresAlvo = strlen(pAlvo);

    int i, i1 = 0, nLetrasIguais = 0;

    for(i = 0; i < nCaracteresFonte; i++)
    {
        if(letraEhEquivalente(pFonte[i], pAlvo[i1]) == 1)
        {
            nLetrasIguais++;
            i1++;
        }

        if(nLetrasIguais == nCaracteresAlvo)
            break;
    }

    if(nLetrasIguais == nCaracteresAlvo)
        return 1;
    else
        return 0;
}

int letraEhEquivalente(char pAlvo, char pFonte)
{
    if(pAlvo == pFonte) // a = a - A = A
        return 1;
    else if(pAlvo == pFonte + 32) // a = A
        return 1;
    else if(pAlvo == pFonte - 32) // A = a
        return 1;
    else
        return 0;
}