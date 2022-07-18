/* 
(BOCA:L5_14) Problema: Dado o programa abaixo que lê candidatos de um
concurso, complete o programa para imprimir os candidatos com sobrenome
repetidos e na ordem de entrada. Não imprimir o mesmo candidato mais de uma
vez. OBS: Não usar funções da biblioteca string.h.
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
int ComparaString(char * str1, char * str2);
int main(){
int qtdCand, i = 0;
scanf("%d", &qtdCand);
tCandidato candidatos[qtdCand];
for(i = 0; i < qtdCand; i++){
candidatos[i] = LeCandidato();
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
 Saída: Candidatos com sobrenome repetidos e na mesma ordem de entrada de dados. Ver
detalhes de formato na função de impressão do candidato.
 Exemplo de Entrada:
10
{3, Oliveira, Thiago, 5, 35}
{5, Detal, Fulano, 10, 25}
{7, Oliveira, Anonimo, 10, 45}
{1, Loko, Poko, 7, 20}
{9, Lin, Chapo, 7, 20}
{4, Matica, Proble, 8, 30}
{11, Lin, Poko, 7, 20}
{8, Longaaaaaaaaaaaaaaaa, Tripa, 8, 30}
{6, Seca, Tripa, 8, 30}
{2, Loko, Chapo, 2, 20}
 Exemplo de Saída:
CAND(3): Thiago Oliveira, Nota:5, Idade:35
CAND(7): Anonimo Oliveira, Nota:10, Idade:45
CAND(1): Poko Loko, Nota:7, Idade:20
CAND(2): Chapo Loko, Nota:2, Idade:20
CAND(9): Chapo Lin, Nota:7, Idade:20
CAND(11): Poko Lin, Nota:7, Idade:20
*/

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
int ComparaString(char * str1, char * str2);

int main(){
    int qtdCand, candidato;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];
    int candidatosImpressos[qtdCand];
    preencheVetor(candidatosImpressos, qtdCand);

    for(candidato = 0; candidato < qtdCand; candidato++)
        candidatos[candidato] = LeCandidato();

    candidato = 0;    
    for(candidato = 0; candidato < qtdCand; candidato++)
    {
        int v = 0, candidato2;
        for(candidato2 = candidato+1; candidato2 < qtdCand; candidato2++)
        {
            if ( ComparaString(candidatos[candidato].sobrenome, candidatos[candidato2].sobrenome) == 1){
                if (v == 0 && candidatosImpressos[candidato] == 0)
                {
                    ImprimeCandidato(candidatos[candidato]);
                    candidatosImpressos[candidato] = 1;
                }

                if(candidatosImpressos[candidato2] == 0)
                {
                    ImprimeCandidato(candidatos[candidato2]);
                    candidatosImpressos[candidato2] = 1;
                }
                v = 1;
            }
        }
    }

return 0;
}

tCandidato LeCandidato(){
    tCandidato candidato; //{codigo, sobrenome, nome, nota, idade}
    scanf("%*[^{]{%d, %[^,], %[^,], %d, %d}", &candidato.codigo, candidato.sobrenome, candidato.nome, &candidato.nota, &candidato.idade);

    //ImprimeCandidato(candidato);
    
return candidato;
}

void ImprimeCandidato(tCandidato candidato){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char * str1, char * str2)
{
    int i = 0, charDiferentes = 0;

    while(str1[i] != '\0' || str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            charDiferentes++;
        i++;
    }

    if (charDiferentes == 0)
        return 1;
    else
        return 0;
}

void preencheVetor(int vetor[], int tamanhoVetor)
{
    int i;

    for (i = 0; i < tamanhoVetor; i++)
    {
        vetor[i] = 0; 
    }
}