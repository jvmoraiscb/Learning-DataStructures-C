/*
Implemente funções em C para cada um dos problemas abaixo, em um mesmo arquivo
(“seu_nome.c”). Faça com que a função main chame adequadamente cada uma das funções.
Envie o arquivo “seu_nome.c” pelo Classroom. Use alocação dinâmica sempre que possível!!!

1. Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r.
A área da superfície e o volume são dados, respectivamente, por e . Essa função
deve obedecer ao seguinte protótipo: void calc_esfera (float r, float* area, float*
volume);
2. Implemente uma função que calcule as raízes de uma equação do segundo grau, do tipo ax2
+ bx + c = 0. Essa função deve obedecer o seguinte protótipo: int raizes (float a, float
b, float c, float* x1, float* x2);
3. Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de
tamanho n e retorne quantos números pares estão armazenados nesse vetor. Essa função
deve obedecer ao protótipo: int pares (int n, int* vet);
4. Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de
tamanho n e inverta a ordem dos elementos armazenados nesse mesmo vetor. Essa função
deve obedecer ao protótipo: void inverte (int n, int* vet);
5. Implemente uma função que permita a avaliação de polinômios. Cada polinômio é definido por
um vetor que contém seus coeficientes. Por exemplo, o polinômio de grau 2, 3x2 + 2x+ 12,
terá um vetor de coeficientes igual a vet[] = {12, 2, 3}. A função deve obedecer o seguinte
protótipo: double avalia (double* poli, int grau, double x), onde poli é o vetor de
coeficientes; grau é o grau do polinômio; x é o valor da variável.
*/

#define PI 3.14159265

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void calc_esfera(float r, float* area, float* volume);
int raizes(float a, float b, float c, float* x1, float* x2);
int pares(int n, int* vet);
void inverte(int n, int*vet);
double avalia(double* poli, int grau, double x);

int main(){
	printf("QUESTAO 1\n");
	float area, volume;
	float r = 5;
	calc_esfera(r, &area, &volume);
	printf("Area superficial = %.2f\nVolume = %.2f\n", area, volume);
	
	printf("\nQUESTAO 2\n");
	float a = 1, b = 4, c = -5, x1, x2;
	if(raizes(a,b,c,&x1,&x2) == 0)
		printf("Nao ha raizes reais\n");
	else
		printf("X1 = %.2f\nX2 = %.2f\n", x1, x2);
		
	printf("\nQUESTAO 3\n");
	int qtd_num = 10, qtd_pares;
	int* vet = (int*) malloc(sizeof(int)*qtd_num);
	for(int i = 0; i < qtd_num; i++)
		vet[i] = i+1;
	qtd_pares = pares(qtd_num, vet);
	printf("Quantidade de numeros pares = %d\n", qtd_pares);
	free(vet);

	printf("\nQUESTAO 4\n");
	int qtd_num2 = 10;
	int* vet2 = (int*) malloc(sizeof(int)*qtd_num2);
	printf("Lista antes de ser invertida:\n");
	for(int i = 0; i < qtd_num2; i++){
		vet2[i] = i+1;
		printf("%d ", vet2[i]);
	}
	inverte(qtd_num2, vet2);
	printf("\nLista invertida:\n");
	for(int i = 0; i < qtd_num2; i++){
		printf("%d ", vet2[i]);
	}
	printf("\n");
	free(vet2);

	printf("\nQUESTAO 5\n");
	int grau = 5, x = 2;
	double* poli = malloc(sizeof(double)*grau+1);
	for(int i = 0; i < grau+1; i++){
		poli[i] = i+1;
	}
	printf("Resultado = %.2lf\n", avalia(poli, grau, x));
	free(poli);
	return 0;
}

void calc_esfera(float r, float* area, float* volume){
	*area = (float) 4.0 * PI * pow(r, 2);
	*volume = (float) 4.0 * PI * pow(r, 3) / 3;
}

int raizes(float a, float b, float c, float* x1, float* x2){
	float delta = pow(b, 2) - 4*a*c;
	float x1_temp, x2_temp;
	if (delta < 0)
		return 0;
	*x1 = (float) (b*-1 + sqrt(delta)) / 2*a;
	*x2 = (float) (b*-1 - sqrt(delta)) / 2*a;
	return 1;
}
int pares(int n, int* vet){
	int qtd_pares = 0;
	
	for(int i = 0; i < n; i++){
		if((vet[i])%2 == 0){
			qtd_pares++;
		}
	}
	
	return qtd_pares;
}
void inverte(int n, int*vet){
	int vet_temp[n];
	int i, j;
	for(i = 0, j = n-1; i < n; i++, j--){
		vet_temp[j] = vet[i];
	}
	for(i = 0; i < n; i++){
		vet[i] = vet_temp[i];
	}
}
double avalia(double* poli, int grau, double x){
	double resp = 0;

	for(int i=0 , j = grau; i < grau+1; i++, j--){
		resp += poli[j]*pow(x, i);
	}
	return resp;
}

