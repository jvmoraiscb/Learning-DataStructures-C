/* 
Problema: (BOCA: P3_2017_Q4_a) Faça um programa que leia uma lista de palavras
e analise cada uma delas. Ao final, o programa deverá imprimir somente as vogais,
somente as consoantes ou a palavra inteira dependendo da quantidade de vogais e
consoantes em cada palavra. Se uma palavra tiver mais consoantes do que vogais,
somente suas consoantes devem ser impressas. Se uma palavra tiver mais vogais do
que consoantes, somente suas vogais devem ser impressas. Se ela tiver a mesma
quantidade de vogais e consoantes, então a palavra deve ser impressa por completo.
• Entrada: Uma lista de palavras, sendo uma em cada linha. As palavras não conterão espaço,
e podem conter caracteres que não são letras.
• Saída: A saída será composta por linhas, uma para cada palavra, com cada linha contendo
as vogais, consoantes ou a palavra completa dependendo de cada caso.
• Exemplo de Entrada:
TripaSeca
QuasiNada
SeuMadruga
DonaFlorinda
ElChapo
ChapoLiiiiin
Test123
Teeest123
Teeeste123
• Exemplo de Saída:
TrpSc
uaiaa
SeuMadruga
DnFlrnd
lChp
aoiiiii
Tst
Teeest123
eeee
*/

#define VOGAL 1
#define CONSOANTE 2
#define OUTRO 3

#include <stdio.h>
#include <string.h>

int verificaLetra(char letra);
void analisaString(char * palavra);
void resetaString(char * palavra);

int main()
{
    char palavra[100];

    while(scanf("%s", palavra) == 1)
    {
        analisaString(palavra);
        memset(palavra, '\0', sizeof(palavra));
    }

    return 0;
}

void analisaString(char * palavra)
{
    int qtdLetras = strlen(palavra);
    char somenteConsoantes[qtdLetras+1], somenteVogais[qtdLetras+1];
    memset(somenteConsoantes, '\0', sizeof(somenteConsoantes));
    memset(somenteVogais, '\0', sizeof(somenteVogais));

    int i, qtdConsoantes = 0, qtdVogais = 0;

    for(i = 0; i < qtdLetras; i++)
    {
        if(verificaLetra(palavra[i]) == VOGAL){
            somenteVogais[qtdVogais] = palavra[i];
            qtdVogais++;
        }
        if(verificaLetra(palavra[i]) == CONSOANTE){
            somenteConsoantes[qtdConsoantes] = palavra[i];
            qtdConsoantes++;
        }
    }
    
    if(qtdVogais > qtdConsoantes)
        printf("%s\n", somenteVogais);
    else if (qtdVogais < qtdConsoantes)
        printf("%s\n", somenteConsoantes);
    else
        printf("%s\n", palavra);

}

int verificaLetra(char letra)
{
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        return VOGAL;
    else if (letra >= 'A' && letra <= 'Z' || letra >= 'a' && letra <= 'z')
        return CONSOANTE;
    else
        return 0;
}