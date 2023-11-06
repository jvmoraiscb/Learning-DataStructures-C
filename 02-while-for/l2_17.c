/*
(BOCA:L2_17) Problema: Ana queria codificar seus textos para que mais ninguém
lesse, e decodificá-los para quando ela quisesse ler. Para isso, faça um programa que
contenha essas duas opções. Serão dados dois números inteiros e um texto
terminado em ponto. O primeiro número é referente a opção (1 para codificar ou 2
para decodificar) que a pessoa quer e o segundo número será um número n
referente ao código da codificação, ou seja, dada a opção 1, codifique o texto
“somando” as letras minúsculas do texto a esse valor n para que o texto fique
codificado. Exemplo: se n = 2, a letra a vira c, a letra n vira p, a letra z vira b, e assim
sucessivamente. Dada a opção 2 com n = 1, o programa deve decodificar o texto
revertendo o texto para o original, ou seja, a letra c vira b, a letra a vira z, e assim
sucessivamente. Se for dada uma opção diferente das opções acima o programa
deverá imprimir: “Operacao invalida.”.
Atenção: Não deverão ser codificadas as letras maiúsculas. Números e outros
caracteres que por ventura apareçam no texto não deverão ser codificados. Serão
testados no BOCA outras entradas além das apresentadas nos exemplos.
• Entrada: dois números inteiros representando o modo codificador ou decodificador e a
chave de codificação seguido do texto que será sempre terminado com um ponto, i.e., “.”.
• Saída: o texto codificado ou decodificado.
• Exemplo de Entradas:
1 1 Ja esta tarde demais, que sono!!! zZ.
1 300209 Joao1#.
2 4 sm.
4 2 sdzf.
• Exemplo de Saídas:
Jb ftub ubsef efnbjt, rvf tpop!!! aZ.
Jbnb1#.
oi.
Operacao invalida
*/

#include <stdio.h>

int main(){

	int c, n, nf;
	char t;
	
	scanf("%d %d ", &c, &n);
	
	if (c==1){ //codificar
		scanf("%c", &t);
		while (t!='.'){
			if (t>='a' && t<='z'){
				if(t+n<='z')
					printf("%c", t+n);
				else{
					nf=t+n;
					while (nf>122){
						nf-=26;
					}
					printf("%c", nf);
				}
			}
			else{
				printf("%c", t);
			}
			
			scanf("%c", &t);
		}	
	}
	else if (c==2){ //decodificar
	scanf("%c", &t);
		while (t!='.'){
			if (t>='a' && t<='z'){
				if(t-n>='a')
					printf("%c", t-n);
				else{
					nf=t-n;
					while (nf<97){
						nf+=26;
					}
					printf("%c", nf);
				}
			}
			else{
				printf("%c", t);
			}
			
			scanf("%c", &t);
		}
	}
	else {
		printf("Operacao invalida");
	}
	printf(".");
	
return 0;
}
