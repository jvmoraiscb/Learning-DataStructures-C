/* 
file: batalhaNaval_JoaoVictorMorais.c
author: Joao Victor Morais <jv.moraiscb@gmail.com>
version: 2.17
*/

#define VERTICAL 0
#define HORIZONTAL 1

#define tiroAgua -32 // em caso de necessidade de troca
#define qtdMaxNavios 20 // desses valores, alterar aqui!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct
{
    int id;
    int idUnico;
    int orientacao;
    int i;
    int j;
    char nome[15];

    int jogadaFoiAtingido;

} tNavio;

typedef struct
{
    int tirosErrados;
    int tirosAcertados;

    int qtdJogadas;
    int jogadasI[100];
    int jogadasJ[100];

} tEstatisticas;


typedef struct
{
    char nome[17];
    int tabuleiro[10][10];

    tNavio navios[qtdMaxNavios];
    int qtdNavios;

    tEstatisticas estatisticas;

} tJogador;

typedef struct
{
    tJogador jogador1;
    tJogador jogador2;

} tPartida;

tNavio preencheNavio(char *nomeNavio, int idNavio, int idUnico, int orientacaoNavio, int iNavio, int jNavio);
tNavio preencheJogadaFoiAtingido(tNavio navio, int jogadaFoiAtingido);
tEstatisticas preencheEstatisticas(int qtdTirosErradosJogador, int qtdTirosAcertadosJogador, int qtdJogadasJogador, int *jogadasJogadorI, int *jogadasJogadorJ);
tJogador preencheEstatisticasJogador(tJogador jogador, int qtdTirosErradosJogador, int qtdTirosAcertadosJogador, int qtdJogadasJogador, int *jogadasJogadorI, int *jogadasJogadorJ);
tJogador preencheJogador(char *diretorio, int nJogador);
tJogador preencheJogada(tJogador jogador, int iJogada, int jJogada, int nJogada);
tJogador atualizaJogador(tPartida partida, int nJogador);
tPartida preenchePartida(tJogador jogador1, tJogador jogador2);
tPartida realizaPartida(tPartida partida);
void imprimeNavio(tNavio navio);
void imprimeTipoNavio(tJogador jogador, int idNavio);
void imprimeNome(tJogador jogador);
void imprimeVencedor(tJogador jogador);
void imprimeTabuleiroAtual(tJogador tabuleiro, tJogador jogada);
void imprimeNaviosOrdemAlfabetica(tJogador jogador, char *arquivo);
void imprimeNaviosEstatisticas(tJogador jogador, int nome, char *arquivo);
void criaArquivoInicializacao(char *diretorio, tJogador jogador1, tJogador jogador2);
void criaArquivoEstatisticas(char *diretorio, tJogador jogador1, tJogador jogador2);
void criaArquivoResultado(char *diretorio, tJogador jogador1, tJogador jogador2);
void criaArquivoTabuleiroAleatorio(char *diretorio, int nJogador);
void preencheNomeNavio(char *nomeNavio, int idNome);
char retornaPosicaoI(int i);
int retornaPosicaoJ(int j);
int validaTabuleiro(char *diretorio);
int validaDiretorio(char *diretorio);
int validaId(tNavio *navios, int qtdNavios);
int validaJogada(char *jogada);
int verificaFimPartida(tPartida partida);
int verificaFimTabuleiro(tJogador jogador);
int verificaNaviosRestantes(tJogador jogador, int idNavio);
int obtemIntLetra(char letra);
int obtemId(tNavio navio);
int obtemIdUnico(tNavio navio);
int obtemPonto(tJogador jogador, int iJogada, int jJogada);
int obtemPosicaoNavioPeloID(tNavio *navios, int qtdNavios, int idNavio);
int obtemNomeNavio(tNavio navio);
int obtemJogadaFoiAtingido(tNavio navio);
int obtemTirosErrados(tEstatisticas estatisicas);
int obtemTirosAcertados(tEstatisticas estatisicas);
int obtemJogadaSorteada(int *numerosSorteados, int posicoesDisponiveis);
int preencheJogadasNaoDisponiveis(int *numerosSorteados, int posicoesDisponiveis, int numeroSorteado);
float obtemLocalizacaoMedia(tEstatisticas estatisicas, int iOUj);
float obtemDesvioPadraoLocalizacao(tEstatisticas estatisicas);

int main(int argc, char *argv[])
{   
    srand(time(0)); //define a geracao dos numeros aleatorios em funcao do tempo

    tJogador jogador1, jogador2;
    tPartida partida;

    char diretorio[1001];

    // caso o programa tenha sido iniciado sem parametros
    if(argc <= 1)
    {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }
    else
        strcpy(diretorio, argv[1]); // recebe o primeiro parametro como diretorio

    // caso o programa tenha sido iniciado com o primeiro parametro sendo "-gt"
    if(strcmp(diretorio, "-gt") == 0)
    {
        // caso o programa tenha sido iniciado sem o segundo parametro
        if(argc <= 2)
        {
            printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
            return 1;
        }
        else
            strcpy(diretorio, argv[2]); // recebe o segundo parametro como diretorio
    
        criaArquivoTabuleiroAleatorio(diretorio, 1);
        criaArquivoTabuleiroAleatorio(diretorio, 2);

        return 0;
    }

    if(validaDiretorio(diretorio) == 0) // verifica a existencia dos arquivos de tabuleiro
        return 2;

    if(validaTabuleiro(diretorio) == 0) // verifica se os tabuleiros sao validos
        return 3;

    jogador1 = preencheJogador(diretorio, 1);
    jogador2 = preencheJogador(diretorio, 2);

    criaArquivoInicializacao(diretorio, jogador1, jogador2);

    partida = preenchePartida(jogador1, jogador2);
    partida = realizaPartida(partida);

    jogador1 = atualizaJogador(partida, 1);
    jogador2 = atualizaJogador(partida, 2);
    
    criaArquivoEstatisticas(diretorio, jogador1, jogador2);
    criaArquivoResultado(diretorio, jogador1, jogador2);

    return 0;
}

