#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/aluno.h"

struct aluno{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

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

void Destroi_aluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}

int Cmp_nome_aluno(void* aluno, void* nome){
    return strcmp(((Aluno*)aluno)->nome, (char*)nome);
}
void Imprime_aluno(void* aluno){
    Aluno* aluno_temp = (Aluno*)aluno;
    printf("Nome:%s\nMatricula:%d\nP1:%.2f\nP2:%.2f\nP3:%.2f\n\n", aluno_temp->nome, aluno_temp->matricula, aluno_temp->p1, aluno_temp->p2, aluno_temp->p3);
}

char* Retorna_nome_aluno(Aluno* aluno){
    return aluno->nome;
}

int Retorna_matricula_aluno(Aluno* aluno){
    return aluno->matricula;
}

float Retorna_p1_aluno(Aluno* aluno){
    return aluno->p1;
}

float Retorna_p2_aluno(Aluno* aluno){
    return aluno->p2;
}

float Retorna_p3_aluno(Aluno* aluno){
    return aluno->p3;
}