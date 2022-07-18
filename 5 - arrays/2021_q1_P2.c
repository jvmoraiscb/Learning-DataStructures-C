/* 
Instruções gerais: A prova tem o objetivo de avaliar os conceitos ensinados e trabalhados
até o momento. Ela deve ser feita individualmente e sem ajuda de terceiros. Casos de cola,
terceirização, ajuda para fazer a avaliação ou qualquer outro que beneficie o aluno de forma
indevida serão tratados com a penalidade máxima disponível na instituição (i.e., atribuição da
nota zero e abertura de processo administrativo podendo levar a expulsão). A penalidade será
aplicada com igual teor a todos os envolvidos e sem distinção (inclusive a quem fornecer).
Siga as regras e faça sua própria prova usando os conceitos ensinados em sala. Boa prova!
Valor: 5 pontos
Correção: a questão está dividida em 4 partes de teste, A, B, C e D, sendo que a complexidade
dos casos aumenta com as letras. Os casos das letras posteriores contemplam os casos das
anteriores e mais alguns. Por exemplo, os casos de B contemplam os de A, os de C contemplam
os de A e B e, assim por diante. Portanto, se resolver a parte D, resolveu toda a questão. Todas
as partes possuem casos de teste ocultos não fornecidos com a questão. O Anexo I descreve
os tipos de casos com mais detalhes. O aluno ganha os pontos totais se obtiver o balão na
parte D (que inclui todos os casos) e ganha 40%, 60% e 80% se passar somente até a parte A,
B, C ou D, respectivamente. A questão a ser corrigida será a última enviada, dando prioridade
a que estiver correta. Portanto, sempre envie a sua solução para as duas partes.
(BOCA: P2_2021_Q1) Sua tarefa é descobrir a posição inicial e final das palavras de
uma certa lista em um caça-palavras.
Informações importantes:
● O número máximo de palavras em uma lista de palavras é 30.
● Cada palavra tem, no máximo, 40 letras, sem espaços nem caracteres especiais.
● O caça-palavras é uma matriz de no máximo 50 linhas e 60 colunas.
● Não haverá repetições, nem na lista de palavras, nem dentro do caça-palavras,
porém pode acontecer de palavras da lista não estarem no caça-palavras (i.e., cada
palavra da lista aparece zero vezes ou uma vez no caça-palavra).
● Todas as letras do caça-palavras e das palavras da lista são maiúsculas, sempre.
Entrada: o arquivo de entrada começa com o caça-palavras, sendo cada linha da matriz
dada em uma linha da entrada. Os caracteres são dados sem espaço. O fim do caça
palavras é determinado por uma linha com o caractere “#”. Em seguida, é dada a lista de
palavras, sendo uma palavra por linha enquanto houver palavras.
Saída: a saída deverá conter as palavras da lista, sendo cada uma em uma linha, na mesma
ordem em que aparecem no arquivo de entrada. Cada palavra deverá ser seguida da linha
e coluna de início da palavra no caça-palavras (assumir linhas e colunas da matriz
iniciando em 1) e da linha e coluna de fim da palavra no caça-palavras. O formato de cada 
palavra da saída será: “@@@@@ - (Li, Ci) - (Lf, Cf)”, sendo @@@@@ a palavra
encontrada, Li a linha inicial da palavra, Ci a coluna inicial da palavra, Lf a linha final da
palavra e Cf a coluna final da palavra. Caso a palavra não esteja no caça-palavras, a
mensagem deverá ser apresentada da seguinte forma: “@@@@@ -NAO ENCONTRADA!”,
sendo @@@@@ a palavra não encontrada.
OBSERVAÇÃO: Implementação de livre escolha do aluno!
ANEXO I
A correção da questão será feita de forma incremental, onde cada caso de teste
apresentado cobra certos conceitos além do caso anterior, permitindo que a nota também
seja incremental. Os tipos de caso de teste se dividem em A, B, C e D e estão descritos
adiante.
(A) O Caça-Palavras pode conter palavras:
● Na horizontal da esquerda para direita (→);
● Na vertical de cima para baixo (↓).
Exemplo de entrada:
EWBLRNAATUAL
LIOAOGMRCRAS
NRATOLAETSBO
ATTATRREAEEU
PIVERMELHOTE
CEAVLHLDENTA
CIZEIROSADTE
LYUREAHPNIUD
UELDYOAREECN
OPRETOAIAEID
#
AMARELO
AZUL
PRETO
ROSA
ROXO
VERDE
VERMELHO
Saída esperada:
AMARELO - (1,7) - (7,7)
AZUL - (6,3) - (9,3)
PRETO - (10,2) - (10,6)
ROSA - (7,6) - (7,9)
ROXO - NAO ENCONTRADA!
VERDE - (6,4) - (10,4)
VERMELHO - (5,3) - (5,10)
OBS: Para melhor visualização, segue o Caça-Palavras correspondente ao exemplo.
Destacadas em cinza claro estão as palavras da lista presentes no Caça-Palavras, e em
cinza escuro suas posições de início e fim.
1 2 3 4 5 6 7 8 9 10 11 12
1 E W B L R N A A T U A L
2 L I O A O G M R C R A S
3 N R A T O L A E T S B O
4 A T T A T R R E A E E U
5 P I V E R M E L H O T E
6 C E A V L H L D E N T A
7 C I Z E I R O S A D T E
8 L Y U R E A H P N I U D
9 U E L D Y O A R E E C N
10 O P R E T O A I A E I D
(B) O Caça-Palavras pode conter palavras:
● Na horizontal da esquerda para direita (→);
● Na horizontal da direita para esquerda (←);
● Na vertical de cima para baixo (↓);
● Na vertical de baixo para cima (↑);
Exemplo de entrada:
XMENTHEGIFTED
ESRETSISTSORF
DRIBREDNUHTIO
AEOLFPASACSSC
OGLIOELIIRAIO
KYHNELARZISRN
AAOKTTJAIAINE
RPPESPILCERER
KAMETSAOPINFU
XVNIRCLPOYDNA
JETWISTISOBOL
HEISUCESSOBOA
PROVANOSSIELC
#
XMENTHEGIFTED
ANDY
LAUREN
ECLIPSE
POLARIS
THUNDERBIRD
BLINK
Saída esperada:
XMENTHEGIFTED - (1,1) - (1,13)
ANDY - (10,13) - (10,10)
LAUREN - (11,13) - (6,13)
ECLIPSE - (8,10) - (8,4)
POLARIS - (10,8) - (4,8)
THUNDERBIRD - (3,11) - (3,1)
BLINK - (3,4) - (7,4)
OBS: Para melhor visualização, segue o Caça-Palavras correspondente ao exemplo.
Destacadas em cinza claro estão as palavras da lista presentes no Caça-Palavras, e em
cinza escuro suas posições de início e fim.
1 2 3 4 5 6 7 8 9 10 11 12 13
1 X M E N T H E G I F T E D
2 E S R E T S I S T S O R F
3 D R I B R E D N U H T I O
4 A E O L F P A S A C S S C
5 O G L I O E L I I R A I O
6 K Y H N E L A R Z I S R N
7 A A O K T T J A I A I N E
8 R P P E S P I L C E R E R
9 K A M E T S A O P I N F U
10 X V N I R C L P O Y D N A
11 J E T W I S T I S O B O L
12 H E I S U C E S S O B O A
13 P R O V A N O S S I E L C
(C) O Caça-Palavras pode conter palavras:
● Na horizontal da esquerda para direita (→);
● Na horizontal da direita para esquerda (←);
● Na vertical de cima para baixo (↓);
● Na vertical de baixo para cima (↑);
● Na diagonal de cima para baixo e da esquerda para direita (↘).
Exemplo de entrada:
FOEESSRKAMAT
DELTORAQUEST
TEONCINTURAO
LKSALOPEDRAS
LUEMHEEETPTD
HFVAEIHBARDA
AENILRZVLIEF
RIRDFJASMINE
OIZAPOTLAMZC
EAITHYSADOCO
HSORABIRMASD
ROHPKUTRRRUB
IRNDAREEUTLS
LOURLLMEEBIF
LAPISLAZULIX
#
OURO
PRATA
BRONZE
DIAMANTE
ESMERALDA
LAPISLAZULI
TOPAZIO
OPALA
RUBI
AMETISTA
Saída esperada:
OURO - NAO ENCONTRADA!
PRATA - NAO ENCONTRADA!
BRONZE - NAO ENCONTRADA!
DIAMANTE - (8,4) - (1,4)
ESMERALDA - (3,2) - (11,10)
LAPISLAZULI - (15,1) - (15,11)
TOPAZIO - (9,7) - (9,1)
OPALA - (11,3) - (15,7)
RUBI - (12,8) - (15,11)
AMETISTA - (15,7) - (8,7)
OBS: Para melhor visualização, segue o Caça-Palavras correspondente ao exemplo.
Destacadas em cinza claro estão as palavras da lista presentes no Caça-Palavras, e em
cinza escuro suas posições de início e fim.
1 2 3 4 5 6 7 8 9 10 11 12
1 F O E E S S R K A M A T
2 D E L T O R A Q U E S T
3 T E O N C I N T U R A O
4 L K S A L O P E D R A S
5 L U E M H E E E T P T D
6 H F V A E I H B A R D A
7 A E N I L R Z V L I E F
8 R I R D F J A S M I N E
9 O I Z A P O T L A M Z C
10 E A I T H Y S A D O C O
11 H S O R A B I R M A S D
12 R O H P K U T R R R U B
13 I R N D A R E E U T L S
14 L O U R L L M E E B I F
15 L A P I S L A Z U L I X
(D) O Caça-Palavras pode conter palavras:
● Na horizontal da esquerda para direita (→);
● Na horizontal da direita para esquerda (←);
● Na vertical de cima para baixo (↓);
● Na vertical de baixo para cima (↑);
● Na diagonal de cima para baixo e da esquerda para direita (↘);
● Na diagonal de cima para baixo e da direita para a esquerda (↙);
● Na diagonal de baixo para cima e da esquerda para direita (↗);
● Na diagonal de baixo para cima e da direita para a esquerda (↖).
Exemplo de entrada:
GWNMHILHNMROORAIYT
ESLIREOTODAIUVCEEY
EEHLUCEMHENINJLGRR
DNUTTTNEEPTASIDOKE
TURKRHPEGDAHRCEBPT
TDPEANNFTHHNTLPRSE
MMOURHOARLIATNOCEP
AIDUERLTENRROENSEH
AFNIMEHOACLAFSREJM
ETIISITDWBIGGEOAEH
EWGSXHTOYVULNLCFLF
OAHNDANEASTTNAFSOI
OEPSMMUGUONERIOUOT
TEOSDEIGDNHEVEZPAT
AHTPETLUYCESTLEGDH
RAEEHVDLEHTUOTEYEY
#
POLVO
ABUTRE
ARANHA
FALCAO
GAVIAO
AGUIA
FORMIGA
VESPA
MOSQUITO
GUAXINIM
LEBRE
PANTERA
Saída esperada:
POLVO - (5,17) - (1,13)
ABUTRE - (9,9) - (14,14)
ARANHA - (9,12) - (4,12)
FALCAO - (9,13) - (9,8)
GAVIAO - (13,8) - (8,13)
AGUIA - NAO ENCONTRADA!
FORMIGA - (6,8) - (12,2)
VESPA - (16,6) - (12,2)
MOSQUITO - NAO ENCONTRADA!
GUAXINIM - (14,8) - (7,1)
LEBRE - NAO ENCONTRADA!
PANTERA - (4,10) - (10,16)
OBS: Para melhor visualização, segue o Caça-Palavras correspondente ao exemplo.
Destacadas em cinza claro estão as palavras da lista presentes no Caça-Palavras, e em
cinza escuro suas posições de início e fim.
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
1 G W N M H I L H N M R O O R A I Y T
2 E S L I R E O T O D A I U V C E E Y
3 E E H L U C E M H E N I N J L G R R
4 D N U T T T N E E P T A S I D O K E
5 T U R K R H P E G D A H R C E B P T
6 T D P E A N N F T H H N T L P R S E
7 M M O U R H O A R L I A T N O C E P
8 A I D U E R L T E N R R O E N S E H
9 A F N I M E H O A C L A F S R E J M
10 E T I I S I T D W B I G G E O A E H
11 E W G S X H T O Y V U L N L C F L F
12 O A H N D A N E A S T T N A F S O I
13 O E P S M M U G U O N E R I O U O T
14 T E O S D E I G D N H E V E Z P A T
15 A H T P E T L U Y C E S T L E G D H
16 R A E E H V D L E H T U O T E Y E Y
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char matriz[50][60];
    int iMax;
    int jMax;

}   tMatriz;

tMatriz retornaCacaPalavras();
void imprimeMatriz(tMatriz matriz);
void encontraPalavraNaMatriz(tMatriz matriz, char *palavra);

int main()
{
    tMatriz matriz;

    matriz = retornaCacaPalavras();
    //imprimeMatriz(matriz);

    char palavra[40];

    while(scanf("%39s", palavra) == 1)
    {
        encontraPalavraNaMatriz(matriz, palavra);
    }

    return 0;
}

tMatriz retornaCacaPalavras()
{
    tMatriz mapa;

    int iLinha = 0, iColuna;
    char c;

    while (1)
    {
        scanf("%c", &c);
        if(c == '#')
            break;
        mapa.matriz[iLinha][0] = c;
        iColuna = 1;

        while(1)
        {
            scanf("%c", &c);
            if(c == '\n')
                break;

            mapa.matriz[iLinha][iColuna] = c;
            iColuna++;
        }

        iLinha++;
    }
    scanf("%*c");

    mapa.iMax = iLinha;
    mapa.jMax= iColuna;

    return mapa;
}

void imprimeMatriz(tMatriz matriz)
{
    int i, j;

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
            printf("%c", matriz.matriz[i][j]);
        printf("\n");
    }
}

void encontraPalavraNaMatriz(tMatriz matriz, char *palavra)
{
    int i, j;
    int palavraEstaPresente = 0, tamanhoPalavra = strlen(palavra);

    for(i = 0; i < matriz.iMax; i++)
    {
        for(j = 0; j < matriz.jMax; j++)
        {
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i+1][j] == palavra[1]) // cima p/ baixo
            {
                int iLinha, iPalavra = 0, qtdLetrasIguais = 0;
                for(iLinha = i; iLinha < i+tamanhoPalavra; iLinha++)
                {
                    if(matriz.matriz[iLinha][j] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, iLinha, j+1);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i-1][j] == palavra[1]) // baixo p/ cima 
            {
                int iLinha, iPalavra = 0, qtdLetrasIguais = 0;
                for(iLinha = i; iLinha > i - tamanhoPalavra; iLinha--)
                {
                    if(matriz.matriz[iLinha][j] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, iLinha+2, j+1);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i][j+1] == palavra[1]) // esquerda p/ direita
            {
                int iColuna, iPalavra = 0, qtdLetrasIguais = 0;
                for(iColuna = j; iColuna < j+tamanhoPalavra; iColuna++)
                {
                    if(matriz.matriz[i][iColuna] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, i+1, iColuna);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i][j-1] == palavra[1]) // direita p/ esquerda
            {
                int iColuna = j, iPalavra = 0, qtdLetrasIguais = 0;
                for(iColuna; iColuna > j-tamanhoPalavra; iColuna--)
                {
                    if(matriz.matriz[i][iColuna] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, i+1, iColuna+2);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i+1][j+1] == palavra[1]) // diagonal p/ baixo e direita
            {
                int iLinha, iColuna = j, iPalavra = 0, qtdLetrasIguais = 0;
                for(iLinha = i; iLinha < i+tamanhoPalavra; iLinha++)
                {
                    if(matriz.matriz[iLinha][iColuna] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                    iColuna++;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, iLinha, iColuna);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i-1][j-1] == palavra[1]) // diagonal p/ cima e esquerda
            {
                int iLinha, iColuna = j, iPalavra = 0, qtdLetrasIguais = 0;
                for(iLinha = i; iLinha > i-tamanhoPalavra; iLinha--)
                {
                    if(matriz.matriz[iLinha][iColuna] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                    iColuna--;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, iLinha+2, iColuna+2);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i-1][j+1] == palavra[1]) // diagonal p/ baixo e esquerda
            {
                int iLinha, iColuna = j, iPalavra = 0, qtdLetrasIguais = 0;
                for(iLinha = i; iLinha > i-tamanhoPalavra; iLinha--)
                {
                    if(matriz.matriz[iLinha][iColuna] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                    iColuna++;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, iLinha+2, iColuna);
                }
            }
            if(matriz.matriz[i][j] == palavra[0] && matriz.matriz[i+1][j-1] == palavra[1]) // diagonal p/ cima e direita
            {
                int iLinha, iColuna = j, iPalavra = 0, qtdLetrasIguais = 0;
                for(iLinha = i; iLinha < i+tamanhoPalavra; iLinha++)
                {
                    if(matriz.matriz[iLinha][iColuna] == palavra[iPalavra])
                        qtdLetrasIguais++;
                    iPalavra++;
                    iColuna--;
                }
                if(qtdLetrasIguais == tamanhoPalavra)
                {
                    palavraEstaPresente = 1;
                    printf("%s - (%d,%d) - (%d,%d)\n", palavra, i+1, j+1, iLinha, iColuna+2);
                }
            }
        }
    }

    if(palavraEstaPresente == 0)
        printf("%s - NAO ENCONTRADA!\n", palavra);
}