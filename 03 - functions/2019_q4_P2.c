/* 
(BOCA: P2_2019_Q4_a) Problema: Faça um programa para analisar as senhas de grupos
de usuários e ao final apresentar o grupo com maior quantidades de senhas fortes, o
com maior de senhas fracas e o com maior de senhas inválidas. Uma senha é dita forte
quando ela é válida e contém pelo menos uma letra maiúscula, uma letra minúscula,
um número e um caractere não alfanumérico. Uma senha é dita fraca quando ela é
válida, mas não é forte. Uma senha é inválida quando ele possui menos de 6 caracteres.
O programa deve ser entregue modularizado, para isso crie:
a) Uma função que recebe um caractere e retorna verdadeiro se ele for uma letra
maiúscula e falso caso contrário. Cabeçalho: int EhLetraMaiuscula(char c);
b) Uma função que recebe um caractere e retorna verdadeiro se ele for uma letra
minúscula e falso caso contrário. Cabeçalho: int EhLetraMinuscula(char c);
c) Uma função que recebe um caractere e retorna verdadeiro se ele for um número e
falso caso contrário. Cabeçalho: int EhNumero(char c);
d) Uma função responsável por analisar a senha de um usuário e retornar 0 se ela for
inválida, 1 se for fraca e 2 se for forte. A função deverá ler a senha da entrada padrão
para fazer a análise. Assumir que a senha será dada no formato “(SENHA)”, ou seja,
entre parênteses. Cabeçalho: int AnalisaSenha();
• Entrada: Um número n indicando a quantidade de grupos seguido dos grupos em si. Cada
grupo é composto por uma lista de usuários. Um usuário é dado por um código e uma senha
fornecida entre parênteses. A lista de usuários de um grupo termina quando o código de um
usuário é -1. Cada usuário é dado em uma linha. Os grupos vão de 1 a n e podem ser vazios (ou
seja, sem usuários). Veja o formato de entrada nos exemplos abaixo.
• Saída: A saída deverá imprimir o tipo das senhas por usuário (fraca, forte ou inválida) e por fim
os grupos com maior quantidade de cada uma delas. Para cada um dos grupos, a formatação
seguirá com: uma linha contendo o índice do grupo com a mensagem “GRUPO:” seguida do
índice; posteriormente, uma linha para cada usuário do grupo informando “FRACA”, “FORTE”
ou “INVALIDA” dependendo do tipo da senha de cada usuário. Por fim, o programa deverá
apresentar 3 mensagens sendo uma em cada linha: “FORTES: GRUPO(#1) QTD(#2)”, “FRACAS:
GRUPO(#1) QTD(#2)” e “INVALIDAS: GRUPO(#1) QTD(#2)”, em que #1 e #2 representam
respectivamente o índice e a quantidade do grupo com a maior quantidade de senhas do tipo
daquela mensagem (fortes, fracas e inválidas respectivamente). Veja o formato da saída nos
exemplos abaixo.
• Exemplo de Entrada:
4
100(abcdefg)
101(abc)
102(Ab2&r)
103(Ab2&ifdz)
104(AB2$ifdz)
-1
-1
100(AAAAAAA)
1002(AAA)
2(123)
103(ABCD)
-1
10(Ab2sger)
20(Ab&sger)
30(jb&s1er)
40(jb&sger)
50()
60(123456)
-1
6
100(¨&&7868sd)
101(3453)
102(Ab2&r)
103(Ab2&ifdz)
104(AB2$ifdz)
-1
100(UJGw98c)
1002(hyas)
2(7890)
103(Z)
-1
-1
10(Ab2sger)
20(Ab&sger)
30(jb&s1er)
40(jb&sger)
50()
60(123456)
-1
10(!@#$%¨&*)
20(A!@#$%¨&*123c)
30(ABCDZa*)
40(1234AA5912)
50()
60(123456)
-1
1001(*&¨%$%IHUTug3423)
1002(*&¨%$%IHUTug3425)
1003(2345)
1004($eA1Z)
-1
• Exemplo de Saída:
GRUPO 1
FRACA
INVALIDA
INVALIDA
FORTE
FORTE
GRUPO 2
GRUPO 3
FRACA
INVALIDA
INVALIDA
INVALIDA
GRUPO 4
FRACA
FRACA
FRACA
FRACA
INVALIDA
FRACA
FORTES: GRUPO(1) QTD(2)
FRACAS: GRUPO(4) QTD(5)
INVALIDAS: GRUPO(3) QTD(3)
GRUPO 1
FRACA
INVALIDA
INVALIDA
FORTE
FORTE
GRUPO 2
FRACA
INVALIDA
INVALIDA
INVALIDA
GRUPO 3
GRUPO 4
FRACA
FRACA
FRACA
FRACA
INVALIDA
FRACA
GRUPO 5
FRACA
FORTE
FRACA
FRACA
INVALIDA
FRACA
GRUPO 6
FORTE
FORTE
INVALIDA
INVALIDA
FORTES: GRUPO(1) QTD(2)
FRACAS: GRUPO(4) QTD(5)
INVALIDAS: GRUPO(2) QTD(3)
*/

