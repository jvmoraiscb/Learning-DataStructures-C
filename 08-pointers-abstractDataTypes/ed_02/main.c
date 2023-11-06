/*
Objetivo: Treinar uso de strings, structs e alocação dinâmica!
Implemente um programa, no arquivo exercicio2.c, que defina um tipo estruturado Aluno
com os seguintes campos: char* nome; int matricula; float p1; float p2;
float p3;
Seu programa deve alocar espaço dinâmico para os alunos de uma Turma. A turma (definida
como um vetor de ponteiros para Alunos) deve ser alocada da seguinte forma:
Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));
Onde n é o número de alunos, que deve ser informado pelo teclado.
As informações dos alunos (nome, matrícula, etc.) também devem ser fornecidas pelo
teclado. Cada “aluno” deve ser alocado dinamicamente, assim como o seu nome. Você
lembra de como fazer alocação dinâmica de uma string fornecida pelo teclado? Se não, veja
os vídeos-aula que a professora gravou ou então o capítulo 7 do livro texto.
Depois que a turma (vetor de ponteiros para alunos) for carregada, imprima todos os dados
(um aluno por linha).
Para completar seu programa, implemente as seguintes funções:
• void imprime_aprovados (int n, Aluno** turma); //Imprime na tela os
alunos aprovados. O aluno é aprovado quando a média das 3 provas for maior ou
igual a 5; n é o números de alunos na turma.
• float media_turma (int n, Aluno** turma); //Retorna a média da turma
inteira; n é o número de alunos da turma.

Despois que os dados dos alunos aparecerem na tela, espera-se a lista de alunos aprovados
seguido pela média da turma.
Envie o arquivo exercicio2.c pelo Classroom!

Bom exercício!!!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno Aluno;

float Media_turma(int num_alunos, Aluno** turma);
Aluno* Constroi_aluno(char* nome, int matricula, float p1, float p2, float p3);
Aluno** Constroi_turma(int num_alunos);
void Libera_aluno(Aluno* aluno);
void Libera_turma(int num_alunos, Aluno** turma);
void Imprime_turma(int num_alunos, Aluno** turma);
void Imprime_aprovados(int num_alunos, Aluno** turma);

int main(){
    int num_alunos;
    scanf("%d", &num_alunos);
    
    Aluno** turma = Constroi_turma(num_alunos);
    Imprime_turma(num_alunos, turma);
    Imprime_aprovados(num_alunos, turma);
    Libera_turma(num_alunos, turma);
    return 0;
}

float Media_turma(int num_alunos, Aluno** turma){
    float media = 0;
    for(int i=0; i<num_alunos; i++){
        media += (turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3;
    }
    media = media/num_alunos;

    return media;
}

Aluno* Constroi_aluno(char* nome, int matricula, float p1, float p2, float p3){
    Aluno* aluno = malloc(sizeof(Aluno));

    aluno->matricula = matricula;
    aluno->p1 = p1;
    aluno->p2 = p2;
    aluno->p3 = p3;
    aluno->nome = malloc(sizeof(char)*(strlen(nome) + 1));
    strcpy(aluno->nome, nome);

    return aluno;
}

void Libera_aluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}

Aluno** Constroi_turma(int num_alunos){
    Aluno** turma = malloc(sizeof(Aluno*)*num_alunos);

    for(int i=0; i < num_alunos; i++){
        char nome[25];
        int matricula;
        float p1, p2, p3;

        scanf("%s%d%f%f%f", nome, &matricula, &p1, &p2, &p3);
        turma[i] = Constroi_aluno(nome, matricula, p1, p2, p3);
    }

    return turma;
}

void Libera_turma(int num_alunos, Aluno** turma){
    //int num_alunos = sizeof(turma)/sizeof(Aluno*);
    for(int i=0; i < num_alunos; i++){
        Libera_aluno(turma[i]);
    }
    free(turma);
}

void Imprime_turma(int num_alunos, Aluno** turma){
    printf("\n");
    printf("===========================\n");
    printf("    ALUNOS MATRICULADOS    \n");
    printf("===========================\n");

    for(int i=0; i<num_alunos; i++){
        printf("%d - %s (Notas: %.2f %.2f %.2f)\n", turma[i]->matricula, turma[i]->nome, turma[i]->p1, turma[i]->p2, turma[i]->p3);
    }
}
void Imprime_aprovados(int num_alunos, Aluno** turma){
    printf("\n");
    printf("============================\n");
    printf("      ALUNOS APROVADOS      \n");
    printf("============================\n");

    for(int i=0; i<num_alunos; i++){
        float media = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3;
        if(media >= 5)
            printf("%d %s\n", turma[i]->matricula, turma[i]->nome);
    }
    printf("\nA media da turma foi: %.2f\n", Media_turma(num_alunos, turma));
}