tJogador preencheJogador(char *diretorio, int nJogador)
{
    int i, j, qtdNavios = 0;
    tJogador jogador;

    printf("Nome do Jogador %d:\n", nJogador);
    scanf("%s", jogador.nome);

    FILE * pTabuleiro;
    char arquivo[1001];

    sprintf(arquivo, "%s/tabu_%d.txt", diretorio, nJogador);
    pTabuleiro = fopen(arquivo,"r");

    for(i = 0; i < 10; i++) // define todas as casas do tabuleiro como agua
    {
        for(j = 0; j < 10; j++)
        {
            jogador.tabuleiro[i][j] = 0;
        }
    }

    int navio;
    char nomeNavio[20], posicaoiNavio; int idNavio, orientacaoNavio, iNavio, jNavio, idUnico;
    while (fscanf(pTabuleiro, "%[^;];%d;%d;%c%d%*c", nomeNavio, &idUnico, &orientacaoNavio, &posicaoiNavio, &jNavio) == 5)
    {
        qtdNavios++;
        idNavio = qtdNavios; // o id que sera representado no mapa recebe o numero atual do navio

        // converte as coordenadas de entrada para posicoes no vetor, ex: a10 --> 0-9 (valor uma unidade menor)
        iNavio = obtemIntLetra(posicaoiNavio)-1;
        jNavio = jNavio-1;
        
        jogador.navios[qtdNavios-1] = preencheNavio(nomeNavio, idNavio, idUnico, orientacaoNavio, iNavio, jNavio);

        if(strcmp(nomeNavio, "Carrier") == 0)
            navio = 5;
        if(strcmp(nomeNavio, "Battleship") == 0)
            navio = 4;
        if(strcmp(nomeNavio, "Cruiser") == 0)
            navio = 3;
        if(strcmp(nomeNavio, "Submarine") == 0)
            navio = 3;
        if(strcmp(nomeNavio, "Destroyer") == 0)
            navio = 2;

        for(i = 0; i < navio; i++) // preenche as casas com o id do navio: agua = 0 / navio > 0
        {
            if(orientacaoNavio == VERTICAL)
            {
                jogador.tabuleiro[iNavio+i][jNavio] = idNavio;
            }
            else if(orientacaoNavio == HORIZONTAL)
            {
                jogador.tabuleiro[iNavio][jNavio+i] = idNavio;
            }
        }
    }
    jogador.qtdNavios = qtdNavios;
    
    fclose(pTabuleiro);
    return jogador;
}

tJogador preencheJogada(tJogador jogador, int iJogada, int jJogada, int nJogada)
{
    if(jogador.tabuleiro[iJogada][jJogada] == 0) 
        jogador.tabuleiro[iJogada][jJogada] = tiroAgua;
        // caso o tiro caia na agua, a casa recebe o valor de tiroAgua, representando uma casa de agua que ja foi acertada
    else
    {
        int posicaoNavio = obtemPosicaoNavioPeloID(jogador.navios, jogador.qtdNavios, jogador.tabuleiro[iJogada][jJogada]);

        jogador.tabuleiro[iJogada][jJogada] *= -1;
        // caso o tiro acerte um navio, a casa recebe o id negativo do navio , representando que aquele id foi acertado
        
        if(obtemJogadaFoiAtingido(jogador.navios[posicaoNavio]) == 0)
            jogador.navios[posicaoNavio] = preencheJogadaFoiAtingido(jogador.navios[posicaoNavio], nJogada);
        // caso seja o primeiro tiro acertado nesse id, o navio guarda o numero da jogada para as estatisticas
    }

    return jogador;
}

tJogador preencheEstatisticasJogador(tJogador jogador, int qtdTirosErradosJogador, int qtdTirosAcertadosJogador, int qtdJogadasJogador, int *jogadasJogadorI, int *jogadasJogadorJ)
{
    jogador.estatisticas = preencheEstatisticas(qtdTirosErradosJogador, qtdTirosAcertadosJogador, qtdJogadasJogador, jogadasJogadorI, jogadasJogadorJ);

    return jogador;
}

tJogador atualizaJogador(tPartida partida, int nJogador)
{
    if(nJogador == 1)
        return partida.jogador1;
    if(nJogador == 2)
        return partida.jogador2;
}

tEstatisticas preencheEstatisticas(int qtdTirosErradosJogador, int qtdTirosAcertadosJogador, int qtdJogadasJogador, int *jogadasJogadorI, int *jogadasJogadorJ)
{
    tEstatisticas estatisticas;

    estatisticas.tirosErrados = qtdTirosErradosJogador;
    estatisticas.tirosAcertados = qtdTirosAcertadosJogador;
    estatisticas.qtdJogadas = qtdJogadasJogador;

    int i;
    for(i = 0; i < qtdJogadasJogador; i++)
    {
        estatisticas.jogadasI[i] = jogadasJogadorI[i];
        estatisticas.jogadasJ[i] = jogadasJogadorJ[i];
    }

    return estatisticas;
}

tNavio preencheNavio(char *nomeNavio, int idNavio, int idUnico, int orientacaoNavio, int iNavio, int jNavio)
{
    tNavio navio;

    strcpy(navio.nome, nomeNavio);
    navio.id = idNavio;
    navio.idUnico = idUnico;
    navio.orientacao = orientacaoNavio;
    navio.i = iNavio;
    navio.j = jNavio;
    navio.jogadaFoiAtingido = 0;

    return navio;
}

tNavio preencheJogadaFoiAtingido(tNavio navio, int jogadaFoiAtingido)
{
    navio.jogadaFoiAtingido = jogadaFoiAtingido;

    return navio;
}

tPartida preenchePartida(tJogador jogador1, tJogador jogador2)
{
    tPartida partida;

    partida.jogador1 = jogador1;
    partida.jogador2 = jogador2;

    return partida;
}

