/*
(BOCA:L2_19) Problema: Durante as Olimpíadas Rio/2016 um painel que mostrava o
resultado das competições quebrou e você deverá escrever um programa para
contabilizar e exibir os resultados. Cada Delegação de Atletas e cada Atleta serão
identificados por um número inteiro. Cada Atleta realizará três provas e receberá
uma nota de 0 a 10 para cada uma delas. Seu programa deverá dizer qual é o melhor
e o pior Atleta de cada Delegação tanto para o Masculino quanto para o Feminino e
por fim dizer qual é a Delegação Campeã para o Masculino e para o Feminino.
Atenção: Considera-se o melhor atleta aquele que sua maior nota seja a maior de
sua Delegação. Em caso de empate para o Melhor Atleta, comparar a segunda maior
nota dos atletas empatados, em seguida a terceira maior e em caso de empate das
três notas, o melhor atleta será aquele com a menor identificação. Considera-se o
pior atleta aquele que sua maior nota seja a menor que a maior nota dos outros
atletas. Em caso de empate para o Pior Atleta, comparar a segunda maior nota dos
atletas empatados, em seguida a terceira maior e em caso de empate das três notas,
o pior atleta será aquele com a maior identificação. Considera-se campeã em um dos
gêneros a Delegação que apresentar um maior valor para o somatório da maior nota
de cada atleta daquele gênero. Em caso de empate, ganha aquela com a menor
identificação.
• Entrada: um inteiro n representando a quantidade de delegações. Em seguida serão dadas
as Delegações em sequência, considerando a primeira delegação como 1, a segunda como
2 e assim sucessivamente. Cada Delegação é composta de várias linhas contendo, cada
uma, um inteiro positivo i que representa a identificação do atleta, um caractere c que
pode ser ‘F’ ou ‘M’ indicando o sexo, e por fim três inteiros representando as notas de cada
prova daquele atleta. Toda delegação terá pelo menos um homem e uma mulher. Cada
delegação é terminada com uma linha contendo o número -1.
• Saída: para cada delegação (separando delegações por linhas em branco), a identificação do
melhor e do pior Atleta tanto do Masculino quanto do Feminino. Ao fim, a saída contém a
identificação da Delegação Campeã Masculina e da Delegação Campeã Feminina. Veja a
formatação esperada nos exemplos abaixo.
• Exemplo de Entradas:
2
1 M 9 9 9
2 M 9 9 9
3 F 0 9 9
4 F 1 0 0
-1
1 M 9 0 0
2 M 9 9 9
3 M 8 10 10
4 F 0 9 9
5 F 1 0 0
-1
2
1 M 3 4 5
2 F 3 7 9
3 M 8 7 9
4 F 10 8 6
-1
1 M 2 8 9
2 F 10 8 10
3 M 8 8 8
4 F 7 6 6
5 F 9 9 9
-1
6
1 M 9 9 9
2 M 9 9 0
3 M 9 0 0
4 M 10 10 10
5 F 10 5 5
-1
1 M 9 9 9
2 M 9 0 0
3 M 9 9 0
4 M 9 9 0
5 F 6 6 6
-1
1 M 9 9 0
2 M 9 9 9
3 M 8 0 0
4 M 9 0 0
5 F 10 3 8
-1
1 M 9 9 0
2 M 8 8 8
3 M 8 8 8
4 M 9 0 0
5 M 9 9 9
6 F 6 6 8 
-1
1 M 9 0 0
2 M 9 9 9
3 M 9 9 0
4 M 9 9 0
5 F 4 6 6
-1
1 M 9 0 0
2 M 9 9 0
3 M 10 0 0
4 M 9 9 9
5 F 5 5 5
-1
• Exemplo de Saídas:
MELHORES ATLETAS DA DELEGACAO 1
MASCULINO: 1 FEMININO: 3
PIORES ATLETAS DA DELEGACAO 1
MASCULINO: 2 FEMININO: 4
MELHORES ATLETAS DA DELEGACAO 2
MASCULINO: 3 FEMININO: 4
PIORES ATLETAS DA DELEGACAO 2
MASCULINO: 1 FEMININO: 5
DELEGACAO CAMPEA:
MASCULINO: 2 FEMININO: 1
MELHORES ATLETAS DA DELEGACAO 1
MASCULINO: 3 FEMININO: 4
PIORES ATLETAS DA DELEGACAO 1
MASCULINO: 1 FEMININO: 2
MELHORES ATLETAS DA DELEGACAO 2
MASCULINO: 1 FEMININO: 2
PIORES ATLETAS DA DELEGACAO 2
MASCULINO: 3 FEMININO: 4
DELEGACAO CAMPEA:
MASCULINO: 2 FEMININO: 2
MELHORES ATLETAS DA DELEGACAO 1
MASCULINO: 4 FEMININO: 5
PIORES ATLETAS DA DELEGACAO 1
MASCULINO: 3 FEMININO: 5
MELHORES ATLETAS DA DELEGACAO 2
MASCULINO: 1 FEMININO: 5
PIORES ATLETAS DA DELEGACAO 2
MASCULINO: 2 FEMININO: 5
MELHORES ATLETAS DA DELEGACAO 3
MASCULINO: 2 FEMININO: 5
PIORES ATLETAS DA DELEGACAO 3
MASCULINO: 3 FEMININO: 5
MELHORES ATLETAS DA DELEGACAO 4
MASCULINO: 5 FEMININO: 6
PIORES ATLETAS DA DELEGACAO 4
MASCULINO: 3 FEMININO: 6
MELHORES ATLETAS DA DELEGACAO 5
MASCULINO: 2 FEMININO: 5
PIORES ATLETAS DA DELEGACAO 5
MASCULINO: 1 FEMININO: 5
MELHORES ATLETAS DA DELEGACAO 6
MASCULINO: 3 FEMININO: 5
PIORES ATLETAS DA DELEGACAO 6
MASCULINO: 1 FEMININO: 5
DELEGACAO CAMPEA:
MASCULINO: 4 FEMININO: 1
*/

