/*
(BOCA:L2_23) Problema: Faça um programa que dado várias linhas com texto, o
programa só imprima o texto que estiver dentro de parênteses mais externos. O
programa será finalizado assim que achar um ponto final fora dos parênteses.
• Entrada: seu programa deverá receber linhas de texto até que se encontre um ponto final
fora dos parênteses. Todo parêntese aberto será necessariamente fechado.
• Saída: como saída, o programa deverá imprimir “RESP:” seguido de tudo que estiver entre
parênteses mais externos.
• Exemplo de Entradas:
testando(vaiimprimirisso).
teste(((abcdefg)))((abc.................defg)).
asdaxaazdcqw().
abcdefghi(TESTE).(NAOERAPRAIR)
• Exemplo de Saídas:
RESP:vaiimprimirisso
RESP: ((abcdefg))(abc.................defg)
RESP:
RESP:TESTE
*/

#include <stdio.h>

int main(){
	
	char l;
	int vparent=0;
	
	printf("RESP:");
	while (1){
		scanf("%c", &l);
		if (vparent==0 && l=='.')
			break;
		if (l==')')
			vparent--;
		if(vparent!=0)
			printf("%c", l);	
		if (l=='(')
			vparent++;			
	}
	
	
	return 0;
}
