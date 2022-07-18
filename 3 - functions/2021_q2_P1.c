/* 
Valor: 5 pontos
Correção: a questão está dividida em duas partes, a e b. A parte a contempla somente os
casos visíveis, enquanto a parte b também inclui casos escondidos. O aluno ganha os
pontos totais se obtiver o balão na parte b (que também inclui os casos de teste da parte
a) e ganha 40% se passar somente na parte a. A questão a ser corrigida será a última
enviada, dando prioridade a que estiver correta. Portanto, sempre envie a sua solução
para as duas partes.
Restrições: não é permitido utilizar recursos ainda além dos ensinados até o momento.
Por exemplo, não é permitido utilizar vetores, matrizes, strings, entre outros recursos
que são temas de aulas futuras.
(BOCA: P1_2021_Q2) Problema: Um site especializado em críticas de filmes
contratou você para um trabalho de fazer um programa. O objetivo é contabilizar e
gerar estatísticas dos filmes avaliados durante um período de tempo. Os gêneros e os
filmes serão representados por três caracteres literais. Cada gênero pode ter vários
filmes, e cada filme pode ter várias críticas. Cada crítica possui uma nota dada pela
quantidade de estrelas em que ele foi avaliado (um número inteiro de 0 a 5). Seu
programa deve dizer: quais são os filmes com maior nota e com menor nota por
gênero, e pela classificação geral; qual é o filme mais popular; quantos filmes não
tiveram nenhuma crítica; qual é o melhor filme do gênero mais popular; qual é a
média da crítica por gênero; qual gênero possui a maior média.
Em caso de empate entre os filmes de maior nota e os de menor nota, o maior e o
menor são considerados os que apareceram primeiro. Considera-se o filme mais
popular aquele que houver a maior quantidade de críticas. Em caso de empate, o filme
mais popular é o que apareceu primeiro. Assuma que os valores das críticas irão de 0
a 5. Considera-se o gênero mais popular aquele que no total possui o maior número
de críticas. Em caso de empate, o gênero mais popular é o que apareceu primeiro.
Considera-se a média de cada gênero a soma de todas as críticas dividido pelo número
de críticas do Gênero. Essa divisão deve ser inteira. Em caso de empate das médias
dos gêneros, a maior média será a primeira que foi calculada. Assuma que as siglas,
tanto dos Gêneros quanto dos Filmes, são compostas por letras maiúsculas.
• Entrada: Um inteiro n representando a quantidade de gêneros de filmes. Em
seguida (a partir da linha seguinte), serão dados os gêneros em sequência.
Cada gênero será iniciado com o caractere ‘#’ e três caracteres que definem o
nome do Gênero no formato ‘#@@@’. Assuma que os gêneros não terão nomes
repetidos. Após o nome, na outra linha, vêm seus filmes, sendo um em cada
linha. Cada filme é dado por uma sigla de três caracteres que representam o
seu nome e uma lista com as notas das suas críticas. As notas são iniciadas e 
finalizadas com colchetes (‘[‘ e ‘]’) e são separadas por vírgulas. Cada gênero é
terminado com uma linha contendo apenas a sigla ‘FIM’. Os gêneros são
separados por uma linha vazia.
• Saída: Para cada gênero (separando os gêneros por uma linha vazia), a
identificação do filme com maior e o com menor notas, e a média do gênero.
Ao fim, a saída deve apresentar: a identificação do filme geral com maior nota;
o filme geral com menor nota; o filme mais popular; o gênero mais popular; o
gênero com a maior média truncada; o filme com a maior nota do gênero mais
popular; a quantidade de filmes que não possuem críticas. Para cada um dos
resultados anteriores, apresentar o respectivo valor entre parênteses. Veja
exemplos de formatação das entradas e saídas a seguir.
Exemplo de Entrada:
3
#ACT
AAT [2,4,3,5]
THA [1,5]
YUS [5,5]
FIM
#ROM
ATH []
TTT [1,4,5,1,1]
FIM
#FIC
UUU [5,4,5]
JHH [5,5,5,5]
VHS []
FIM
4
#COM
LOL [3,2,1,2,2,2]
FUN [2,2,5,3,1,3]
RSR [1,2,1,1]
FIM
#ACT
POW [3,3,4,4,5,3,4]
PEI [3,3,3,4,2]
BUM [4,4,5,3,2,4]
FIM
#FIC
PLU [5,4,5,2,3]
PLA [3,2,3]
ZUM [2]
FIM
#DRA
BUA [5,5,4,5,5,5,4]
CHU [4,4,3,4]
SAD []
FIM
2
#TER
BUU [1,1,2,3]
AAA [0,2,1]
AII [2,3,2,1]
FIM
#MUS
DOO [4,4,5,4,5,5]
REE []
MII [3,2,5,1,2,3]
FAA [1,2,4,4,5]
SOL [2,1,3]
LAA [4,5,4,4,5]
SII [1,2,2,2,1]
FIM
Exemplo de Saída:
FILME DO GENERO ACT COM MAIOR NOTA: AAT (5)
FILME DO GENERO ACT COM MENOR NOTA: THA (1)
MEDIA DO GENERO ACT: 3
FILME DO GENERO ROM COM MAIOR NOTA: TTT (5)
FILME DO GENERO ROM COM MENOR NOTA: TTT (1)
MEDIA DO GENERO ROM: 2
FILME DO GENERO FIC COM MAIOR NOTA: UUU (5)
FILME DO GENERO FIC COM MENOR NOTA: UUU (4)
MEDIA DO GENERO FIC: 4
FILME GERAL COM MAIOR NOTA: AAT (5)
FILME GERAL COM MENOR NOTA: THA (1)
FILME MAIS POPULAR: TTT (5 CRITICAS)
GENERO MAIS POPULAR: ACT (8 CRITICAS)
GENERO COM MAIOR MEDIA TRUNCADA: FIC (4)
FILME COM MAIOR NOTA DO GENERO MAIS POPULAR: AAT (5)
FILMES QUE NAO POSSUEM CRITICAS: 2
FILME DO GENERO COM COM MAIOR NOTA: FUN (5)
FILME DO GENERO COM COM MENOR NOTA: LOL (1)
MEDIA DO GENERO COM: 2
FILME DO GENERO ACT COM MAIOR NOTA: POW (5)
FILME DO GENERO ACT COM MENOR NOTA: PEI (2)
MEDIA DO GENERO ACT: 3
FILME DO GENERO FIC COM MAIOR NOTA: PLU (5)
FILME DO GENERO FIC COM MENOR NOTA: PLU (2)
MEDIA DO GENERO FIC: 3
FILME DO GENERO DRA COM MAIOR NOTA: BUA (5)
FILME DO GENERO DRA COM MENOR NOTA: CHU (3)
MEDIA DO GENERO DRA: 4
FILME GERAL COM MAIOR NOTA: FUN (5)
FILME GERAL COM MENOR NOTA: LOL (1)
FILME MAIS POPULAR: POW (7 CRITICAS)
GENERO MAIS POPULAR: ACT (18 CRITICAS)
GENERO COM MAIOR MEDIA TRUNCADA: DRA (4)
FILME COM MAIOR NOTA DO GENERO MAIS POPULAR: POW (5)
FILMES QUE NAO POSSUEM CRITICAS: 1
FILME DO GENERO TER COM MAIOR NOTA: BUU (3)
FILME DO GENERO TER COM MENOR NOTA: AAA (0)
MEDIA DO GENERO TER: 1
FILME DO GENERO MUS COM MAIOR NOTA: DOO (5)
FILME DO GENERO MUS COM MENOR NOTA: MII (1)
MEDIA DO GENERO MUS: 3
FILME GERAL COM MAIOR NOTA: DOO (5)
FILME GERAL COM MENOR NOTA: AAA (0)
FILME MAIS POPULAR: DOO (6 CRITICAS)
GENERO MAIS POPULAR: MUS (30 CRITICAS)
GENERO COM MAIOR MEDIA TRUNCADA: MUS (3)
FILME COM MAIOR NOTA DO GENERO MAIS POPULAR: DOO (5)
FILMES QUE NAO POSSUEM CRITICAS: 1
*/