#include <stdio.h>

int main(){

	int n, i, n1, n2, n3, na, nb, nc;
	int at, mM, pM, mF, pF;
	int mn1M=-1, pn1M=11, mn1F=-1, pn1F=11, mn2M=-1, pn2M=11, mn2F=-1,
	pn2F=11, mn3M=-1, pn3M=11, mn3F=-1, pn3F=11;
	int smM=0, smF=0;
	int vM, vF, vatM=-1, vatF=-1;
	char sx;
	
	scanf("%d", &n);
	
	for (i=1;i<=n;i++){
		while (1){
			scanf("%d", &at);
			if (at==-1){
				break;
			}
			scanf(" %c %d %d %d%*c", &sx, &na, &nb, &nc);
			if (na>=nb && nb>=nc){
				n1=na;
				n2=nb;
				n3=nc;
			}
			else if (na>=nc && nc>=nb){
				n1=na;
				n2=nc;
				n3=nb;
			}
			else if (nb>=na && na>=nc){
				n1=nb;
				n2=na;
				n3=nc;
			}
			else if (nb>=nc && nc>=na){
				n1=nb;
				n2=nc;
				n3=na;
			}
			else if (nc>=na && na>=nb){
				n1=nc;
				n2=na;
				n3=nb;
			}
			else if (nc>=nb && nb>=na){
				n1=nc;
				n2=nb;
				n3=na;
			}
			//printf("%d %d %d\n", n1, n2, n3);
			if (sx=='M'){
				if ((n1>mn1M)||(n1==mn1M && n2>mn2M)||(n1==mn1M &&
				n2==mn2M && n3>mn3M)){
					mn1M=n1;
					mn2M=n2;
					mn3M=n3;
					mM=at;
					smM+=n1;
				}	
				else
					smM+=n1;
					
				if ((n1<pn1M)||(n1==pn1M && n2<pn2M)||(n1==pn1M && 
				n2==pn2M && n3<pn3M)||(n1==pn1M && n2==pn2M && 
				n3==pn3M)){
					pn1M=n1;
					pn2M=n2;
					pn3M=n3;
					pM=at;
				}			
			}	
			if (sx=='F'){
				if ((n1>mn1F)||(n1==mn1F && n2>mn2F)||(n1==mn1F && 
				n2==mn2F && n3>mn3F)){
					mn1F=n1;
					mn2F=n2;
					mn3F=n3;
					mF=at;
					smF+=n1;
				}	
				else
					smF+=n1;
					
				if ((n1<pn1F)||(n1==pn1F && n2<pn2F)||(n1==pn1F && 
				n2==pn2F && n3<pn3F)||(n1==pn1F && n2==pn2F && 
				n3==pn3F)){
					pn1F=n1;
					pn2F=n2;
					pn3F=n3;
					pF=at;
				}	
			}
		}
		if (smM>vatM){
			vM=i;
			vatM=smM;
		}
		if (smF>vatF){
			vF=i;
			vatF=smF;
		}
		printf("MELHORES ATLETAS DA DELEGACAO %d\n", i);
		printf("MASCULINO: %d FEMININO: %d\n", mM, mF);
		printf("PIORES ATLETAS DA DELEGACAO %d\n", i);
		printf("MASCULINO: %d FEMININO: %d\n", pM, pF);
		printf("\n");
		mn1M=-1; pn1M=11; mn1F=-1; pn1F=11; mn2M=-1; pn2M=11; mn2F=-1;
		pn2F=11; mn3M=-1; pn3M=11; mn3F=-1; pn3F=11;
		smM=0; smF=0;
	}
	printf("DELEGACAO CAMPEA:\n");
	printf("MASCULINO: %d FEMININO: %d", vM, vF);

return 0;
}