tPartida realizaPartida(tPartida partida)
{
    // valores que serao enviados para as estatisticas de cada jogador
    int qtdTirosErradosJogador1 = 0, qtdTirosAcertadosJogador1 = 0, qtdJogadasJogador1 = 0, jogadasJogador1i[100], jogadasJogador1j[100]; 

    int qtdTirosErradosJogador2 = 0, qtdTirosAcertadosJogador2 = 0, qtdJogadasJogador2 = 0, jogadasJogador2i[100], jogadasJogador2j[100];

    printf("\n");
    while(verificaFimPartida(partida) == 0)
    {
        int jogador, jogadaI, jogadaJ;
        char posicaoJogadaI;

        // sempre que, ao final da jogada do segundo jogador a partida nao acabar, ambos devem jogar novamente
        for(jogador = 1; jogador <= 2; jogador++) // garante que para cada jogador serao feitas as mesmas operacoes
        {
            char jogada[15]; // recebe a jogada em string para analisar se e uma jogada valida

            printf("Jogada de ");
            if(jogador == 1)
                    imprimeNome(partida.jogador1);
                if(jogador == 2)
                    imprimeNome(partida.jogador2);

            scanf("%s", jogada);

            while(1) // enquanto a jogada nao for valida, pede uma nova jogada
            {
                if(validaJogada(jogada) == 1) // caso as coordenadas sejam validas
                {
                    sscanf(jogada,"%c%d", &posicaoJogadaI, &jogadaJ);
                    jogadaI = obtemIntLetra(posicaoJogadaI) - 1;
                    jogadaJ = jogadaJ - 1;

                    if(jogador == 1)
                    {
                        if(obtemPonto(partida.jogador2, jogadaI, jogadaJ) >= 0) 
                            break; 
                    }
                    if(jogador == 2)
                    {
                        if(obtemPonto(partida.jogador1, jogadaI, jogadaJ) >= 0)
                            break; 
                    } // caso o ponto tenha valor negativo, a jogada ja foi feita anteriormente
                }

                printf("%s:Jogada invalida! Jogue novamente ", jogada);
                if(jogador == 1)
                    imprimeNome(partida.jogador1);
                if(jogador == 2)
                    imprimeNome(partida.jogador2);

                scanf("%s", jogada);
            }

            if(jogador == 1)
            {
                qtdJogadasJogador1++;
                jogadasJogador1i[qtdJogadasJogador1-1] = jogadaI;
                jogadasJogador1j[qtdJogadasJogador1-1] = jogadaJ;
                // as coordenadas das jogadas sao armazenadas para serem usadas no resultado

                partida.jogador2 = preencheJogada(partida.jogador2 ,jogadaI, jogadaJ, qtdJogadasJogador1);
                int ponto = obtemPonto(partida.jogador2, jogadaI, jogadaJ); // ponto recebe o valor da casa
                if(ponto == tiroAgua)
                {
                    printf("%s:Agua\n\n", jogada);
                    qtdTirosErradosJogador1++;
                }
                else
                {
                    if(ponto < 0 && verificaNaviosRestantes(partida.jogador2, ponto) == 1)
                    // caso ainda existam casas com id do navio observado que nao foram atingidas
                    {
                        printf("%s:Tiro!\n\n", jogada);
                    }
                    else if(ponto < 0 && verificaNaviosRestantes(partida.jogador2, ponto) == 0)
                    // caso nao existam, o navio foi afundado
                    {
                        printf("%s:Afundou ", jogada);
                        imprimeTipoNavio(partida.jogador2, ponto);
                    }
                    qtdTirosAcertadosJogador1++;
                }
            }
            if(jogador == 2)
            {
                qtdJogadasJogador2++;
                jogadasJogador2i[qtdJogadasJogador2-1] = jogadaI;
                jogadasJogador2j[qtdJogadasJogador2-1] = jogadaJ;
                // as coordenadas das jogadas sao armazenadas para serem usadas no resultado

                partida.jogador1 = preencheJogada(partida.jogador1 ,jogadaI, jogadaJ, qtdJogadasJogador2);
                int ponto = obtemPonto(partida.jogador1, jogadaI, jogadaJ); // ponto recebe o valor da casa
                if(ponto == tiroAgua)
                {
                    printf("%s:Agua\n\n", jogada);
                    qtdTirosErradosJogador2++;
                }
                else
                {
                    if(ponto < 0 && verificaNaviosRestantes(partida.jogador1, ponto) == 1) 
                    // caso ainda existam casas com id do navio observado que nao foram atingidas
                    {
                        printf("%s:Tiro!\n\n", jogada);
                    }
                    else if(ponto < 0 && verificaNaviosRestantes(partida.jogador1, ponto) == 0)
                    // caso nao existam, o navio foi afundado
                    {
                        printf("%s:Afundou ", jogada);
                        imprimeTipoNavio(partida.jogador1, ponto);
                    }
                    qtdTirosAcertadosJogador2++;
                }
            }
            if(jogador == 1)
                imprimeTabuleiroAtual(partida.jogador2, partida.jogador1);
            if(jogador == 2)
                imprimeTabuleiroAtual(partida.jogador1, partida.jogador2);
        }
    }
    if(verificaFimTabuleiro(partida.jogador1) == 1 && verificaFimTabuleiro(partida.jogador2) == 1)
        printf("Empate\n");
    else if(verificaFimTabuleiro(partida.jogador1) == 1 && verificaFimTabuleiro(partida.jogador2) == 0)
        imprimeVencedor(partida.jogador2);
    else if(verificaFimTabuleiro(partida.jogador1) == 0 && verificaFimTabuleiro(partida.jogador2) == 1)
        imprimeVencedor(partida.jogador1);

    // cada jogador recebe suas estatisticas finais
    partida.jogador1 = preencheEstatisticasJogador(partida.jogador1, qtdTirosErradosJogador1, qtdTirosAcertadosJogador1, qtdJogadasJogador1, jogadasJogador1i, jogadasJogador1j);
    partida.jogador2 = preencheEstatisticasJogador(partida.jogador2, qtdTirosErradosJogador2, qtdTirosAcertadosJogador2, qtdJogadasJogador2, jogadasJogador2i, jogadasJogador2j);

    return partida;
}

char retornaPosicaoI(int i)
{
    i = i+1 + 96; // ex: a --> 1

    return i;
}

int retornaPosicaoJ(int j)
{
    j = j+1; // ex: 0 --> 1

    return j;
}

int validaDiretorio(char *diretorio)
{
    FILE * pTabuleiro; FILE * pTabuleiro2;
    char arquivo1[1000], arquivo2[1000];

    sprintf(arquivo1, "%s/tabu_1.txt", diretorio);
    pTabuleiro = fopen(arquivo1,"r");

    if(!pTabuleiro)
    {
        printf("ERRO: Nao foi possivel ler o arquivo \"%s\"\n", arquivo1);
        return 0;
    }

    fclose(pTabuleiro);

    sprintf(arquivo2, "%s/tabu_2.txt", diretorio);
    pTabuleiro2 = fopen(arquivo2,"r"); 

    if(!pTabuleiro2)
    {
        printf("ERRO: Nao foi possivel ler o arquivo \"%s\"\n", arquivo2);
        return 0;
    }

    fclose(pTabuleiro2);

    return 1;
}

