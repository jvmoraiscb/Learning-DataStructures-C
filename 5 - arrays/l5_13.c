/* 
(BOCA:L5_13) Problema: Dado o programa abaixo que lê pares de palavras
separadas por espaço e imprime “IGUAL” quando elas são iguais e “DIFERENTE”
quando elas são diferente, implemente a função que falta para comparar duas
strings. OBS: Não usar funções da biblioteca string.h.
#include <stdio.h>
#include <stdlib.h>
int ComparaString(char * str1, char * str2);
int main(){
char str1[1000];
char str2[1000];
while ( scanf("%s", &str1) == 1 && scanf("%s", &str2) == 1){
if ( ComparaString(str1, str2) )
printf("IGUAL\n");
else
printf("DIFERENTE\n");
}
 return 0;
}
 Entrada: uma lista de pares de palavras separadas por espaço, um par em cada linha.
 Saída: “IGUAL” para pares com palavras iguais, e “DIFERENTE” para pares com palavras
diferentes.
 Exemplo de Entrada:
Oliveira Oliveira
fulano Fulano
Aninimo Anini
Ani Anini
Loko Geronimo
1231 1231
1231 2131
2 2
123456789 123456789
ojin nxqw
BABA BABA
 Exemplo de Saída:
IGUAL
DIFERENTE
DIFERENTE
DIFERENTE
DIFERENTE
IGUAL
DIFERENTE
IGUAL
IGUAL
DIFERENTE
IGUAL
*/

#include <stdio.h>
#include <stdlib.h>

int ComparaString(char * str1, char * str2);

int main(){
    char str1[1000];
    char str2[1000];

    while ( scanf("%s", &str1) == 1 && scanf("%s", &str2) == 1)
    {
        if ( ComparaString(str1, str2) )
            printf("IGUAL\n");
        else
            printf("DIFERENTE\n");
    }

return 0;
}

int ComparaString(char * str1, char * str2)
{
    int i = 0, charDiferentes = 0;

    while(str1[i] != '\0' || str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            charDiferentes++;
        i++;
    }

    if (charDiferentes == 0)
        return 1;
    else
        return 0;
}