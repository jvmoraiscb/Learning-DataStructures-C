/* 
 (BOCA:L4_3) Problema: Usando o tipo tData implementado acima, faça um
programa que leia n datas e informe se a data é de ano bissexto.
• Entrada: Sua entrada deverá conter a quantidade de datas a serem lidas, e as datas em
questão. Cada data será dada em uma linha e por 3 valores (dia, mês e ano) separados por
espaço.
• Saída: Sua saída deverá apresentar a data seguida da mensagem “:Bisexto” se o ano for
bisexto, ou “:Normal” caso contrário.
• Exemplo de Entrada:
7
04 12 2000
04 01 2001
04 01 2003
04 01 2004
04 00 2005
04 13 2006
04 01 2007
• Exemplo de Saída:
'04/12/2000':Bisexto
'04/01/2001':Normal
'04/01/2003':Normal
'04/01/2004':Bisexto
'04/01/2005':Normal
'04/12/2006':Normal
'04/01/2007':Normal 
*/

#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

} tData;

int ehBissexto(tData d);
tData corrigeData(tData data);
int quantosDias(tData data);

void main ()
{
    int data, nDatas;

    scanf("%d", &nDatas);
    for (data = 1; data <= nDatas; data++)
    {
        tData dataAtual;

        scanf("%d%*c%d%*c%d%*c", &dataAtual.dia, &dataAtual.mes, &dataAtual.ano);
        dataAtual = corrigeData(dataAtual);

        printf("'%02d/%02d/%d':", dataAtual.dia, dataAtual.mes, dataAtual.ano);
        if (ehBissexto(dataAtual) == 1)
            printf("Bisexto\n");
        else
            printf("Normal\n");
    }
}

int ehBissexto(tData d)
{
    int ano = d.ano;

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

tData corrigeData(tData data)
{   
    tData d = data;

    if (d.mes > 12)
        d.mes = 12;
    else if (d.mes < 1)
        d.mes = 1;

    if (d.dia > quantosDias(data))
        d.dia = quantosDias(data);
    else if (d.dia < 1)
        d.dia = 1;

    return d;
}

int quantosDias(tData data)
{
    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
        return 31;
    else if (data.mes == 2 && ehBissexto(data) == 1)
        return 29;
    else if (data.mes == 2 && ehBissexto(data) == 0)
        return 28;
    else
        return 30;
}