int validaTabuleiro(char *diretorio)
{
    int errosTabuleiro1, qtdNaviosTabuleiro1, qtdCarrierTabuleiro1, qtdBattleshipTabuleiro1, qtdCruiserTabuleiro1, qtdSubmarineTabuleiro1, qtdDestroyerTabuleiro1; 

    int errosTabuleiro2, qtdNaviosTabuleiro2, qtdCarrierTabuleiro2, qtdBattleshipTabuleiro2, qtdCruiserTabuleiro2, qtdSubmarineTabuleiro2, qtdDestroyerTabuleiro2;
    // todas as estatisticas de ambos os tabuleiros devem ser iguais, e a quantidade de erros deve ser 0

    int tabuleiro;

    for(tabuleiro = 1; tabuleiro <= 2; tabuleiro++) // verificacao se repete para os dois tabuleiros
    {
        // tabuleiro maior do que o necessario para que as bordas sejam preenchidas por 0
        int i, j, tabuleiroTeste[12][12], errosTabuleiro = 0;
        int qtdNavios = 0, qtdCarrier = 0, qtdBattleship = 0, qtdCruiser = 0, qtdSubmarine = 0, qtdDestroyer = 0;

        FILE * pTabuleiro;
        char arquivo[1001];

        if(tabuleiro == 1)
            sprintf(arquivo, "%s/tabu_1.txt", diretorio);
        else if(tabuleiro == 2)
            sprintf(arquivo, "%s/tabu_2.txt", diretorio);

        pTabuleiro = fopen(arquivo,"r");

        for(i = 0; i < 12; i++)
        {
            for(j = 0; j < 12; j++)
            {
                tabuleiroTeste[i][j] = 0; // todas as casas sao preenchidas por 0
            }
        }
        // verifica e insere no tabuleiro de teste cada navio
        int navio;
        tNavio navios[qtdMaxNavios];
        char nomeNavio[20], posicaoiNavio; int idNavio, idUnico, orientacaoNavio, iNavio, jNavio;
        while (fscanf(pTabuleiro, "%[^;];%d;%d;%c%d%*c", nomeNavio, &idUnico, &orientacaoNavio, &posicaoiNavio, &jNavio) == 5)
        {
            qtdNavios++;
            idNavio = qtdNavios; // o id que sera representado no mapa recebe o numero atual do navio
            navios[qtdNavios-1] = preencheNavio(nomeNavio, idNavio, idUnico, orientacaoNavio, iNavio, jNavio);

            iNavio = obtemIntLetra(posicaoiNavio);
            jNavio = jNavio;

            if(orientacaoNavio != VERTICAL && orientacaoNavio != HORIZONTAL) // verifica se a orientacao e valida
                errosTabuleiro++;

            if(validaId(navios, qtdNavios) == 0) // verifica se ja existe outro barco com o mesmo id
                errosTabuleiro++;
        
            // verifica se a coordenada colocada extrapola o tamanho do tabuleiro
            if(iNavio < 1 || iNavio > 10)
                errosTabuleiro++;
            if(jNavio < 1 || jNavio > 10)
                errosTabuleiro++;

            // verifica se o navio nao extrapola o tamanho do tabuleiro
            if(strcmp(nomeNavio, "Carrier") == 0)
            {
                navio = 5;
                if(orientacaoNavio == VERTICAL && iNavio > 6 || orientacaoNavio == HORIZONTAL && jNavio > 6)
                    errosTabuleiro++;
                qtdCarrier++;
            }
            else if(strcmp(nomeNavio, "Battleship") == 0)
            {
                navio = 4;
                if(orientacaoNavio == VERTICAL && iNavio > 7 || orientacaoNavio == HORIZONTAL && jNavio > 7)
                    errosTabuleiro++;
                qtdBattleship++;
            }
            else if(strcmp(nomeNavio, "Cruiser") == 0)
            {
                navio = 3;
                if(orientacaoNavio == VERTICAL && iNavio > 8 || orientacaoNavio == HORIZONTAL && jNavio > 8)
                    errosTabuleiro++;
                qtdCruiser++;
            }
            else if(strcmp(nomeNavio, "Submarine") == 0)
            {    
                navio = 3;
                if(orientacaoNavio == VERTICAL && iNavio > 8 || orientacaoNavio == HORIZONTAL && jNavio > 8)
                    errosTabuleiro++;
                qtdSubmarine++;
            }
            else if(strcmp(nomeNavio, "Destroyer") == 0)
            {
                navio = 2;
                if(orientacaoNavio == VERTICAL && iNavio > 9 || orientacaoNavio == HORIZONTAL && jNavio > 9)
                    errosTabuleiro++;
                qtdDestroyer++;
            }
            else
                errosTabuleiro++;

            /* verifica se o navio nao encosta em outros navios ja colocados, sendo considerado valido caso se posicione assim:
                          0 0 0
               0 0 0 0    0 X 0
               0 X X 0    0 X 0
               0 0 0 0 ou 0 0 0 onde navio = X e agua = 0
            */
            for(i = 0; i < navio; i++)
            {
                if(orientacaoNavio == VERTICAL)
                {
                    if(tabuleiroTeste[iNavio+i][jNavio] != 0) // verifica as posicoes ao lado
                        errosTabuleiro++;
                    tabuleiroTeste[iNavio+i][jNavio] = idNavio;
        
                    if(tabuleiroTeste[iNavio+i][jNavio-1] != 0 || tabuleiroTeste[iNavio+i][jNavio+1] != 0)
                        errosTabuleiro++;
                    // caso seja a primeira casa, verifica todas as posicoes
                    if(i == 0 && (tabuleiroTeste[iNavio+i-1][jNavio] != 0 || tabuleiroTeste[iNavio+i-1][jNavio-1] != 0 || tabuleiroTeste[iNavio+i-1][jNavio+1] != 0 || tabuleiroTeste[iNavio+i+1][jNavio] != 0 || tabuleiroTeste[iNavio+i+1][jNavio-1] != 0 || tabuleiroTeste[iNavio+i+1][jNavio+1] != 0) )
                        errosTabuleiro++;
                    // caso seja a ultima casa, verifica as proximas posicoes
                    if(i == navio-1 && (tabuleiroTeste[iNavio+i+1][jNavio] != 0 || tabuleiroTeste[iNavio+i+1][jNavio-1] != 0 || tabuleiroTeste[iNavio+i+1][jNavio+1] != 0) )
                        errosTabuleiro++;
                }
                else if(orientacaoNavio == HORIZONTAL)
                {
                    if(tabuleiroTeste[iNavio][jNavio+i] != 0) // verifica as posicoes ao lado
                        errosTabuleiro++;
                    tabuleiroTeste[iNavio][jNavio+i] = idNavio;

                    if(tabuleiroTeste[iNavio-1][jNavio+i] != 0 || tabuleiroTeste[iNavio+1][jNavio+i] != 0)
                        errosTabuleiro++;
                    // caso seja a primeira casa, verificar todas as posicoes
                    if(i == 0 && (tabuleiroTeste[iNavio][jNavio+i-1] != 0 || tabuleiroTeste[iNavio-1][jNavio+i-1] != 0 || tabuleiroTeste[iNavio+1][jNavio+i-1] != 0 || tabuleiroTeste[iNavio][jNavio+i+1] != 0 || tabuleiroTeste[iNavio-1][jNavio+i+1] != 0 || tabuleiroTeste[iNavio+1][jNavio+i+1] != 0) )
                        errosTabuleiro++;
                    // caso seja a ultima casa, verifica as proximas posicoes
                    if(i == navio-1 && (tabuleiroTeste[iNavio][jNavio+i+1] != 0 || tabuleiroTeste[iNavio-1][jNavio+i+1] != 0 || tabuleiroTeste[iNavio+1][jNavio+i+1] != 0) )
                        errosTabuleiro++;
                }
            }
        }
        fclose(pTabuleiro);
    
        // cada tabuleiro recebe suas estatisticas para verificar a compatibilidade dos tabuleiros
        if(tabuleiro == 1)
        {
            errosTabuleiro1 = errosTabuleiro;
            qtdNaviosTabuleiro1 = qtdNavios;
            qtdCarrierTabuleiro1 = qtdCarrier;
            qtdBattleshipTabuleiro1 = qtdBattleship;
            qtdCruiserTabuleiro1 = qtdCruiser;
            qtdSubmarineTabuleiro1 = qtdSubmarine;
            qtdDestroyerTabuleiro1 = qtdDestroyer;
        }
        else if(tabuleiro == 2)
        {
            errosTabuleiro2 = errosTabuleiro;
            qtdNaviosTabuleiro2 = qtdNavios;
            qtdCarrierTabuleiro2 = qtdCarrier;
            qtdBattleshipTabuleiro2 = qtdBattleship;
            qtdCruiserTabuleiro2 = qtdCruiser;
            qtdSubmarineTabuleiro2 = qtdSubmarine;
            qtdDestroyerTabuleiro2 = qtdDestroyer;
        }
    }

    FILE * pValidacaoTabuleiros;
    char arquivo[1001];

    sprintf(arquivo, "%s/saida/validacao_tabuleiros.txt", diretorio);

    pValidacaoTabuleiros = fopen(arquivo, "w");

    fprintf(pValidacaoTabuleiros, "tabu_1.txt;");
    if(errosTabuleiro1 == 0)
        fprintf(pValidacaoTabuleiros, "valido\n");
    else
        fprintf(pValidacaoTabuleiros, "invalido\n");

    fprintf(pValidacaoTabuleiros, "tabu_2.txt;");
    if(errosTabuleiro2 == 0)
        fprintf(pValidacaoTabuleiros, "valido");
    else
        fprintf(pValidacaoTabuleiros, "invalido");

    if(errosTabuleiro1 == 0 && errosTabuleiro2 == 0)
    {
        fprintf(pValidacaoTabuleiros, "\n");
        
        if(qtdNaviosTabuleiro1 == qtdNaviosTabuleiro2 && qtdCarrierTabuleiro1 == qtdCarrierTabuleiro2 && qtdBattleshipTabuleiro1 == qtdBattleshipTabuleiro2 && qtdCruiserTabuleiro1 == qtdCruiserTabuleiro2 && qtdSubmarineTabuleiro1 == qtdSubmarineTabuleiro2 && qtdDestroyerTabuleiro1 == qtdDestroyerTabuleiro2)
        {
            fprintf(pValidacaoTabuleiros, "Tabuleiros compativeis entre si");
            {
                fclose(pValidacaoTabuleiros);
                return 1;
            }
        }
        else
            fprintf(pValidacaoTabuleiros, "Tabuleiros incompativeis entre si");
    }
    
    fclose(pValidacaoTabuleiros);
    
    return 0;
}

