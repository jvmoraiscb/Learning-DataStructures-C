/*
(BOCA: P1_2018_Q4) Problema: Faça um programa que incremente um horário com
uma quantidade de minutos e diga o equivalente em quantidade de dias, horas e
minutos. Analisando o último dos exemplos abaixo, podemos ver que o horário
02:05 deve ser incrementado de 56 minutos gerando 0 dias, 3 horas e 1 minuto e a
resposta “(3 horas)(1 minuto)”. Como o número de dias foi zero, ele foi omitido na
resposta. Como número de horas foi 3, ele foi acompanhado do descritor “horas”.
Como o número de minutos foi 1, ele foi acompanhado do descritor “minuto”.
• Entrada: 1 horário (horas e minutos) e um incremento em minutos. O horário será dado no
formato HH:MM, no qual as horas vão de zero a 23 e os minutos vão de zero a 59. O
incremento será dado em minutos e virá logo após o horário (separado por um espaço).
Veja o formato de entrada nos exemplos abaixo.
• Saída: A saída deverá imprimir a quantidade de dias, horas e minutos que representa o
horário incrementado da quantidade de minutos. Ela deverá apresentar primeiro a
quantidade de dias, depois a de horas e, por último, a de minutos. Cada quantidade deverá
ser apresentada entre parentes e só deverá ser mostrada se for maior do que zero. As
quantidades deverão ser seguidas de um descritor indicando se é referente a “dias”,
“horas” ou “minutos”. O descritor deverá estar no singular (“dia”, “hora” ou “minuto”) caso
a quantidade respectiva seja 1 para qualquer um dos elementos. Veja o formato da saída
nos exemplos abaixo.
• Exemplo de Entrada:
02:55 10
23:50 200
14:31 3000
01:00 1
01:00 30
02:05 56
• Exemplo de Saída:
(3 horas)(5 minutos)
(1 dia)(3 horas)(10 minutos)
(2 dias)(16 horas)(31 minutos)
(1 hora)(1 minuto)
(1 hora)(30 minutos)
(3 horas)(1 minuto)
*/

#include <stdio.h>

int main(){

	int d=0, h, hf, m, mf, i;
	
	scanf("%d:%d %d",&h, &m, &i);
	
	mf=m+i;
	
	if (mf>=60){
		m=mf%60;
		hf=h+mf/60;
		h=hf;
	}
	else{
		m=mf;
		hf=h;
		h=hf;
	}
	
	if (hf>=24){
		d+=hf/24;
		h=hf%24;
	}
	if (d==1){
		printf("(%d dia)", d);
	}
	if (d>1){
		printf("(%d dias)", d);
	}
	if (h==1){
		printf("(%d hora)", h);
	}
	if (h>1){
		printf("(%d horas)", h);
	}
	if (m==1){
		printf("(%d minuto)", m);
	}
	if (m>1){
		printf("(%d minutos)", m);
	}

return 0;
}
