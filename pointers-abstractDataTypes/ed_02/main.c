// Joao Victor Morais - 04/05/2022

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