int validaId(tNavio *navios, int qtdNavios)
{
    int i, posicaoNavioVerificado = qtdNavios-1;

    for(i = 0; i < posicaoNavioVerificado; i++)
    {
        if(obtemIdUnico(navios[posicaoNavioVerificado]) == obtemIdUnico(navios[i]))
        {
            return 0;
        }
    }

    return 1;
}

int validaJogada(char *jogada)
{
    int tamanhoJogada = strlen(jogada);

    if(tamanhoJogada < 2 || tamanhoJogada > 3) // as jogadas validas podem ter duas ou tres caracteres
        return 0;
    if(jogada[0] < 'a' || jogada[0] > 'j')
        return 0;
    
    if(tamanhoJogada == 2)
    {
        if(jogada[1] < '1' || jogada[1] > '9')
            return 0;
    }
    if(tamanhoJogada == 3)
    {
        if(jogada[1] != '1' || jogada[2] != '0')
            return 0;
    }

    return 1;
}

int verificaFimPartida(tPartida partida)
{
    if(verificaFimTabuleiro(partida.jogador1) == 1 || verificaFimTabuleiro(partida.jogador2) == 1)
        return 1;
    else
        return 0;
}

int verificaFimTabuleiro(tJogador jogador)
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(jogador.tabuleiro[i][j] > 0) // caso ainda tenham navios que nao foram atingidos (id > 0), o tabuleiro nao acabou
                return 0;
        }
    }

    return 1;
}

int verificaNaviosRestantes(tJogador jogador, int idNavio)
{
    int i, j;
    idNavio *= -1;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(jogador.tabuleiro[i][j] == idNavio)
                return 1;
        }
    }

    return 0;
}

int obtemId(tNavio navio)
{
    return navio.id;
}

int obtemIdUnico(tNavio navio)
{
    return navio.idUnico;
}

int obtemIntLetra(char letra)
{
    return letra - 96;
}

int obtemPonto(tJogador jogador, int iJogada, int jJogada)
{
    return jogador.tabuleiro[iJogada][jJogada];
}

int obtemPosicaoNavioPeloID(tNavio *navios, int qtdNavios, int idNavio)
{
    int i;

    for(i = 0; i < qtdNavios; i++)
    {
        if(navios[i].id == idNavio)
            return i;
    }
}

int obtemNomeNavio(tNavio navio)
{
    if(strcmp(navio.nome, "Carrier") == 0)
        return 5;
    if(strcmp(navio.nome, "Battleship") == 0)
        return 4;
    if(strcmp(navio.nome, "Cruiser") == 0)
        return 3;
    if(strcmp(navio.nome, "Submarine") == 0)
        return 2;
    if(strcmp(navio.nome, "Destroyer") == 0)
        return 1;
}

int obtemJogadaFoiAtingido(tNavio navio)
{
    return navio.jogadaFoiAtingido;
}

int obtemTirosErrados(tEstatisticas estatisticas)
{
    return estatisticas.tirosErrados;
}

int obtemTirosAcertados(tEstatisticas estatisticas)
{
    return estatisticas.tirosAcertados;
}

int obtemQtdJogadas(tEstatisticas estatisticas)
{
    return estatisticas.qtdJogadas;
}

int obtemJogadaSorteada(int *numerosSorteados, int posicoesDisponiveis)
{
    return numerosSorteados[rand () % posicoesDisponiveis]; // sorteia um numero dentre as posicoes que ainda estao disponiveis
}