#include <stdio.h>

int gNumCriticas, gMenorNota, gMaiorNota, gFilmesSemCritica = 0;

int RecebeCriticasDoFilme();

void main ()
{
    int genero, nGeneros, maiorNumCriticasGenero = 0, maiorMediaGenero = 0, filmeMaiorNotaGeral = 0, filmeMenorNotaGeral = 6, filmeMaiorNotaGeneroMaisPopular, numCriticasFilmeMaisPopular = -1;
    char l1Genero, l2Genero, l3Genero, l1GeneroMaisPopular, l2GeneroMaisPopular, l3GeneroMaisPopular, l1GeneroMaiorMedia, l2GeneroMaiorMedia, l3GeneroMaiorMedia;
    char l1FilmeMaiorNotaGeneroMaisPopular, l2FilmeMaiorNotaGeneroMaisPopular, l3FilmeMaiorNotaGeneroMaisPopular, l1FilmeMaiorNotaGeral, l2FilmeMaiorNotaGeral, l3FilmeMaiorNotaGeral, l1FilmeMenorNotaGeral, l2FilmeMenorNotaGeral, l3FilmeMenorNotaGeral, l1FilmeMaisPopular, l2FilmeMaisPopular, l3FilmeMaisPopular;

    scanf("%d", &nGeneros);
    scanf("%*c"); // \n

    for (genero = 1; genero <= nGeneros; genero++)
    {
        int mediaGenero = 0, numCriticas = 0;
        int notaFilme, menorNota, maiorNota, numFilmes = 0, maiorNotaFilme = 0, menorNotaFilme = 6;
        char l1Filme, l2Filme, l3Filme, l1FilmeMaiorNota, l2FilmeMaiorNota, l3FilmeMaiorNota, l1FilmeMenorNota, l2FilmeMenorNota, l3FilmeMenorNota;

        scanf("#%c%c%c", &l1Genero, &l2Genero, &l3Genero);
        scanf("%*c"); // \n
        while (1)
        {
            scanf("%c%c%c", &l1Filme, &l2Filme, &l3Filme);
            if (l1Filme == 'F' && l2Filme == 'I' && l3Filme == 'M'){
                scanf("%*c%*c"); // \n\n
                break;
            }
            scanf("%*c"); // espaco antes do []
            notaFilme = RecebeCriticasDoFilme();
            menorNota = gMenorNota;
            maiorNota = gMaiorNota;
            scanf("%*c"); // \n
            if (notaFilme >= 0){
                if (maiorNota > maiorNotaFilme)
                {
                    maiorNotaFilme = maiorNota;
                    l1FilmeMaiorNota = l1Filme;
                    l2FilmeMaiorNota = l2Filme;
                    l3FilmeMaiorNota = l3Filme;
                }
                if (menorNota < menorNotaFilme)
                {
                    menorNotaFilme = menorNota;
                    l1FilmeMenorNota = l1Filme;
                    l2FilmeMenorNota = l2Filme;
                    l3FilmeMenorNota = l3Filme;
                }
                if (maiorNota > filmeMaiorNotaGeral)
                {
                    filmeMaiorNotaGeral = maiorNota;
                    l1FilmeMaiorNotaGeral = l1Filme;
                    l2FilmeMaiorNotaGeral = l2Filme;
                    l3FilmeMaiorNotaGeral = l3Filme;
                }
                if (menorNota < filmeMenorNotaGeral)
                {
                    filmeMenorNotaGeral = menorNota;
                    l1FilmeMenorNotaGeral = l1Filme;
                    l2FilmeMenorNotaGeral = l2Filme;
                    l3FilmeMenorNotaGeral = l3Filme;
                }
                if (gNumCriticas > numCriticasFilmeMaisPopular)
                {
                    numCriticasFilmeMaisPopular = gNumCriticas;
                    l1FilmeMaisPopular = l1Filme;
                    l2FilmeMaisPopular = l2Filme;
                    l3FilmeMaisPopular = l3Filme;
                }
                mediaGenero += notaFilme;
                numCriticas += gNumCriticas;
            }
        }

        if (numCriticas > maiorNumCriticasGenero){
            maiorNumCriticasGenero = numCriticas;
            l1GeneroMaisPopular = l1Genero;
            l2GeneroMaisPopular = l2Genero;
            l3GeneroMaisPopular = l3Genero;

            l1FilmeMaiorNotaGeneroMaisPopular = l1FilmeMaiorNota;
            l2FilmeMaiorNotaGeneroMaisPopular = l2FilmeMaiorNota;
            l3FilmeMaiorNotaGeneroMaisPopular = l3FilmeMaiorNota;

            filmeMaiorNotaGeneroMaisPopular = maiorNotaFilme;
        }

        mediaGenero = mediaGenero / numCriticas;
        if (mediaGenero > maiorMediaGenero)
        {
            maiorMediaGenero = mediaGenero;
            l1GeneroMaiorMedia = l1Genero;
            l2GeneroMaiorMedia = l2Genero;
            l3GeneroMaiorMedia = l3Genero;
        }

        printf("FILME DO GENERO %c%c%c COM MAIOR NOTA: %c%c%c (%d)\n", l1Genero, l2Genero, l3Genero, l1FilmeMaiorNota, l2FilmeMaiorNota, l3FilmeMaiorNota, maiorNotaFilme);
        printf("FILME DO GENERO %c%c%c COM MENOR NOTA: %c%c%c (%d)\n", l1Genero, l2Genero, l3Genero, l1FilmeMenorNota, l2FilmeMenorNota, l3FilmeMenorNota, menorNotaFilme);
        printf("MEDIA DO GENERO %c%c%c: %d\n\n", l1Genero, l2Genero, l3Genero, mediaGenero);
    }

    printf("FILME GERAL COM MAIOR NOTA: %c%c%c (%d)\n", l1FilmeMaiorNotaGeral, l2FilmeMaiorNotaGeral, l3FilmeMaiorNotaGeral, filmeMaiorNotaGeral);
    printf("FILME GERAL COM MENOR NOTA: %c%c%c (%d)\n", l1FilmeMenorNotaGeral, l2FilmeMenorNotaGeral, l3FilmeMenorNotaGeral, filmeMenorNotaGeral);
    printf("FILME MAIS POPULAR: %c%c%c (%d CRITICAS)\n", l1FilmeMaisPopular, l2FilmeMaisPopular, l3FilmeMaisPopular, numCriticasFilmeMaisPopular);
    printf("GENERO MAIS POPULAR: %c%c%c (%d CRITICAS)\n", l1GeneroMaisPopular, l2GeneroMaisPopular, l3GeneroMaisPopular, maiorNumCriticasGenero);
    printf("GENERO COM MAIOR MEDIA TRUNCADA: %c%c%c (%d)\n", l1GeneroMaiorMedia, l2GeneroMaiorMedia, l3GeneroMaiorMedia, maiorMediaGenero);
    printf("FILME COM MAIOR NOTA DO GENERO MAIS POPULAR: %c%c%c (%d)\n", l1FilmeMaiorNotaGeneroMaisPopular, l2FilmeMaiorNotaGeneroMaisPopular, l3FilmeMaiorNotaGeneroMaisPopular, filmeMaiorNotaGeneroMaisPopular);
    printf("FILMES QUE NAO POSSUEM CRITICAS: %d", gFilmesSemCritica);
}

int RecebeCriticasDoFilme()
{
    int nota; char c;
    int numNotas = 0, somaNotas = 0, maiorNota = -1, menorNota = 6;
    
    gNumCriticas = 0; gMaiorNota = 0; gMenorNota = 0;

    scanf("[");
    while (1)
    {
        scanf("%c", &c);
        if (c >= '0' && c <= '5'){
            nota = c-48;
            if (nota > maiorNota)
                maiorNota = nota;
            if (nota < menorNota)
                menorNota = nota;
            somaNotas += nota;
            numNotas++;
        }
        else if (c == ',')
            continue;
        else
            break;
    }

    gNumCriticas = numNotas;
    gMaiorNota = maiorNota;
    gMenorNota = menorNota;

    if (numNotas > 0)
        return somaNotas;
    else{
        gFilmesSemCritica++;
        return -1;
    }
}