/*
(BOCA:LDEP1_2) Problema: O objetivo desta questão é treinar a capacidade de
encontrar erros e acertar códigos. Para isso, conserte o código dado (arquivo
“codigo_quebrado.c” no zip juntamente com a descrição do problema), para que
ele seja capaz de informar se uma pessoa pode votar ou não.
• Entrada: a idade da pessoa.
• Saída: uma mensagem dizendo “vc nao pode votar!”, caso a pessoa tenha menos de 16
anos; “vc pode votar, mas nao eh obrigado!”, caso a pessoa tenha entre 16 e 18 anos (18
não incluso); “vc eh obrigado a votar!”, caso a pessoa tenha 18 anos ou mais, mas não seja
idosa; ou, “vc pode votar, mas nao eh obrigado!”, caso a pessoa seja idosa e tenha 65 anos
ou mais.
• Exemplo de Entrada:
14
17
24
80
• Exemplo de Saída:
vc nao pode votar!
vc pode votar, mas nao eh obrigado!
vc eh obrigado a votar!
vc pode votar, mas nao eh obrigado!
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int idade;

    scanf("%d", &idade);

    if(idade < 16) {printf("vc nao pode votar!\n");}
    if((idade >= 16) && (idade < 18)) {printf("vc pode votar, mas nao eh obrigado!\n");}
    if((idade >= 18) && (idade < 65)) {printf("vc eh obrigado a votar!\n");}
    if(idade >= 65) {printf("vc pode votar, mas nao eh obrigado!\n");}
    

    return 0;
}