float obtemLocalizacaoMedia(tEstatisticas estatisticas, int iOUj)
{
    int i;
    float soma = 0;

    if(iOUj == 0) // caso iOUj seja 0, a funcao entende que deve analisar as jogadas feitas no eixo i
    {
        for(i = 0; i < estatisticas.qtdJogadas; i++)
        {
            soma += estatisticas.jogadasI[i]+1;
        }
    }
    if(iOUj == 1) // caso iOUj seja 1, a funcao entende que deve analisar as jogadas feitas no eixo j
    {
        for(i = 0; i < estatisticas.qtdJogadas; i++)
        {
            soma += estatisticas.jogadasJ[i]+1;
        }
    }

    return soma/estatisticas.qtdJogadas;
}

float obtemDesvioPadraoLocalizacao(tEstatisticas estatisticas)
{
    int i;
    float soma = 0, valor;

    for(i = 0; i < estatisticas.qtdJogadas; i++)
    {
        float valorI = estatisticas.jogadasI[i]+1 - obtemLocalizacaoMedia(estatisticas, 0); 
        float valorJ = estatisticas.jogadasJ[i]+1 - obtemLocalizacaoMedia(estatisticas, 1);

        soma += valorI*valorI + valorJ*valorJ;
    }
    
    valor = 1.0 / estatisticas.qtdJogadas;

    return sqrt(valor*soma);
}

void criaArquivoInicializacao(char *diretorio, tJogador jogador1, tJogador jogador2)
{
    int i, j;
    FILE * pInicializacao;
    char arquivo[1001];

    sprintf(arquivo, "%s/saida/inicializacao.txt", diretorio);
    pInicializacao = fopen(arquivo, "w");

    fprintf(pInicializacao, "%s\n", jogador1.nome);
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(j == 0){
                if(jogador1.tabuleiro[i][j] == 0)
                    fprintf(pInicializacao, "o");
                else
                    fprintf(pInicializacao, "X");
            }
            else{
                if(jogador1.tabuleiro[i][j] == 0)
                    fprintf(pInicializacao, " o");
                else
                    fprintf(pInicializacao, " X");
            } 
        }
        fprintf(pInicializacao, "\n");
    }
    fprintf(pInicializacao, "\n");

    fprintf(pInicializacao, "%s\n", jogador2.nome);
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(j == 0){
                if(jogador2.tabuleiro[i][j] == 0)
                    fprintf(pInicializacao, "o");
                else
                    fprintf(pInicializacao, "X");
            }
            else{
                if(jogador2.tabuleiro[i][j] == 0)
                    fprintf(pInicializacao, " o");
                else
                    fprintf(pInicializacao, " X");
            }     
        }
        if(i < 9)
            fprintf(pInicializacao, "\n");
    }

    fclose(pInicializacao);
}

void criaArquivoEstatisticas(char *diretorio, tJogador jogador1, tJogador jogador2)
{
    FILE * pEstatisticas;
    char arquivo[1000];

    sprintf(arquivo, "%s/saida/estatisticas.txt", diretorio);
    pEstatisticas = fopen(arquivo, "w");

    fprintf(pEstatisticas, "%s\n", jogador1.nome);
    fprintf(pEstatisticas, "Tiros Errados: %d\n", obtemTirosErrados(jogador1.estatisticas));
    fprintf(pEstatisticas, "Tiros Acertados: %d\n", obtemTirosAcertados(jogador1.estatisticas));
    fprintf(pEstatisticas, "Localizacao Media: (%.2f,%.2f)\n", obtemLocalizacaoMedia(jogador1.estatisticas, 0), obtemLocalizacaoMedia(jogador1.estatisticas, 1));
    fprintf(pEstatisticas, "Desvio Padrao da Localizacao: %.2f\n", obtemDesvioPadraoLocalizacao(jogador1.estatisticas));
    fprintf(pEstatisticas, "Navios de %s:\n", jogador1.nome);

    fclose(pEstatisticas);
    imprimeNaviosOrdemAlfabetica(jogador1, arquivo); // imprime os navios que foram acertados

    pEstatisticas = fopen(arquivo, "a");
    fprintf(pEstatisticas, "\n");

    fprintf(pEstatisticas, "%s\n", jogador2.nome);
    fprintf(pEstatisticas, "Tiros Errados: %d\n", obtemTirosErrados(jogador2.estatisticas));
    fprintf(pEstatisticas, "Tiros Acertados: %d\n", obtemTirosAcertados(jogador2.estatisticas));
    fprintf(pEstatisticas, "Localizacao Media: (%.2f,%.2f)\n", obtemLocalizacaoMedia(jogador2.estatisticas, 0), obtemLocalizacaoMedia(jogador2.estatisticas, 1));
    fprintf(pEstatisticas, "Desvio Padrao da Localizacao: %.2f\n", obtemDesvioPadraoLocalizacao(jogador2.estatisticas));
    fprintf(pEstatisticas, "Navios de %s:\n", jogador2.nome);

    fclose(pEstatisticas);
    imprimeNaviosOrdemAlfabetica(jogador2, arquivo); // imprime os navios que foram acertados

}

