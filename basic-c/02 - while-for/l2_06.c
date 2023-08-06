/*
(BOCA:L2_6) Problema: Faça um programa que calcule S, dado por:
--
• Entrada: Seu programa deverá receber 1, 2 ou 3 indicando S1, S2 ou S3
respectivamente.
• Saída: Seu programa deverá apresentar o resultado das somas descritas
acima, sempre com precisão de 6 casas após a vírgula.
• Exemplo de Entrada:
1
2
• Exemplo de Saída:
95.500795
1560828692041339.750000
*/
#include <stdio.h>
#include <math.h>

int main(){
	int s;
	double s1, s2, soma=0;
	
	scanf("%d", &s);
	
	if (s==1){
		s1=1;
		s2=1;
		for(s2;s2<=50;s2++){
			soma+=s1/s2;
			s1+=2;
		}
		printf("%f", soma); 
	}
	else if (s==2){
		s1=1;
		s2=50;
		for (s2;s2>=1;s2--){
			soma+=pow(2, s1)/s2;
			s1++;
		}
		printf("%f", soma);
	}
	else if (s==3){
		s1=1;
		s2=1;
		for (s2;s2<=10;s2++){
			soma+=s1/pow(s2, 2);
			s1++;
		}
		printf("%f", soma);
	}
	else{
		printf("Escolha entre 1, 2 ou 3.");
	}
return 0;
}