#define INVALIDA 0
#define FRACA 1
#define FORTE 2
#include <stdio.h>

int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
int EhNumero(char c);
int AnalisaSenha();

void main ()
{
    int grupo, nGrupos, grupoMaisFortes, grupoMaisFracas, grupoMaisInvalidas;
    int maiorNumSenhasFortes = 0, maiorNumSenhasFracas = 0, maiorNumSenhasInvalidas = 0;

    scanf("%d%*c", &nGrupos);
    for (grupo = 1; grupo <= nGrupos; grupo++)
    {
        int senha, senhasFortes = 0, senhasFracas = 0, senhasInvalidas = 0;

        printf("GRUPO %d\n", grupo);

        while (1)
        {
            char c;

            scanf("%c", &c);
            if (c == '-')
            {
                scanf("1%*c");
                break;
            }
            if (c == '(')
            {
                senha = AnalisaSenha();
                if (senha == INVALIDA)
                    senhasInvalidas++;
                if (senha == FRACA)
                    senhasFracas++;
                if (senha == FORTE)
                    senhasFortes++;
                
            }
        }
        if (senhasInvalidas > maiorNumSenhasInvalidas)
        {
                maiorNumSenhasInvalidas = senhasInvalidas;
                grupoMaisInvalidas = grupo;
        }
        if (senhasFracas > maiorNumSenhasFracas)
        {
            maiorNumSenhasFracas = senhasFracas;
            grupoMaisFracas = grupo;
        }
        if (senhasFortes > maiorNumSenhasFortes)
        {
            maiorNumSenhasFortes = senhasFortes;
            grupoMaisFortes = grupo;
        }
        printf("\n");
    }
    printf("FORTES: GRUPO(%d) QTD(%d)\n", grupoMaisFortes, maiorNumSenhasFortes);
    printf("FRACAS: GRUPO(%d) QTD(%d)\n", grupoMaisFracas, maiorNumSenhasFracas);
    printf("INVALIDAS: GRUPO(%d) QTD(%d)\n", grupoMaisInvalidas, maiorNumSenhasInvalidas);
}

int AnalisaSenha()
{
    int vNumCaracteres = 0, vLetraMaiuscula = 0, vLetraMinuscula = 0, vNumero = 0, vNaoAlfanumerico = 0;

    while (1)
    {
        char c;

        scanf("%c", &c);
        if (c == ')'){
            scanf("%*c");
            break;
        }
        else if (EhLetraMaiuscula(c))
            vLetraMaiuscula = 1;
        else if (EhLetraMinuscula(c))
            vLetraMinuscula = 1;
        else if (EhNumero(c))
            vNumero = 1;
        else
            vNaoAlfanumerico = 1;
        
        vNumCaracteres += 1;
    }

    if (vNumCaracteres < 6)
    {
        printf("INVALIDA\n");
        return INVALIDA;
    }
    else if (vLetraMaiuscula == 1 && vLetraMinuscula == 1 && vNumero == 1 && vNaoAlfanumerico == 1)
    {
        printf("FORTE\n");
        return FORTE;
    }
    else
    {
        printf("FRACA\n");
        return FRACA;
    }
}

int EhLetraMaiuscula(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int EhLetraMinuscula(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;
}

int EhNumero(char c)
{
    if (c >= '1' && c <= '9')
        return 1;
    else
        return 0;
}