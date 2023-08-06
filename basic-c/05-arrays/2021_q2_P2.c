/* 
Instruções gerais: A prova tem o objetivo de avaliar os conceitos ensinados e trabalhados
até o momento. Ela deve ser feita individualmente e sem ajuda de terceiros. Casos de cola,
terceirização, ajuda para fazer a avaliação ou qualquer outro que beneficie o aluno de forma
indevida serão tratados com a penalidade máxima disponível na instituição (i.e., atribuição da
nota zero e abertura de processo administrativo podendo levar a expulsão). A penalidade será
aplicada com igual teor a todos os envolvidos e sem distinção (inclusive a quem fornecer).
Siga as regras e faça sua própria prova usando os conceitos ensinados em sala. Boa prova!
Valor: 5 pontos
Correção: a questão está dividida em 5 partes de teste, A, B, C, D e E, sendo que a
complexidade dos casos aumenta com as letras. Os casos das letras posteriores contemplam
os casos das anteriores e mais alguns. Por exemplo, os casos de B contemplam os de A, os de
C contemplam os de A e B e, assim por diante. Portanto, se resolver a parte E, resolveu toda a
questão. Todas as partes possuem casos de teste ocultos não fornecidos com a questão. O
Anexo I descreve os tipos de casos com mais detalhes. O aluno ganha os pontos totais se
obtiver o balão na parte E (que inclui todos os casos) e ganha 20%, 40%, 60% e 80% se passar
somente até a parte A, B, C ou D, respectivamente. A questão a ser corrigida será a última
enviada, dando prioridade a que estiver correta. Portanto, sempre envie a sua solução para as
duas partes. Não implementar os tipos e funções (subprogramas) pedidos abaixo levará a
descontos de até 50% do valor da questão.
(BOCA: P2_2021_Q2) Você viajou no tempo por engano e acabou caindo em 2002.
Para sobreviver você terá que trabalhar como programador de uma videolocadora,
criando um sistema de locação de filmes na linguagem que o dono da loja exige, a
linguagem C. O objetivo é controlar as operações de cadastro de filmes, aluguel de fitas,
devolução de fitas e consulta ao estoque. A operação de cadastro irá cadastrar um novo
filme com suas fitas no estoque, a operação de aluguel irá retirar do estoque fitas de filmes
específicos, e a de devolução retornará fitas para o estoque. A consulta irá mostrar os
filmes disponíveis em estoque em ordem alfabética (filmes não alugados).
Atenção: Cada filme pode conter várias fitas. Ao alugar um filme não necessariamente irá
esgotar o estoque daquele filme. Não é possível fazer o cadastro de filmes que já tenham
o mesmo código no sistema, caso isso aconteça deverá reportar a mensagem “Filme ja
cadastrado no estoque”. Também não é possível alugar ou devolver um filme que não
esteja cadastrado, reportando a mensagem “Filme @ nao cadastrado” em que @
corresponde ao código do filme inválido. Demais erros podem incluir: alugar um filme que
não contenha fitas no estoque (“Filme ## - @@ nao disponivel no estoque. Volte mais
tarde.”), em que @@ corresponde ao nome do filme, e ## ao código do filme; ou, devolver
um filme que esteja com o estoque completo (“Nao e possivel devolver o filme ## - @@”),
em que @@ corresponde ao nome do filme, e ## ao código do filme.
Entrada: As operações serão dadas em blocos. Cada bloco de operação se iniciará com o
nome da operação em questão, e irá terminar com o caractere “#” que indica o fim da
operação. A operação de cadastro se iniciará com a string “Cadastrar” e seguirá com as
linhas correspondentes ao cadastro de um filme, sendo um filme por linha até o caractere
de saída do bloco da operação. A formatação das linhas de cadastro é ##,@@,$$$,%%, em
que ## é o código do filme (representado por um número inteiro), @@ é o nome do filme
(representado por no máximo 19 caracteres), $$$ é o valor do filme (representado por
um número inteiro), e %% a quantidade de fitas disponíveis para aquele filme
(representado por um número inteiro). Os blocos de aluguel e devolução iniciarão
respectivamente com as strings “Alugar” e “Devolver” e seguirão com as linhas de entrada.
Cada linha corresponderá ao código do filme em que a ação será executada. A operação
de consulta ao estoque se iniciará com a string “Estoque”, e não conterá linhas adicionais,
tendo o fim da operação logo após a abertura.
Saída: Cada bloco de operação contém saídas diferentes. Além dos erros explícitos
anteriormente, as saídas de sucesso incluem: ao cadastrar filmes, reportar para cada filme
cadastrado a mensagem “Filme cadastrado - ## - @@ ”, em que @@ corresponde ao nome
do filme, e ## ao código do filme. Na operação de aluguel, reportar a mensagem “Total de
filmes alugados ## com custo de R$%%”, em que ## é o número de filmes efetivamente
alugados (ou seja, que não apresentaram erro) e %% corresponde ao valor total do custo
dos filmes alugados naquela operação. Ao devolver uma fita o programa deverá reportar
a mensagem “Filme ## - @@ Devolvido!”, em que @@ corresponde ao nome do filme, e
## ao código do filme. Ao consultar o estoque, o programa deverá reportar o estoque
seguindo a formatação a seguir. Uma linha iniciando com “~ESTOQUE~” seguida de todos
os filmes do estoque, sendo um em cada linha. Os filmes deverão estar ordenados
alfabeticamente e cada um deles será reportado com o formato: “Filme: ## - @@ Fitas
em estoque: %%”, em que @@ corresponde ao nome do filme, e ## ao código do filme e,
%% ao número de fitas atual do filme. A saída de cada bloco de operação será separada
por uma linha em branco. Ao terminar todas as operações, o programa deverá exibir o
lucro total das operações da locadora. O lucro total corresponde à soma do valor de todas
as fitas que foram devolvidas com sucesso. O lucro total será exibido no formato: “Lucro
total R$%%”, em que %% corresponde ao valor do lucro total.
Seu código deve estar modularizado! Ele deve conter um tipo tLocadora e um tipo tFilme.
O tipo tLocadora será responsável por controlar o estoque da locadora, enquanto o tipo
tFilme será responsável por representar um filme.
O tipo tLocadora possuirá, pelo menos, as quatro funções a seguindo o cabeçalho seguir
(outras podem ser necessárias para evitar acessos indevidos a seus atributos).
● Função para cadastrar o filme: tLocadora CadastrarFilmeLocadora(tLocadora
locadora, char nome[], int codigo, int valor, int quantidade);
● Função para alugar o filme: tLocadora AlugarFilmesLocadora(tLocadora locadora,
int codigos[], int quantidadeCodigos);
● Função para devolver o filme: tLocadora DevolverFilmesLocadora(tLocadora
locadora, int codigos[], int quantidadeCodigos);
● Função para consultar o estoque: void ConsultarEstoqueLocadora(tLocadora
locadora);
O tipo tFilme também possuirá funções para sua manipulação. O aluno deve pensar nas
funções de forma a evitar acessos indevidos aos atributos do tipo (por exemplo,
CriarFilme, entre outras).
Veja exemplos de formatação das entradas e saídas a seguir.
Exemplo de Entrada:
Cadastrar
2,Shrek,4,1
3,A Mumia,4,3
1,Matrix,2,3
6,A Sociedade Do Anel,5,1
1,A Viagem,5,1
#
Devolver
1
#
Alugar
1
2
5
#
Alugar
2
#
Devolver
2
#
Estoque
#
Exemplo de Saída:
Filme cadastrado 2 - Shrek
Filme cadastrado 3 - A Mumia
Filme cadastrado 1 - Matrix
Filme cadastrado 6 - A Sociedade Do Anel
Filme ja cadastrado no estoque
Nao e possivel devolver o filme 1 - Matrix.
Filme 5 nao cadastrado.
Total de filmes alugados: 2 com custo de R$6
Filme 2 - Shrek nao disponivel no estoque. Volte mais tarde.
Filme 2 - Shrek Devolvido!
~ESTOQUE~
3 - A Mumia Fitas em estoque: 3
6 - A Sociedade Do Anel Fitas em estoque: 1
1 - Matrix Fitas em estoque: 2
2 - Shrek Fitas em estoque: 1
Lucro total R$4
ANEXO I
A correção da questão será feita de forma incremental, onde cada caso de teste
apresentado cobra certos conceitos além do caso anterior, permitindo que a nota também
seja incremental.
a) Caso de teste 1 - Apenas cadastro de filmes e consulta ao estoque.
Entrada:
Cadastrar
2,Shrek,4,1
#
Estoque
#
Saída esperada:
Filme cadastrado 2 - Shrek
~ESTOQUE~
2 - Shrek Fitas em estoque: 1
b) Caso de teste 2 Cadastro de filmes, Aluguel e Consulta ao Estoque
Entrada:
Cadastrar
1,A Sociedade Do Anel,5,1
#
Alugar
1
#
Estoque
#
Saída esperada:
Filme cadastrado 1 - A Sociedade Do Anel
Total de filmes alugados: 1 com custo de R$5
~ESTOQUE~
1 - A Sociedade Do Anel Fitas em estoque: 0
c) Caso de teste 3 Cadastro de filmes, Aluguel, Devolução e Consulta ao Estoque
Entrada:
Cadastrar
1,A Sociedade Do Anel,5,1
#
Alugar
1
#
Devolver
1
#
Estoque
#
Saída esperada:
Filme cadastrado 1 - A Sociedade Do Anel
Total de filmes alugados: 1 com custo de R$5
Filme 1 - A Sociedade Do Anel Devolvido!
~ESTOQUE~
1 - A Sociedade Do Anel Fitas em estoque: 1
Lucro total R$5
d) Caso de teste 4 - Cadastro de filmes, Aluguel, Erro no Aluguel, Devolução e Consulta
ao Estoque
Entrada:
Cadastrar
2,Shrek,4,1
3,A Mumia,4,3
#
Alugar
1
2
3
#
Devolver
2
#
Estoque
#
Saída esperada:
Filme cadastrado 2 - Shrek
Filme cadastrado 3 - A Mumia
Filme 1 nao cadastrado.
Total de filmes alugados: 2 com custo de R$8
Filme 2 - Shrek Devolvido!
~ESTOQUE~
3 - A Mumia Fitas em estoque: 2
2 - Shrek Fitas em estoque: 1
Lucro total R$4
 e) Caso de teste 4 - Cadastro de filmes, Erro no cadastro de filmes, Aluguel, Erro no
Aluguel, Devolução, Erro na Devolução e Consulta ao Estoque
Entrada:
Cadastrar
2,Shrek,4,1
3,A Mumia,4,3
1,Matrix,2,3
6,A Sociedade Do Anel,5,1
1,A Viagem,5,1
#
Devolver
1
#
Alugar
1
2
5
#
Alugar
2
#
Devolver
2
#
Estoque
#
Saída esperada:
Filme cadastrado 2 - Shrek
Filme cadastrado 3 - A Mumia
Filme cadastrado 1 - Matrix
Filme cadastrado 6 - A Sociedade Do Anel
Filme ja cadastrado no estoque
Nao e possivel devolver o filme 1 - Matrix.
Filme 5 nao cadastrado.
Total de filmes alugados: 2 com custo de R$6
Filme 2 - Shrek nao disponivel no estoque. Volte mais tarde.
Filme 2 - Shrek Devolvido!
~ESTOQUE~
3 - A Mumia Fitas em estoque: 3
6 - A Sociedade Do Anel Fitas em estoque: 1
1 - Matrix Fitas em estoque: 2
2 - Shrek Fitas em estoque: 1
Lucro total R$4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[20];
    int valor;
    int qtdFitasAtual;
    int qtdFitas;
    int qtdFitasDevolvidas;

}   tFilme;

typedef struct
{
    tFilme filmes[20];
    int qtdFilmes;

}   tLocadora;

void imprimeFilme(tFilme filme);
void ConsultarEstoqueLocadora(tLocadora locadora);
void ImprimeFilmesEmOrdemCrescente(tFilme *filmes, int qtdFilmes);
tFilme CriarFilme(char *informacoesFilme);
tFilme MontarFilme(char* nome, int codigo, int valor, int quantidade);
tFilme AlugaFilme(tFilme filme);
tFilme DevolveFilme(tFilme filme);
tLocadora CadastrarTodosFilmesLocadora(tLocadora locadora);
tLocadora CadastrarFilmeLocadora(tLocadora locadora, char* nome, int codigo, int valor, int quantidade);
tLocadora AlugarFilmesLocadora(tLocadora locadora, int *codigos, int qtdCodigos);
tLocadora DevolverFilmesLocadora(tLocadora locadora, int *codigos, int qtdCodigos);
int filmeAindaNaoCadastrado(tFilme filme, tLocadora locadora);
int obtemCodFilme(tFilme filme);
int obtemValorFilme(tFilme filme);
int filmePodeSerAlugado(tFilme filme);
int filmePodeSerDevolvido(tFilme filme);
int defineOperacao();
int encontraMenorValorNome(tFilme *filmes, int qtdFilmes, int i);
int adicionaValorAoLucroTotal(tLocadora locadora);

int main()
{
    int lucroTotal = 0;
    tLocadora locadora;
    locadora.qtdFilmes = 0;

    char operacao, hashtag[2] = "#";
    while(scanf("%c", &operacao) == 1)
    {
        //char cadastrar[10] = "Cadastrar", alugar[10] = "Alugar", devolver[10] = "Devolver", estoque[10] = "Estoque";
        scanf("%*[^\n]%*c");
        
        if(operacao == 'C')
        {
            locadora = CadastrarTodosFilmesLocadora(locadora);
            printf("\n");
        }

        else if(operacao == 'A')
        {
            int i = 0, codigos[20], qtdCodigos;
            while(1)
            {
                char cod[3];
                memset(cod, '\0', 3);
                scanf("%[^\n]%*c", cod);

                if(strcmp(cod, hashtag) == 0)
                    break;
                else
                {
                    codigos[i] = atoi(cod);
                    i++;
                }
            }
            qtdCodigos = i;
            locadora = AlugarFilmesLocadora(locadora, codigos, qtdCodigos);
            printf("\n");
        }

        else if(operacao == 'D')
        {
            int i = 0, codigos[20], qtdCodigos;
            while(1)
            {
                char cod[3];
                memset(cod, '\0', 3);
                scanf("%[^\n]%*c", cod);

                if(strcmp(cod, hashtag) == 0)
                    break;
                else
                {
                    codigos[i] = atoi(cod);
                    i++;
                }
            }
            qtdCodigos = i;
            locadora = DevolverFilmesLocadora(locadora, codigos, qtdCodigos);
            printf("\n");
        }

        else if(operacao == 'E')
        {
            scanf("#%*c");
            imprimeEstoque(locadora);
            printf("\n");
        }

        scanf("%*[^A-E]");
    }

    lucroTotal = adicionaValorAoLucroTotal(locadora);
    if(lucroTotal > 0)
        printf("Lucro total R$%d", lucroTotal);

    return 0;
}

tLocadora CadastrarTodosFilmesLocadora(tLocadora locadora)
{
    char hashtag[2] = "#";
    tFilme filme;

    int i = locadora.qtdFilmes;
    while(1)
    {
        char informacoesFilme[50];
        memset(informacoesFilme, '\0', 50);
        scanf("%[^\n]%*c", informacoesFilme);
        if(strcmp(informacoesFilme, hashtag) == 0)
            break;
        else   
        {
            filme = CriarFilme(informacoesFilme);
            if(filmeAindaNaoCadastrado(filme, locadora) == 1)
            {
                locadora.qtdFilmes = i+1;
                locadora = CadastrarFilmeLocadora(locadora, filme.nome, filme.codigo, filme.valor, filme.qtdFitas);
                i++;

                printf("Filme cadastrado ");
                imprimeFilme(filme);
                printf("\n");
            }
            else
                printf("Filme ja cadastrado no estoque\n");
        }
    }

    return locadora;
}

tLocadora CadastrarFilmeLocadora(tLocadora locadora, char* nome, int codigo, int valor, int quantidade)
{
    int filmeAtual = locadora.qtdFilmes-1;

    locadora.filmes[filmeAtual] = MontarFilme(nome, codigo, valor, quantidade);

    return locadora;
}

tLocadora AlugarFilmesLocadora(tLocadora locadora, int *codigos, int qtdCodigos)
{
    int i, iCodigo, codFilme, qtdFilmesAlugados = 0, custoFilmesAlugados = 0;

    for(iCodigo = 0; iCodigo < qtdCodigos; iCodigo++)
    {
        codFilme = codigos[iCodigo];
        int filmeExiste = 0;
            for(i = 0; i < locadora.qtdFilmes; i++)
            {
                if (obtemCodFilme(locadora.filmes[i]) == codFilme)
                {
                    filmeExiste = 1;
                    break;
                }
            }
            if(filmeExiste == 1 && filmePodeSerAlugado(locadora.filmes[i]) == 1)
            {
                locadora.filmes[i] = AlugaFilme(locadora.filmes[i]);
                qtdFilmesAlugados++;
                custoFilmesAlugados += obtemValorFilme(locadora.filmes[i]);
            }
            else if (filmeExiste == 1 && filmePodeSerAlugado(locadora.filmes[i]) == 0)
            {
                printf("Filme ");
                imprimeFilme(locadora.filmes[i]);
                printf(" nao disponivel no estoque. Volte mais tarde.\n");
            }
            else
                printf("Filme %d nao cadastrado.\n", codFilme);
    }
    if(qtdFilmesAlugados > 0)
    printf("Total de filmes alugados: %d com custo de R$%d\n", qtdFilmesAlugados, custoFilmesAlugados);

    return locadora;
}

tLocadora DevolverFilmesLocadora(tLocadora locadora, int *codigos, int qtdCodigos)
{
    int i, iCodigo, codFilme;

    for(iCodigo = 0; iCodigo < qtdCodigos; iCodigo++)
    {
            codFilme = codigos[iCodigo];
            int filmeExiste = 0;
            for(i = 0; i < locadora.qtdFilmes; i++)
            {
                if (obtemCodFilme(locadora.filmes[i]) == codFilme)
                {
                    filmeExiste = 1;
                    break;
                }
            }
            if(filmeExiste == 1 && filmePodeSerDevolvido(locadora.filmes[i]) == 1)
            {
                printf("Filme ");
                imprimeFilme(locadora.filmes[i]);
                printf(" Devolvido!\n");
                locadora.filmes[i] = DevolveFilme(locadora.filmes[i]);
            }
            else if (filmeExiste == 1 && filmePodeSerDevolvido(locadora.filmes[i]) == 0)
            {
                printf("Nao e possivel devolver o filme ");
                imprimeFilme(locadora.filmes[i]);
                printf(".\n");
            }
            else
                printf("Filme %d nao cadastrado.\n", codFilme);
    }

    return locadora;
}

tFilme MontarFilme(char* nome, int codigo, int valor, int quantidade)
{
    tFilme filme;

    memset(filme.nome, '\0', 20);

    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdFitas = quantidade;
    filme.qtdFitasAtual = quantidade;
    filme.qtdFitasDevolvidas = 0;

    memcpy(filme.nome, nome, strlen(nome));

    return filme;
}

tFilme CriarFilme(char *informacoesFilme)
{
    tFilme filme;

    int pVirgulas[3], iVirgula = 0, i, i0;
    char codigo[5], nome[20], valor[5], qtd[5];
    memset(nome, '\0', 20);
    memset(filme.nome, '\0', 20);

    for(i = 0; i < strlen(informacoesFilme); i++)
    {
        if(informacoesFilme[i] == ',')
        {
            pVirgulas[iVirgula] = i;
            iVirgula++;
        }
    }
    i0 = 0;
    for(i = 0; i < pVirgulas[0]; i++)
    {
        codigo[i0] = informacoesFilme[i];
        i0++;
    }
    i0 = 0;
    for(i = pVirgulas[0]+1; i < pVirgulas[1]; i++)
    {
        nome[i0] = informacoesFilme[i];
        i0++;
    }
    i0 = 0;
    for(i = pVirgulas[1]+1; i < pVirgulas[2]; i++)
    {
        valor[i0] = informacoesFilme[i];
        i0++;
    }
    i0 = 0;
    for(i = pVirgulas[2]+1; i < strlen(informacoesFilme); i++)
    {
        qtd[i0] = informacoesFilme[i];
        i0++;
    }

    filme.codigo = atoi(codigo);
    filme.valor = atoi(valor);
    filme.qtdFitas = atoi(qtd);
    filme.qtdFitasAtual = filme.qtdFitas;
    memcpy(filme.nome, nome, strlen(nome));
    
    return filme;
}

tFilme AlugaFilme(tFilme filme)
{
    filme.qtdFitasAtual--;

    return filme;
}

tFilme DevolveFilme(tFilme filme)
{
    filme.qtdFitasAtual++;
    filme.qtdFitasDevolvidas++;

    return filme;
}

void imprimeFilme(tFilme filme)
{
    printf("%d - %s", filme.codigo, filme.nome);
}

void imprimeEstoque(tLocadora locadora)
{
    printf("~ESTOQUE~\n");
    ImprimeFilmesEmOrdemCrescente(locadora.filmes, locadora.qtdFilmes);
}

void ImprimeFilmesEmOrdemCrescente(tFilme *filmes, int qtdFilmes)
{
    int i, iMenorValorNome;
    tFilme filmeFlutuante;

    for (i = 0; i < qtdFilmes-1; i++)
    {
        iMenorValorNome = encontraMenorValorNome(filmes, qtdFilmes, i);
        filmeFlutuante = filmes[i];
        filmes[i] = filmes[iMenorValorNome];
        filmes[iMenorValorNome] = filmeFlutuante;
    }

    for(i = 0; i < qtdFilmes; i++)
    {
        printf("%d - %s Fitas em estoque: %d\n", filmes[i].codigo, filmes[i].nome, filmes[i].qtdFitasAtual);
    }
}

int filmeAindaNaoCadastrado(tFilme filme, tLocadora locadora)
{
    int i, filmeCadastrado = 0;
    
    for (i = 0; i < locadora.qtdFilmes; i++)
    {
        if(filme.codigo == obtemCodFilme(locadora.filmes[i]))
            filmeCadastrado = 1;
    }

    if(filmeCadastrado == 1)
        return 0;
    else
        return 1;
}

int obtemCodFilme(tFilme filme)
{
    return filme.codigo;
}

int obtemValorFilme(tFilme filme)
{
    return filme.valor;
}

int filmePodeSerAlugado(tFilme filme)
{
    if (filme.qtdFitasAtual > 0)
        return 1;
    else
        return 0;
}

int filmePodeSerDevolvido(tFilme filme)
{
    if (filme.qtdFitasAtual+1 <= filme.qtdFitas)
        return 1;
    else
        return 0;
}

int encontraMenorValorNome(tFilme *filmes, int qtdFilmes, int i)
{
    int iNomeMenorValor = i, i2;

    for (i2 = i+1; i2 < qtdFilmes; i2++)
    {
        int letraAtual;

        for(letraAtual = 1; letraAtual < 42; letraAtual++)
        {
            if (strncmp(filmes[iNomeMenorValor].nome, filmes[i2].nome, letraAtual) > 0 )
            {
                iNomeMenorValor = i2;
                break;
            }
        }
    }

    return iNomeMenorValor;
}

int adicionaValorAoLucroTotal(tLocadora locadora)
{
    int i, lucro = 0;

    for(i = 0; i < locadora.qtdFilmes; i++)
    {
        if(obtemQtdFilmesDevolvidos(locadora.filmes[i]) > 0)
        {
            lucro += obtemQtdFilmesDevolvidos(locadora.filmes[i]) * obtemValorFilme(locadora.filmes[i]);
        }
    }

    return lucro;
}

int obtemQtdFilmesDevolvidos(tFilme filme)
{
    return filme.qtdFitasDevolvidas;
}