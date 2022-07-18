/* 
(BOCA:L3_9) Problema: Você e seu amigo estão desenvolvendo um projeto de
Iniciação Científica, no qual consiste na criação de um dispositivo de análises da
chuva de determinada região. O dispositivo analisa, através de uma nova tecnologia,
o pH das gotas de chuva de uma área. Para demonstrar o projeto para outros
colegas, você precisa implementar um programa que mostra as estatísticas da chuva
de uma região, dados a área da região em metros quadrados e a densidade de gotas
de chuva (quantas gotas de chuva caem em 1 metro quadrado a cada 1 segundo) e o
tempo em segundos que o dispositivo analisou o local.
a) Seu programa deve conter a função int verificapH(float pH) que retorna 0 para pH
neutro, 1 para ácido e 2 para básico.
b) Seu programa deve conter a função int verificaGotaChuvaAcida(float pH) que
retorna verdadeiro se a gota for considerada chuva ácida (pH menor que 5.7) e
falso caso contrário.
c) Seu programa deve conter a função float porcentagem(float total, float valor) que
retorna a porcentagem de um valor em relação ao número total.
d) Seu programa deve conter a função
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) que
imprime os resultados conforme formatação mostrada abaixo.
Atenção: o pH considerado neutro é igual a 7.00; ácido é menor que 7.00; básico é
maior que 7.00. Todas as impressões de float devem ser com precisão de 2 casas
decimais.
 Entrada: a entrada do seu programa deve conter uma linha com três números inteiros: a
área A (0 <= A <= 50) da região a ser analisada em metros quadrados, a densidade D
(0 <= D <= 50) de gotas de chuva por metro quadrado em 1 segundo, e o tempo T
(0 <= T <= 12) que o dispositivo analisou o local em segundos. Em seguida, seu programa
deverá ler um valor float P (0.00 <= P <= 14.00) (você deve considerar as entradas sempre
com 2 casas decimais de precisão) para cada gota de chuva que caiu no tempo e região
dados representando o pH da água.
 Saída: a saída do seu programa deverá imprimir uma linha com a quantidade de gotas com
pH ácido, básico e neutro analisadas pelo dispositivo, o pH mais ácido, o pH mais básico e o
pH mais neutro. Também deve imprimir outra linha com uma mensagem sobre a chuva nas
condições dadas – se foi considerada ácida (75.00% ou mais das gotas com pH menor que
5.70), normal (75.00% ou mais das gotas com pH maior ou igual 5.70) ou com indícios de
chuva ácida caso contrário; essa linha deve ser seguida da porcentagem de gotas com pH
menor que 5.70 e a porcentagem de gotas com pH igual ou maior que 5.70. Caso o
dispositivo não avalie nenhuma gota, a saída do seu programa deve imprimir somente a
mensagem “Nenhuma gota foi avaliada”. Atenção às formatações abaixo.
 Exemplo de Entradas:
1 2 2
7.80 3.31 3.08 8.90
3 3 3
1.34 3.50 5.4 7.00 7.01 5.98 3.20 4.47 1.17 3.43 2.10 1.96 3.40 13.5 3.40 2.00 3.50 5.02 2.30
5.30 2.10 4.71 5.69 10.98 4.44 4.42 4.42
3 3 3
5.97 6.20 5.40 9.50 8.50 5.98 3.20 5.89 6.87 6.87 6.95 6.37 6.42 6.12 6.45 6.67 5.70 6.87
6.87 6.87 6.87 3.17 6.87 10.98 4.44 6.87 4.42
 Exemplo de Saídas:
2 2 0 3.08 8.90 7.80
Chuva com indicios de chuva acida 50.00% 50.00%
23 3 1 1.17 13.50 7.00
Chuva Acida 81.48% 18.52%
24 3 0 3.17 10.98 6.95
Chuva Normal 22.22% 77.78%
*/

#include <stdio.h>
#include <math.h>

int modulo(float a);

int verificapH(float pH);

int verificaGotaChuvaAcida(float pH);

float porcentagem(float total, float valor);

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main(){
	int area, densidade, tempo, i; //m², gotas/s, s
	int nGotaspHacido=0, nGotaspHneutro=0, nGotaspHbasico=0, nGotasTotal, nGotasChuvaAcida, nGotasNormal;
	float ph, pHmaisAlto = 0, pHmaisMedio = 11, pHmaisBaixo = 11;
	
	scanf("%d %d %d", &area, &densidade, &tempo);

	if (area*densidade*tempo == 0)
	{
		printf("Nenhuma gota foi avaliada");
	}

	else {
	
		for (i=1; i<=area*densidade*tempo; i++){
			scanf("%f", &ph);
			if (verificapH(ph) == 0)
				nGotaspHneutro += 1;
			else if (verificapH(ph) == 1){
				nGotaspHacido += 1;
				if (verificaGotaChuvaAcida(ph) == 1)
					nGotasChuvaAcida += 1;
			}
			else if (verificapH(ph) == 2)
				nGotaspHbasico += 1;

			if (fabs(ph-7) < fabs(pHmaisMedio-7))
				pHmaisMedio = ph;
			if (ph > pHmaisAlto)
				pHmaisAlto = ph;
			if (ph < pHmaisBaixo)
				pHmaisBaixo = ph;	
		
		}
		nGotasTotal = nGotaspHacido + nGotaspHbasico + nGotaspHneutro;
		nGotasNormal = nGotasTotal - nGotasChuvaAcida;

		printf("%d %d %d %.2f %.2f %.2f\n", nGotaspHacido, nGotaspHbasico, nGotaspHneutro, pHmaisBaixo, pHmaisAlto, pHmaisMedio );

		imprimeResultadosAnalise( porcentagem(nGotasTotal, nGotasChuvaAcida), porcentagem(nGotasTotal, nGotasNormal) );
	}
	return 0;
}

int verificapH(float pH)
{
	if(pH == 7)
	{
		return 0;
	}
	else if (pH < 7)
	{
		return 1;
	}
	else if (pH > 7)
	{
		return 2;
	}
}

int verificaGotaChuvaAcida(float pH)
{
	if (pH < 5.7)
		return 1;
	else
		return 0;
}

float porcentagem(float total, float valor)
{
	return (valor/total)* 100;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal)
{
	if (porcentagemGotasChuvaAcida >= 75)
		printf("Chuva Acida ");
	else if (porcentagemGotasChuvaNormal >= 75)
		printf("Chuva Normal ");
	else
		printf("Chuva com indicios de chuva acida ");

	printf("%.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
	

}
