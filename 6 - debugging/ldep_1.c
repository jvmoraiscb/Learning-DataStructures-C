/*
(BOCA:LDEP1_1) Problema: O objetivo desta questão é treinar a capacidade de
encontrar erros e acertar códigos. Para isso, concerte o código dado (arquivo
“codigo_quebrado.c” no zip juntamente com a descrição do problema), para que
ele seja capaz de ler uma sequência de pares de números da entrada padrão e
imprimir a soma de cada par.
• Entrada: Um número inteiro informando a quantidade de pares de números seguido dos
pares de números, sendo um par em cada linha.
• Saída: A soma de cada par, sendo uma em cada linha.
• Exemplo de Entrada:
5
10 20
4000 10000
0 0
-5 40
12345678 12345677
• Exemplo de Saída:
30
14000
0
35
24691355
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    int a=0, b, c, d;

	scanf("%d", &d);
    while(a < d){
        scanf("%d %d", &b, &c);
        printf("%d\n", b + c);
        a++;
    }

    return 0;
}
