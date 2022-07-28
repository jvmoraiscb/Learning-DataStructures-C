/* 
(BOCA:L5_16) Problema: Dado o programa abaixo que lê candidatos de um
concurso e imprime em ordem de classificação do concurso (do primeiro a ser
chamado ao último), implemente a função que ordena os candidatos considerando a
prioridade de chamada dada por maior nota, menor idade, e menor código.
#include <stdio.h>
#include <stdlib.h>
typedef struct{
int codigo;
char sobrenome[21];
char nome[21];
int nota;
int idade;
} tCandidato;
tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
void OrdenaCrescente(tCandidato * vet, int qtd);
int main(){
int qtdCand, i = 0, j;
scanf("%d", &qtdCand);
tCandidato candidatos[qtdCand];
for(i = 0; i < qtdCand; i++){
candidatos[i] = LeCandidato();
}
OrdenaCrescente(candidatos, qtdCand);
for(i = 0; i < qtdCand; i++){
ImprimeCandidato(candidatos[i]);
}
 return 0;
}
tCandidato LeCandidato(){
tCandidato candidato;
scanf("%*[^{]");
scanf("%*[{ ]");
scanf("%d", &candidato.codigo);
scanf("%*[, ]");
scanf("%[^,],", candidato.sobrenome);
scanf("%*[ ]");
scanf("%[^,],", candidato.nome);
scanf("%d", &candidato.nota);
scanf("%*[, ]");
scanf("%d", &candidato.idade);
scanf("%*[^\n]\n");
return candidato;
}
void ImprimeCandidato(tCandidato candidato){
printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
candidato.codigo, candidato.nome,
candidato.sobrenome, candidato.nota, candidato.idade);
}
 Entrada: uma quantidade N de candidatos, seguida de N candidatos (um em cada linha). As
informações de cada candidato são apresentadas entre chaves e separadas por vírgula
seguindo a ordem: código de inscrição (inteiro), sobrenome (máximo de 20 caracteres),
nome (máximo de 20 caracteres), nota (inteiro), idade (inteiro).
 Saída: Candidatos ordenados por ordem de chamada no concurso. Ver detalhes de formato
na função de impressão do candidato.
 Exemplo de Entrada:
10
{3, Oliveira, Thiago, 5, 35}
{5, Detal, Fulano, 10, 25}
{7, Oliveira, Anonimo, 10, 45}
{1, Loko, Poko, 7, 20}
{9, Lin, Chapo, 7, 25}
{4, Matica, Proble, 8, 30}
{11, Lin, Poko, 7, 20}
{8, Longaaaaaaaaaaaaaaaa, Tripa, 8, 30}
{6, Seca, Tripa, 8, 30}
{2, Loko, Chapo, 2, 20}
 Exemplo de Saída:
CAND(5): Fulano Detal, Nota:10, Idade:25
CAND(7): Anonimo Oliveira, Nota:10, Idade:45
CAND(4): Proble Matica, Nota:8, Idade:30
CAND(6): Tripa Seca, Nota:8, Idade:30
CAND(8): Tripa Longaaaaaaaaaaaaaaaa, Nota:8, Idade:30
CAND(1): Poko Loko, Nota:7, Idade:20
CAND(11): Poko Lin, Nota:7, Idade:20
CAND(9): Chapo Lin, Nota:7, Idade:25
CAND(3): Thiago Oliveira, Nota:5, Idade:35
CAND(2): Chapo Loko, Nota:2, Idade:20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
void OrdenaCrescente(tCandidato * vet, int qtd);
int encontraMelhorCandidato(tCandidato vetor[], char tamanhoVetor, int i);

int main(){
    int qtdCand, i = 0;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];
    int ordemCrescente[qtdCand];

    for(i = 0; i < qtdCand; i++)
        candidatos[i] = LeCandidato();

    OrdenaCrescente(candidatos, qtdCand);

    for(i = 0; i < qtdCand; i++)
        ImprimeCandidato(candidatos[i]);

    return 0;
}

tCandidato LeCandidato(){
    tCandidato candidato;

    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");

    return candidato;
}

void ImprimeCandidato(tCandidato candidato){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente(tCandidato * vet, int qtd)
{
    int i, iMelhorCandidato;
    tCandidato candidatoFlutuante;

    for (i = 0; i < qtd; i++)
    {
        iMelhorCandidato = encontraMelhorCandidato(vet, qtd, i);
        candidatoFlutuante = vet[i];
        vet[i] = vet[iMelhorCandidato];
        vet[iMelhorCandidato] = candidatoFlutuante;
    }
}

int encontraMelhorCandidato(tCandidato vetor[], char tamanhoVetor, int i)
{
    int iMelhorCandidato = i, i2;

    for (i2 = i; i2 < tamanhoVetor; i2++)
    {
        if (vetor[i2].nota > vetor[iMelhorCandidato].nota)
            iMelhorCandidato = i2;
        else if (vetor[i2].nota == vetor[iMelhorCandidato].nota && vetor[i2].idade < vetor[iMelhorCandidato].idade)
            iMelhorCandidato = i2;
        else if (vetor[i2].nota == vetor[iMelhorCandidato].nota && vetor[i2].idade == vetor[iMelhorCandidato].idade && vetor[i2].codigo < vetor[iMelhorCandidato].codigo)
            iMelhorCandidato = i2;
    }

    return iMelhorCandidato;
}

void ConcatenaString(char * str1, char * str2, char * strOut)
{
    int i = 0, i1 = 0, i2 = 0;

    bzero(strOut, 42);
    while(str1[i] != '\0')
    {
        strOut[i] = str1[i1];
        i++;
        i1++;
    }
    while(str2[i2] != '\0')
    {
        strOut[i] = str2[i2];
        i++;
        i2++;
    }
}
