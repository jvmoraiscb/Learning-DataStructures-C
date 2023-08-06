/* 
 (BOCA:L4_2) Problema: Faça um programa para apresentar todas as datas
contidas em um intervalo formado por duas datas d1 e d2, em que o intervalo seja
fechado em d1 e aberto em d2 [d1, d2[. Para isso, implemente um tipo tData que
seja capaz de prover as funções necessárias para resolver o problema. Considere
que as datas desse tipo serão impressas com o formato “’dd/mm/aaaa’”, e que datas
fornecidas com valores inválidos devem ser corrigidas para datas válidas, ex. se o
mês fornecido for maior do que 12, a data criada deverá ser com mês 12. O mesmo
critério deverá ser usado para o dia considerando o mês em questão.
• Entrada: Sua entrada deverá conter os 3 valores (dia, mês e ano) da data inicial e 3 valores
(dia, mês e ano) da data final. Os valores das datas estarão separados por um espaço em
branco, e cada data estará em uma linha diferente.
• Saída: Sua saída deverá conter todas as datas contidas no intervalo (uma data por linha).
• Exemplo de Entrada:
30 12 2000
04 01 2001
• Exemplo de Saída:
'30/12/2000'
'31/12/2000'
'01/01/2001'
'02/01/2001'
'03/01/2001' 
*/

#include <stdio.h>

typedef struct 
{
    int dia;
    int mes;
    int ano;

} tData;

int quantosDias(int mes, int ano);
int ehBissexto(int ano);

void imprimeDatas(tData d1, tData d2);

void main()
{
    tData dataInicial, dataFinal;

    scanf("%d%*c%d%*c%d%*c", &dataInicial.dia, &dataInicial.mes, &dataInicial.ano);
    scanf("%d%*c%d%*c%d%*c", &dataFinal.dia, &dataFinal.mes, &dataFinal.ano);

    imprimeDatas(dataInicial, dataFinal);
}

void imprimeDatas(tData d1, tData d2)
{
    if (d1.mes > 12)
        d1.mes = 12;
    else if (d1.mes < 1)
        d1.mes = 1;
    if (d2.mes > 12)
        d2.mes = 12;
    else if (d2.mes < 1)
        d2.mes = 1;

    if (d1.dia > quantosDias(d1.mes, d1.ano))
        d1.dia = quantosDias(d1.mes, d1.ano);
    else if (d1.dia < 1)
        d1.dia = 1;
        
    if (d2.dia > quantosDias(d2.mes, d2.ano))
        d2.dia = quantosDias(d2.mes, d2.ano);
    else if (d2.dia < 1)
        d2.dia = 1;

    while (1)
    {
        if (d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano)
            break;
        printf("'%02d/%02d/%d'\n", d1.dia, d1.mes, d1.ano);
        
        d1.dia++;
        if (d1.dia > quantosDias(d1.mes, d1.ano))
        {
            d1.dia = 1;
            d1.mes++;
        }

        if (d1.mes > 12)
        {
            d1.mes = 1;
            d1.ano++;
        }
    }
}

int quantosDias(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        return 31;
    else if (mes == 2 && ehBissexto(ano) == 1)
        return 29;
    else if (mes == 2 && ehBissexto(ano) == 0)
        return 28;
    else
        return 30;
}

int ehBissexto(int ano)
{
    if (ano%100 == 0)
    {
        if (ano%400 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if (ano%4 == 0)
            return 1;
        else
            return 0;
    }
}
