/*
(BOCA:L2_14) Problema: Faça um programa para eliminar os caracteres espaço ‘ ‘ de
uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até
encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.
• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação
‘?’ ou exclamação ‘!’.
• Saída: “RESP:” seguido da sequência de caracteres modificada.
• Exemplo de Entrada:
Thiago Oliveira dos Santos.
Testando 1 2 3 ABC * &&&¨ ?
!
• Exemplo de Saída:
RESP:ThiagoOliveiradosSantos.
RESP:Testando123ABC*&&&¨?
RESP:!
*/

#include <stdio.h>

int main(){

	char s;
	
	scanf("%c", &s);
	printf("RESP:");
	
	while (s!='!' && s!='?' && s!='.'){
		if (s!=' '){
			printf("%c", s);
		}
		scanf("%c", &s);
	}
	
	if (s=='!' || s=='?' || s=='.'){
		printf("%c",s);
	}
	
return 0;
}
