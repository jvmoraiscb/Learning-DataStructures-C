#if !defined(ALUNO_H)
#define ALUNO_H

typedef struct aluno Aluno;

float Media_turma(int num_alunos, Aluno** turma);
Aluno* Constroi_aluno(char* nome, int matricula, float p1, float p2, float p3);
Aluno** Constroi_turma(int num_alunos);
char* Retorna_nome_aluno(Aluno* aluno);
void Libera_aluno(Aluno* aluno);
void Libera_turma(int num_alunos, Aluno** turma);
void Imprime_turma(int num_alunos, Aluno** turma);
void Imprime_aprovados(int num_alunos, Aluno** turma);

#endif // ALUNO_H