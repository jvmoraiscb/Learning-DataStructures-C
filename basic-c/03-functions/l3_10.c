/* 
(BOCA:L3_10) Problema: O irmão de Ana sendo muito experto descobriu como ela
codificou os textos dela na L2_17, por conta disso, ela veio recorrer novamente a
você, pra que você faça melhorias pro programa pra que dessa vez ninguém
descubra o que há nos textos codificados.
Para melhorar seu código, o primeiro passo é modularizar.
a) A codificação agora deverá ser feita por uma função que recebe uma letra e a
chave de codificação (inteiro) e retornará a letra codificada. A função deverá ter o
seguinte cabeçalho: char Codifica(char letra, int n);
b) De forma análoga, deverá ser feita uma função que decodifique uma letra,
recebendo como parâmetro a letra e um inteiro que represente a chave de
codificação e retornar a letra decodificada. A função deverá ter o seguinte
cabeçalho: char Decodifica (char letra, int n);
Depois das funções básicas serem feitas, Ana também gostaria que as letras
maiúsculas dessa vez também fossem cofidicadas, só que com a chave 2 vezes maior
que a chave normal, ou seja, se a chave é 2, a letra a vira c e a letra A vira E. Para
diferenciar os caracteres recebidos, crie as funções:
a) int EhLetra (char c) que recebe um caractere e retorna verdadeiro se for letra e
falso caso contrário.
b) int EhLetraMaiuscula (char c) que recebe um caractere e retorna verdadeiro se ele
for letra maiúscula e falso caso contrário;
c) int EhLetraMinuscula (char c) que recebe um caractere e retorna verdadeiro se for
letra minúscula e falso caso contrário.
Atenção: Números e outros caracteres que por ventura apareçam no texto não
deverão ser codificados.
 Entrada: dois números inteiros representando modo codificador ou decodificador e a chave
de codificação seguidos do texto que terminado por um ponto ‘.’.
 Saída: o texto codificado ou decodificado.
 Exemplo de Entradas:
1 1 Ja esta tarde demais, que sono!!! zZ.
1 3 Joao1#.
2 4 sm.
 Exemplo de Saídas:
Lb ftub ubsef efnbjt, rvf tpop!!! aB.
Prdr1#.
oi.
*/

#include <stdio.h>

char Codifica(char c, int n);
char Descodifica(char c, int n);
int EhLetra (char c);
int EhLetraMaiuscula (char c);
int EhLetraMinuscula (char c);

int main(){
    int n, chave;
    char c;
    
    scanf("%d %d %c", &n, &chave, &c);
    
    if (n == 1)
    {
        while (c!='.')
        {
            printf("%c", Codifica(c, chave));
            scanf("%c", &c);
        }
        printf(".\n");
    }
    else if (n == 2)
    {
        while (c!='.')
        {
            printf("%c", Descodifica(c, chave));
            scanf("%c", &c);
        }
        printf(".\n");
    }
    else
        printf("Operacao invalida.\n");

    return 0;
}

char Codifica(char c, int chave)
{
    int cC;
    if (EhLetraMaiuscula(c))
    {
		cC = c + (chave*2)%26;
		if (cC > 90){ //'Z'
		    cC-=26;
		} 
    }
    else if (EhLetraMinuscula(c))
    {
		cC = c + (chave%26);
		if (cC > 122){ //'z'
			cC-=26;
		}
    }
    else
        cC = c;
    return cC;
}

char Descodifica(char c, int chave)
{
    int cC;
    if (EhLetraMaiuscula(c))
    {
		cC = c - (chave*2)%26;
		if (cC < 65){ //'A'
		    cC+=26;
		}
    }
    else if (EhLetraMinuscula(c))
    {
		cC = c - (chave%26);
		if (cC < 97){ //'a'
			cC+=26;
		}
    }
    else
        cC = c;
    return cC;
}

int EhLetra(char c){

    if ((EhLetraMaiuscula(c) == 1) || (EhLetraMinuscula(c) == 1))
        return 1;
    else
        return 0; 
}
int EhLetraMaiuscula(char c){
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;    
}
int EhLetraMinuscula(char c){
    if (c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;    
}

