/* 
Problema: (BOCA: P2_2017_Q3) Faça um programa para exibir a placa com maior
débito (considerando valores não prescritos) das multas referentes a placas de
algumas cidades e por fim apresentar a soma dos maiores débitos das cidades
consideradas.
• Entrada: um número inteiro n representando a quantidade de cidades a serem tratadas
seguido (na linha seguinte) das informações sobre as cidades. Cada cidade será
representada por um número inteiro p representando o número de anos para prescrever
uma multa seguido (na linha seguinte) das placas da cidade (uma por linha). As informações
de cada placa serão dadas em uma linha contendo a placa (representada por 3 caracteres)
e as informações dos débitos referentes a aquela placa. Os débitos de cada placa serão
dados por vários elementos no formato “(#1:#2)”, em que #1 é um inteiro representando o
valor do débito e #2 é um valor inteiro representando há quantos anos o débito ocorreu. O
termino da sequência de placas de uma cidade será definido pelos caracteres “FIM”.
• Saída: para cada cidade, o programa deverá imprimir a placa com o maior débito
acumulado (i.e. soma de todos os débitos daquela placa) no formato
"PLACA:#3 DEBITO:#4", em que #3 são os 3 caracteres representando a placa e #4 é um
inteiro representando o debito acumulado daquela placa. Débitos com quantidade de anos
superior a quantidade de prescrição p não deverão ser contabilizados. Se a cidade não
possuir débitos não prescritos, então o programa deverá imprimir “SEM DEBITO!”. Ao final
o programa deverá imprimir a soma de todos os maiores débitos de cada cidade no
formato "SOMA:#5", em que #5 representa a soma de todos os maiores débitos das
cidades. Ver formato da saída nos exemplos abaixo.
O programa deve estar modularizado, para isso crie:
a) Uma função que receba um número representando a quantidade máxima de anos
para prescrever um débito, leia as informações da lista de débitos de uma placa e
retorne o débito acumulado dos valores não prescritos desse placa. Assuma que a
função será chamada no início da leitura da lista de débitos (ou seja, logo após a
leitura dos caracteres da placa) e deve retornar após consumir o caractere de
quebra de linha. Cabeçalho: int QtdDebitoPlaca(int presc);
b) Uma função que leia as informações de uma cidade e retorne o maior débito dela.
Assuma que a função será chamada no início da leitura das informações da cidade,
ou seja, antes do valor p representando a quantidade de anos para prescrever uma
multa. A função retornará após ler a placa com os caracteres terminadores “FIM”.
Adicionalmente, essa função deverá imprimir a placa com o maior debito e o
respectivo valor do débito no formato especificado acima, ou seja,
"PLACA:#3 DEBITO:#4", em que #3 são os 3 caracteres representando a placa e #4 é
um inteiro representando o debito acumulado daquela placa. Se a cidade não
possuir débitos não prescritos, então ela deverá retornar 0 e imprimir “SEM
DEBITO!”. Cabeçalho: int MaiorDebitoCidade();
• Exemplos de Entradas:
4
5
ABC(15:2)(30:6)(10:1)(15:5)
BCA(30:7)
CBA
DBC(19:3)
FIM
3
FGH(20:2)(30:6)(10:1)(15:5)
HGF(30:1)
FIM
10
DNM(2:3)(20:5)(30:4)(20:6)(19:3)(19:3)
FIM
10
TUV(2:3)(20:5)(30:4)(20:6)
FIM
1
3
FGH(20:4)(30:6)(15:5)
HGF(30:5)(10:6)
ABC
BCA(30:7)
CBA(30:6)(15:5)
DBC(19:4)
FIM
• Exemplos de Saídas:
PLACA:ABC DEBITO:40
PLACA:FGH DEBITO:30
PLACA:DNM DEBITO:110
PLACA:TUV DEBITO:72
SOMA:252
SEM DEBITO!
SOMA:0
*/

#include <stdio.h>

int QtdDebitoPlaca(int pAnos);
int MaiorDebitoCidade();

void main ()
{
    int nCidades, debitoCidade, somaDebitos = 0, i;

    scanf("%d\n", &nCidades);

    for (i = 1; i <= nCidades; i++)
    {
        debitoCidade = MaiorDebitoCidade();
        somaDebitos += debitoCidade;
    }
    printf("SOMA:%d\n", somaDebitos);
}

int QtdDebitoPlaca(int pAnos)
{
    int valorDebito, anos, soma = 0; char letraInicial;

    while (1)
    {
        scanf("%c", &letraInicial);
        if (letraInicial == '\n')
            break;
        scanf("%d:%d)", &valorDebito, &anos);
        if (anos <= pAnos)
            soma += valorDebito;
    }

    return soma;
}

int MaiorDebitoCidade()
{
    int anos, debitoPlaca, maiorDebito = 0; char l1, l2, l3, maiorDebl1, maiorDebl2, maiorDebl3;

    scanf("%d\n", &anos);
    while (1)
    {
        scanf("%c%c%c", &l1, &l2, &l3);
        if (l1 == 'F' && l2 == 'I' && l3 == 'M'){
            break;
        }
        else{
            debitoPlaca = QtdDebitoPlaca(anos);
            if (debitoPlaca > maiorDebito)
            {
                maiorDebito = debitoPlaca;
                maiorDebl1 = l1; maiorDebl2 = l2; maiorDebl3 = l3;
            }
        }
    }
    if (maiorDebito == 0){
        printf("SEM DEBITO!\n");
        return 0;
    }
    else{
        printf("PLACA:%c%c%c DEBITO:%d\n", maiorDebl1, maiorDebl2, maiorDebl3, maiorDebito);
        return maiorDebito;
    }
}