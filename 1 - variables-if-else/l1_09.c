/*
(BOCA:L1_9) Problema: Faça um programa que mostre a versão maiúscula de uma
letra minúscula. Caso o caractere não seja letra ou não seja minúscula, mostre uma
mensagem. OBS: Proibido usar a função toupper. Dica: olhar tabela ASCII.
Essa questão NÃO é deve ser considerada correta se a resposta for “YES - Presentation
differences”!!
• Entrada: Um caractere.
• Saída: A versão maiúscula do caractere seguida do seu valor ASCII ou a mensagem
apropriada. Ver exemplos abaixo.
• Exemplo de Entrada:
a
g
1
A
• Exemplo de Saída:
A(65)
G(71)
Nao e letra!
A letra deve ser minuscula!
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){ //poderia print o char em forma de inteiro com "%d"
	
	char l; // letra
	int c; // letra em ascii
	int cm; // letra maiuscula
	
	scanf("%c", &l);
	
	c = l;
	
	if (c >= 97 && c <= 122){
	
		cm = c - 32;
	
		printf("%c(%d)", cm, cm);
	
	}

	else if (c >= 65 && c <= 90){
	
		printf("A letra deve ser minuscula!");
	
	}
	
	else {
	
		printf("Nao e letra!");
	
	}


   return 0;
}
