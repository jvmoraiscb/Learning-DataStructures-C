/*
(L2_13) Problema: Faça um programa para substituir letras minúsculas de uma frase
por letras maiúsculas. O programa deverá ler caracteres da entrada padrão (um por
vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.
OBS: “YES - Presentation diferences” não é uma resposta válida para essa questão.
• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação
‘?’ ou exclamação ‘!’.
• Saída: a sequência de caracteres modificada.
• Exemplo de Entrada:
Thiago Oliveira dos Santos.
Testando 1 2 3 ABC * &&&¨ ?
!
• Exemplo de Saída:
THIAGO OLIVEIRA DOS SANTOS.
TESTANDO 1 2 3 ABC * &&&¨ ?
!
*/

#include <stdio.h>
//#include <string.h>

int main(){

	char s;
	
	scanf("%c", &s);
	
	while (s!='!' && s!='?' && s!='.'){
		if (s>='a' && s<='z'){
			printf("%c", s-32);
		}
		else{
			printf("%c",s);
		}
		scanf("%c", &s);
	}
	
	if (s=='!' || s=='?' || s=='.'){
		printf("%c",s);
	}
	
return 0;
}
