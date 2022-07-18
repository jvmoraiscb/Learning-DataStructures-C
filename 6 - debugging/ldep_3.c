/*
(BOCA:LDEP1_3) Problema: O objetivo desta questão é treinar a capacidade de
encontrar erros e acertar códigos. Para isso, conserte o código dado (arquivo
“codigo_quebrado.c” no zip juntamente com a descrição do problema), para que
ele seja capaz de imprimir os múltiplos de 2 e 3 de um intervalo.
• Entrada: Um número inteiro n que determinará o intervalo de interesse como sendo de 1 a
n.
• Saída: Todos os múltiplos de 2 e 3 contidos no intervalo de 1 a n (n não incluso no
intervalo), sendo eles separados por espaço.
• Exemplo de Entrada:
8
15
• Exemplo de Saída:
2 3 4 6
2 3 4 6 8 9 10 12 14
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, i = 1;

    scanf("%d", &a);


    while(i < a) {
        if(i % 2 == 0){
            printf("%d ", i);}
        else if(i % 3 == 0){
            printf("%d ", i);}
        i++;
        
    }
    printf("\n");
    return 0;
}