void criaArquivoResultado(char *diretorio, tJogador jogador1, tJogador jogador2)
{
    FILE * pResultado;
    char arquivo[1000];
    int i0, posicaoI, posicaoJ;
    char i; int j;

    tEstatisticas estatisticasJogador1, estatisticasJogador2;

    estatisticasJogador1 = jogador1.estatisticas;
    estatisticasJogador2 = jogador2.estatisticas;

    sprintf(arquivo, "%s/saida/resultado.txt", diretorio);
    pResultado = fopen(arquivo, "w");

    fprintf(pResultado, "%s\n", jogador1.nome);

    // verifica todas as jogadas feitas na partida e o que elas acertaram
    for(i0 = 0; i0 < obtemQtdJogadas(jogador1.estatisticas); i0++)
    {
        posicaoI = estatisticasJogador1.jogadasI[i0];
        posicaoJ = estatisticasJogador1.jogadasJ[i0];

        i = retornaPosicaoI(posicaoI);
        j = retornaPosicaoJ(posicaoJ);

        if(jogador2.tabuleiro[posicaoI][posicaoJ] == tiroAgua) // caso tenha acertado a agua
            fprintf(pResultado, "%c%d - Agua\n", i, j);
        else if(jogador2.tabuleiro[posicaoI][posicaoJ] < 0) // caso tenha acertado um navio
        {
            int idNavio = jogador2.tabuleiro[posicaoI][posicaoJ] * -1; // id da casa retorna positivo para procurar o navio
            int posicaoNavio = obtemPosicaoNavioPeloID(jogador2.navios, jogador2.qtdNavios, idNavio);
            char nomeNavio[15];

            preencheNomeNavio(nomeNavio, obtemNomeNavio(jogador2.navios[posicaoNavio]));

            fprintf(pResultado, "%c%d - Tiro - %s - ID %02d\n", i, j, nomeNavio, obtemIdUnico(jogador2.navios[posicaoNavio]));
        }
    }
    fprintf(pResultado, "\n");

    fprintf(pResultado, "%s\n", jogador2.nome);

    // verifica todas as jogadas feitas na partida e o que elas acertaram
    for(i0 = 0; i0 < obtemQtdJogadas(jogador2.estatisticas); i0++)
    {
        posicaoI = estatisticasJogador2.jogadasI[i0];
        posicaoJ = estatisticasJogador2.jogadasJ[i0];

        i = retornaPosicaoI(posicaoI);
        j = retornaPosicaoJ(posicaoJ);

        if(jogador1.tabuleiro[posicaoI][posicaoJ] == tiroAgua) // caso tenha acertado a agua
            fprintf(pResultado, "%c%d - Agua\n", i, j);
        else if(jogador1.tabuleiro[posicaoI][posicaoJ] < 0) // caso tenha acertado um navio
        {
            int idNavio = jogador1.tabuleiro[posicaoI][posicaoJ] * -1; // id da casa retorna positivo para procurar o navio
            int posicaoNavio = obtemPosicaoNavioPeloID(jogador1.navios, jogador1.qtdNavios, idNavio); 
            char nomeNavio[15];

            preencheNomeNavio(nomeNavio, obtemNomeNavio(jogador1.navios[posicaoNavio]));

            fprintf(pResultado, "%c%d - Tiro - %s - ID %02d\n", i, j, nomeNavio, obtemIdUnico(jogador1.navios[posicaoNavio]));
        }
    }
    fprintf(pResultado, "\n");

    if(verificaFimTabuleiro(jogador1) == 1 && verificaFimTabuleiro(jogador2) == 1)
        fprintf(pResultado, "Empate");
    else if(verificaFimTabuleiro(jogador1) == 1 && verificaFimTabuleiro(jogador2) == 0)
        fprintf(pResultado, "Vencedor: %s", jogador2.nome);
    else if(verificaFimTabuleiro(jogador1) == 0 && verificaFimTabuleiro(jogador2) == 1)
        fprintf(pResultado, "Vencedor: %s", jogador1.nome);

    fclose(pResultado);
}

void criaArquivoTabuleiroAleatorio(char *diretorio, int nJogador)
{
    FILE * pTabuleiro;
    char arquivo[1000];
    int navio, tabuleiroTeste[10][10], numerosSorteados[100], posicoesDisponiveis = 100;
    int numeroTabuleiro;
    int i,j, num = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            // preenche cada casa do tabuleiro com um numero de 0-99 (para ser sorteado depois)
            tabuleiroTeste[i][j] = num;
            numerosSorteados[num] = num;
            num++;
        }
    }
    
    sprintf(arquivo, "%s/tabu_%d.txt", diretorio, nJogador);
    pTabuleiro = fopen(arquivo, "w");

    int posicao, tamanhoNavio, idNavio, orientacaoNavio, jNavio; char iNavio;
    char nomeNavio[15];
    for(navio = 0; navio < 5; navio++) // imprime um navio de cada tipo
    {
        orientacaoNavio = rand() % 2; // escolhe aleatoriamente a posicao entre 0-1

        if(navio == 0)
        {
            strcpy(nomeNavio, "Carrier");
            idNavio = 1;
            tamanhoNavio = 5;
        }
        if(navio == 1)
        {
            strcpy(nomeNavio, "Cruiser");
            idNavio = 2;
            tamanhoNavio = 3;
        }
        if(navio == 2)
        {
            strcpy(nomeNavio, "Battleship");
            idNavio = 3;
            tamanhoNavio = 4;
        }
        if(navio == 3)
        {
            strcpy(nomeNavio, "Destroyer");
            idNavio = 4;
            tamanhoNavio = 2;
        }
        if(navio == 4)
        {
            strcpy(nomeNavio, "Submarine");
            idNavio = 5;
            tamanhoNavio = 3;
        }

        int posicao, posicaoValida = 0;
        int i,j, iPosicao, jPosicao;

        while(posicaoValida == 0)
        {
            posicao = obtemJogadaSorteada(numerosSorteados, posicoesDisponiveis); // sorteia um numero dentro do vetor

            for(i = 0; i < 10; i++)
            {
                for(j = 0; j < 10; j++)
                {
                    if(tabuleiroTeste[i][j] == posicao) // encontra a casa que representa esse numero
                    {
                        // verifica se o navio nao extrapola o tamanho do tabuleiro
                        if((tamanhoNavio == 5 && orientacaoNavio == VERTICAL && i <= 5) || (tamanhoNavio == 4 && orientacaoNavio == VERTICAL && i <= 6) || (tamanhoNavio == 3 && orientacaoNavio == VERTICAL && i <= 7) || (tamanhoNavio == 2 && orientacaoNavio == VERTICAL && i <= 8))
                        {
                            int pedacosNavio = 0, i0;
                            for(i0 = 0; i0 < tamanhoNavio; i0++) // verifica se as casa que o navio ocupara estao disponiveis
                            {
                                int count;
                                for(count = 0; count < posicoesDisponiveis; count++) // verifica todas as casas disponiveis
                                {
                                    if(tabuleiroTeste[i+i0][j] == numerosSorteados[count])
                                        pedacosNavio++;
                                }
                            }
                            if(tamanhoNavio == pedacosNavio) // caso estejam disponiveis
                            {
                                posicaoValida = 1;
                                iPosicao = i;
                                jPosicao = j;
                            }  
                        }
                        // verifica se o navio nao extrapola o tamanho do tabuleiro
                        if((tamanhoNavio == 5 && orientacaoNavio == HORIZONTAL && j <= 5) || (tamanhoNavio == 4 && orientacaoNavio == HORIZONTAL && j <= 6) || (tamanhoNavio == 3 && orientacaoNavio == HORIZONTAL && j <= 7) || (tamanhoNavio == 2 && orientacaoNavio == HORIZONTAL && j <= 8))
                        {
                            int pedacosNavio = 0, i0;
                            for(i0 = 0; i0 < tamanhoNavio; i0++) // verifica se as casa que o navio ocupara estao disponiveis
                            {
                                int count;
                                for(count = 0; count < posicoesDisponiveis; count++)
                                {
                                    if(tabuleiroTeste[i][j+i0] == numerosSorteados[count]) // verifica todas as casas disponiveis
                                        pedacosNavio++;
                                }
                            }
                            if(tamanhoNavio == pedacosNavio) // caso estejam disponiveis
                            {
                                posicaoValida = 1;
                                iPosicao = i;
                                jPosicao = j;
                            }  
                        }
                    }
                }
            }
        }

        int i0;
        /* torna indisponivel todas as posicoes ocupadas pelo navio, inclusive as laterais para que os navios nao se encostem
        
        1 1 1              
        2 X 2
        2 X 2 
        3 3 3 --> navio = X / laterais = 1,2,3

        cada vez que uma casa e preenchida, a quantidade de posicoes disponiveis e diminuida
        */
        if(orientacaoNavio == VERTICAL)
        {
            for(i0 = 0; i0 < tamanhoNavio; i0++)
            {
                if(i0 == 0) // preenche as laterais 1
                {
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0-1][jPosicao-1]);

                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0-1][jPosicao]);
                        
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0-1][jPosicao+1]);
                }
                // preenche o navio e as laterais 2
                posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0][jPosicao-1]);

                posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0][jPosicao]);
                        
                posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0][jPosicao+1]);

                if(i0 == tamanhoNavio - 1) // preenche as laterais 3
                {
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0+1][jPosicao-1]);

                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0+1][jPosicao]);
                        
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+i0+1][jPosicao+1]);
                }
            }
        }
        /* torna indisponivel todas as posicoes ocupadas pelo navio, inclusive as laterais para que os navios nao se encostem
        
        1 2 2 3
        1 X X 3
        1 2 2 3 --> navio = X / laterais = 1,2,3

        cada vez que uma casa e preenchida, a quantidade de posicoes disponiveis e diminuida
        */
        if(orientacaoNavio == HORIZONTAL)
        {
            for(i0 = 0; i0 < tamanhoNavio; i0++)
            {
                if(i0 == 0) // preenche as laterais 1
                {
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao-1][jPosicao+i0-1]);

                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao][jPosicao+i0-1]);
                        
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+1][jPosicao+i0-1]); 
                }

                // preenche o navio e as laterais 2
                posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao-1][jPosicao+i0]);

                posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao][jPosicao+i0]);
                        
                posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+1][jPosicao+i0]);
                

                // preenche as laterais 3
                if(i0 == tamanhoNavio - 1)
                {
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao-1][jPosicao+i0+1]);

                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao][jPosicao+i0+1]);
                        
                    posicoesDisponiveis = preencheJogadasNaoDisponiveis(numerosSorteados, posicoesDisponiveis, tabuleiroTeste[iPosicao+1][jPosicao+i0+1]);
                }
                
            }
        }

        iNavio = retornaPosicaoI(iPosicao); // ex: 0 --> a
        jNavio = retornaPosicaoJ(jPosicao); // ex: 0 --> 1

        int idUnico = idNavio;
        fprintf(pTabuleiro, "%s;%d;%d;%c%d\n", nomeNavio, idUnico, orientacaoNavio, iNavio, jNavio);
    }

    fclose(pTabuleiro);
}

