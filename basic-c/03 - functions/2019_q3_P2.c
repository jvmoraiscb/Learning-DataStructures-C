/* 
(BOCA: P2_2019_Q3_a) Problema: Faça um programa para processar um texto e
escrever os seus números de um dígito por extenso. Os números com mais de um
dígito devem permanecer inalterados, assim como os demais caracteres do texto.
• Entrada: um delimitador d (um caractere) que servirá para identificar o fim do texto; um
caractere espaço ‘ ’ e, por fim, o texto a ser processado. O texto será necessariamente
terminado com o delimitador d e não conterá números negativos. Veja o formato de
entrada nos exemplos abaixo.
• Saída: A saída deverá imprimir o texto dado como entrada, porém com seus números de
um dígito convertidos para texto. Ou seja, caso encontre o número 1 no texto, ele deverá
ser convertido para “um”, o 2 para “dois” e assim por diante, porém números como 10, 123
e 92145 não devem ser alterados. Veja o formato da saída nos exemplos abaixo.
O programa deve estar modularizado, para isso crie:
a) Uma função que receba um caractere como parâmetro e retorne verdadeiro se ele
for um dígito numérico ou falso caso contrário. Cabeçalho: int EhDigito(char c);
b) Uma função leia o próximo caractere da entrada padrão e o retorne caso não seja o
caractere terminador recebido como parâmetro. Se ele for o caractere terminador,
a função deverá retornar zero. Cabeçalho: char LeProxChar(char terminador);
c) Uma função que receba um caractere numérico e imprima sua versão por extenso.
Cabeçalho: void ImprimePorExtenso(char digito);
• Exemplo de Entrada:
# Sera que eu deveria fazer 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, ou todas as questoes do boca.#
. Quanto eh 2 + 2? Seria 4 ou 198231? Acho q 4.
. Vamos tentar (1e2h3k234523) repetir esse numero 987432140953240.
• Exemplo de Saída:
Sera que eu deveria fazer zero, um, dois, tres, quatro, cinco, seis, sete, oito, nove, 10, 25,
ou todas as questoes do boca.
Quanto eh dois + dois? Seria quatro ou 198231? Acho q quatro
Vamos tentar (umedoishtresk234523) repetir esse numero 987432140953240
*/

#include <stdio.h>

int EhDigito(char c);
char LeProxChar (char delimitador);
void ImprimePorExtenso(char digito);

void main()
{
    char c0 = 'a', c, c2, delimitador;

    scanf("%c ", &delimitador);

    scanf("%c", &c);
    while (1)
    {
        c2 = LeProxChar(delimitador);

        if (EhDigito(c0) == 0 && EhDigito(c) == 1 && EhDigito(c2) == 0)
            ImprimePorExtenso(c);
        else
            printf("%c", c);

        if (c2 == 0)
            break;
        else
            c0 = c;
            c = c2;
    }
}

int EhDigito(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

char LeProxChar (char delimitador)
{
    char c2;

    scanf("%c", &c2);
    if (c2 == delimitador)
        return 0;
    else
        return c2;
}

void ImprimePorExtenso(char digito)
{
    if(digito == '0')
        printf("zero");
    if(digito == '1')
        printf("um");
    if(digito == '2')
        printf("dois");
    if(digito == '3')
        printf("tres");
    if(digito == '4')
        printf("quatro");
    if(digito == '5')
        printf("cinco");
    if(digito == '6')
        printf("seis");
    if(digito == '7')
        printf("sete");
    if(digito == '8')
        printf("oito");
    if(digito == '9')
        printf("nove");
}



