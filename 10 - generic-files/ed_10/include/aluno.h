#if !defined(ALUNO_H)
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* Constroi_aluno(char* nome, int matricula, float p1, float p2, float p3);
void Destroi_aluno(Aluno* aluno);

int Cmp_nome_aluno(void* aluno, void* nome);
void Imprime_aluno(void* aluno);

char* Retorna_nome_aluno(Aluno* aluno);
int Retorna_matricula_aluno(Aluno* aluno);
float Retorna_p1_aluno(Aluno* aluno);
float Retorna_p2_aluno(Aluno* aluno);
float Retorna_p3_aluno(Aluno* aluno);

#endif // ALUNO_H