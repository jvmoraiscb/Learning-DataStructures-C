/*
(BOCA:L2_12) Problema: Faça um programa para substituir caracteres espaço ‘ ‘ por
caracteres underline ‘_’ de uma frase. O programa deverá ler caracteres da entrada
padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação
‘!’.
• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação
‘?’ ou exclamação ‘!’.
• Saída: “RESP:” seguido da sequência de caracteres modificada.
• Exemplo de Entrada:
Thiago Oliveira dos Santos.
Testando 1 2 3 * &&&¨ ?
!
• Exemplo de Saída:
RESP:Thiago_Oliveira_dos_Santos.
RESP:Testando_1_2_3_*_&&&¨___?
RESP:!
*/

#include <stdio.h>
#include <string.h>

int main(){

	int i;
	char s[128];
	
	fgets(s,128,stdin);
	printf("RESP:");
	
	 for (i = 0; i < strlen(s); ++i) {
        if (s[i] == ' ') {
    		s[i] = '_';
		}
		printf("%c", s[i]);
    }
	
return 0;
}