void imprimeNavio(tNavio navio)
{
    printf("%s\n\n", navio.nome);
}

void imprimeNome(tJogador jogador)
{
    printf("%s:\n\n", jogador.nome);
}

void imprimeVencedor(tJogador jogador)
{
    printf("Vencedor: %s\n", jogador.nome);
}

void imprimeTabuleiroAtual(tJogador tabuleiro, tJogador jogada)
{
    printf("Tabuleiro atual de %s apos a jogada de %s\n", tabuleiro.nome, jogada.nome);

    int i,j;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(j == 0){
                if(tabuleiro.tabuleiro[i][j] >= 0)
                    printf(".");
                else if (tabuleiro.tabuleiro[i][j] == tiroAgua)
                    printf("o");
                else
                    printf("X");
            }
            else{
                if(tabuleiro.tabuleiro[i][j] >= 0)
                    printf(" .");
                else if (tabuleiro.tabuleiro[i][j] == tiroAgua)
                    printf(" o");
                else
                    printf(" X");
            } 
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeTipoNavio(tJogador jogador, int idNavio)
{
    int i;

    for(i = 0; i < jogador.qtdNavios; i++)
    {
        if(obtemId(jogador.navios[i]) == idNavio*-1)
            break;
    }

    imprimeNavio(jogador.navios[i]);
}

void imprimeNaviosOrdemAlfabetica(tJogador jogador, char *arquivo)
{
    // imprime na ordem = Battleship, Carrier, Cruiser, Destroyer, Submarine
    imprimeNaviosEstatisticas(jogador, 4, arquivo);
    imprimeNaviosEstatisticas(jogador, 5, arquivo);
    imprimeNaviosEstatisticas(jogador, 3, arquivo);
    imprimeNaviosEstatisticas(jogador, 1, arquivo);
    imprimeNaviosEstatisticas(jogador, 2, arquivo);
}

void imprimeNaviosEstatisticas(tJogador jogador, int nome, char *arquivo)
{
    FILE * pEstatisticas;
    pEstatisticas = fopen(arquivo, "a");

    int i0, i, qtdNavios = 0;
    char nomeNavio[15];

    for(i = 1; i < obtemQtdJogadas(jogador.estatisticas); i++) // imprime jogadas em ordem crescente
    {
        for(i0 = 0; i0 < jogador.qtdNavios; i0++) // verifica todos os navios em busca da jogada
        {
            if(obtemJogadaFoiAtingido(jogador.navios[i0]) == i && obtemNomeNavio(jogador.navios[i0]) == nome)
            {
                preencheNomeNavio(nomeNavio, obtemNomeNavio(jogador.navios[i0]));

                fprintf(pEstatisticas, "%02d - %s - ID %02d\n", obtemJogadaFoiAtingido(jogador.navios[i0]), nomeNavio, obtemIdUnico(jogador.navios[i0]));
            }
        }
    }

    fclose(pEstatisticas);
}

void preencheNomeNavio(char *nomeNavio, int idNome)
{
    if(idNome == 5)
        strcpy(nomeNavio, "Carrier");
    if(idNome == 4)
        strcpy(nomeNavio, "Battleship");
    if(idNome == 3)
        strcpy(nomeNavio, "Cruiser");
    if(idNome == 2)
        strcpy(nomeNavio, "Submarine");
    if(idNome == 1)
        strcpy(nomeNavio, "Destroyer");
}

int preencheJogadasNaoDisponiveis(int *numerosSorteados, int posicoesDisponiveis, int numeroSorteado)
{
    int i;
    for(i = 0; i < posicoesDisponiveis; i++)
    {
        // remove o numero sorteado do vetor e coloca o numero da ultima posicao disponivel em seu lugar
        if(numerosSorteados[i] == numeroSorteado)
        {
            numerosSorteados[i] = numerosSorteados[posicoesDisponiveis-1];
            return posicoesDisponiveis - 1;
        }
    }

    return posicoesDisponiveis;
}