/* 
(BOCA:L5_12) Problema: Dado o programa abaixo que lê sobrenomes e nomes
separados por espaço e imprime o nome completo da pessoa sem espaço,
implemente a função que falta para concatenar (i.e. juntar) duas strings. OBS: Não
usar funções da biblioteca string.h.
#include <stdio.h>
#include <stdlib.h>
void ConcatenaString(char * str1, char * str2, char * strOut);
int main(){
char nome[1000];
char sobrenome[1000];
char nomeCompleto[2000];
while ( scanf("%s", &sobrenome) == 1 && scanf("%s", &nome) == 1){
ConcatenaString(nome, sobrenome, nomeCompleto);
printf("%s\n", nomeCompleto);
}
 return 0;
}
 Entrada: uma lista de pares de palavras, sobrenome e nome, separadas por espaço, um par
em cada linha.
 Saída: Nome completo sem espaço.
 Exemplo de Entrada:
Oliveira Thiago
Detal Fulano
Aninimo Beltrano
Loko Geronimo
 Exemplo de Saída:
ThiagoOliveira
FulanoDetal
BeltranoAninimo
GeronimoLoko
*/

#include <stdio.h>
#include <stdlib.h>

void ConcatenaString(char * str1, char * str2, char * strOut);

int main(){
    char nome[1000];
    char sobrenome[1000];
    char nomeCompleto[2000];
    
    while ( scanf("%s", &sobrenome) == 1 && scanf("%s", &nome) == 1)
    {
        ConcatenaString(nome, sobrenome, nomeCompleto);
        printf("%s\n", nomeCompleto);
    }

    return 0;
}

void ConcatenaString(char * str1, char * str2, char * strOut)
{
    int i0, i = 0, i1 = 0, i2 = 0;

    //bzero(strOut, 2000);
    for(i0 = 0; i0 <= 2000; i0++)
        strOut[i0] = '\0';

    while(str1[i] != '\0')
    {
        strOut[i] = str1[i1];
        i++;
        i1++;
    }
    while(str2[i2] != '\0')
    {
        strOut[i] = str2[i2];
        i++;
        i2++;
    }
}
