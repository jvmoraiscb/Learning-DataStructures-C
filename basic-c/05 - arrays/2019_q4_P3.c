/* 
(BOCA: P3_2019_Q4_a) Problema: Considere o mesmo cenário da concessionária da
questão anterior, porém, agora, você já tem as funções para ler os carros. Sua
segunda tarefa será ler eventos de aluguel e devoluções de carro e processá-los de
acordo com a disponibilidade dos carros. Processar um evento inclui alterar o
estado da concessionaria para representar o estado corrente de sua frota de
veículos alugados e devolvidos e, imprimir o resultado de cada evento processado
mostrando o veículo alugado ou devolvido. Os eventos estarão associados a um
cliente e quando forem de aluguel, virão também com critérios restringindo o carro
a ser alugado (os critérios mesmos da questão anterior). Quando um cliente
demandar um carro para aluguel, o carro deverá atender aos critérios exigidos pelo
cliente (i.e., capacidade de passageiros e quilometragem máxima, como na questão
anterior) e estar disponível (não ter sido alugado por alguém antes ou já ter sido
devolvido). O primeiro carro da lista que atenda os critérios e esteja disponível será
alugado. Novamente, os critérios podem ser ignorados, caso o cliente informe -1.
• Entrada: assim como na questão anterior, a primeira linha terá um inteiro n representando
o número de carros da concessionária; na linhas seguintes, serão dados os n carros, sendo
cada um deles em uma linha e contendo as seguintes informações separadas por espaço:
identificador único do carro (inteiro), quantidade de passageiros que o carro suporta
(inteiro), tipo do carro (string com no máximo 100 caracteres) e uma quilometragem
(inteiro). Após os carros, serão dados os eventos. Um evento de aluguel será composto por
dois elementos principais (dados em uma linha) separados por uma vírgula: um
identificador do cliente (inteiro) e um caractere ‘A’ indicando um aluguel. Ele será seguido
(na outra linha) por dois elementos separados por uma vírgula, indicando os critérios do
aluguel: quantidade de passageiros (inteiro) e uma quilometragem máxima (inteiro). Um
evento de devolução será composto por dois únicos elementos separados por uma vírgula:
um identificador do cliente (inteiro) e um caractere ‘D’ indicando uma devolução. O
identificador do cliente será um número de um cliente que esteja com o carro alugado no
momento. Veja exemplos abaixo.
• Saída: A saída será uma descrição de cada evento, sendo uma mensagem de evento por
linha. Um evento de aluguel bem-sucedido, ou seja, em que o carro com os critérios
demandado estava disponível, será representado pela mensagem: ”Alugado (cliente #1) ->
” seguida da impressão da informação do carro alugado (já implementada na questão
anterior), em que #1 é o identificador do cliente que alugou. Um evento de aluguel não
concretizado, ou seja, em que não tinha carro disponível atendendo os critérios exigidos,
será representado pela mensagem: ”Carro Indisponivel”. Um evento de devolução será
representado pela mensagem: ”Devolvido (cliente #1) -> ” seguida da impressão da
informação do carro devolvido (já implementada na questão anterior), em que #1 é o
identificador do cliente que devolveu. Ver exemplos abaixo!
O aluno deverá incrementar o tipo tCarro e suas funções para tratar a demanda
acima (0.2 pto). Sugere-se a implementação das seguintes funções adicionais:
• int ObtemClienteAlugouCarro(tCarro carro); (0.1 pto)
• int EstaDisponivelCarro(tCarro carro); (0.1 pto)
• tCarro AlugaCarro(tCarro carro, int cliente); (0.1 pto)
• tCarro DevolveCarro(tCarro carro); (0.1 pto)
O aluno deverá incrementar o tipo tConcessionaria e suas funções para tratar a
demanda acima. Sugere-se a implementação das seguintes funções adicionais para
processar os eventos na concessionária:
• tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int
cliente, int pass, int km); (0.7 pto)
• tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int
cliente); (0.7 pto)
Sugere-se fazer a leitura dos eventos na função main (0.5 pto).
• Exemplos de Entradas:
9
10 5 Gol 15000
11 5 Gol 12000
14 5 Gol 65000
44 7 Spin 15000
20 5 Corola 11000
21 5 Corola 35000
31 2 Saveiro 45000
33 2 Saveiro 55000
43 7 Doblo 35000
10,A
5,15000
20,A
5,30000
30,A
-1,30000
10,D
40,A
2,-1
50,A
2,50000
40,D
55,A
2,50000
60,A
7,30000
30,D
70,A
7,30000
75,A
7,30000
70,D
80,A
2,15000
85,A
7,30000
90,A
-1,-1
60,D
100,A
7,50000
• Exemplos de Saídas:
Alugado (cliente 10) -> CARRO (10): Gol de 5 passageiros e com 15000 km
Alugado (cliente 20) -> CARRO (11): Gol de 5 passageiros e com 12000 km
Alugado (cliente 30) -> CARRO (44): Spin de 7 passageiros e com 15000 km
Devolvido (cliente 10) -> CARRO (10): Gol de 5 passageiros e com 15000 km
Alugado (cliente 40) -> CARRO (31): Saveiro de 2 passageiros e com 45000 km
Carro Indisponivel
Devolvido (cliente 40) -> CARRO (31): Saveiro de 2 passageiros e com 45000 km
Alugado (cliente 55) -> CARRO (31): Saveiro de 2 passageiros e com 45000 km
Carro Indisponivel
Devolvido (cliente 30) -> CARRO (44): Spin de 7 passageiros e com 15000 km
Alugado (cliente 70) -> CARRO (44): Spin de 7 passageiros e com 15000 km
Carro Indisponivel
Devolvido (cliente 70) -> CARRO (44): Spin de 7 passageiros e com 15000 km
Carro Indisponivel
Alugado (cliente 85) -> CARRO (44): Spin de 7 passageiros e com 15000 km
Alugado (cliente 90) -> CARRO (10): Gol de 5 passageiros e com 15000 km
Alugado (cliente 100) -> CARRO (43): Doblo de 7 passageiros e com 35000 km
*/

#include <stdio.h>

typedef struct
{
    int id;
    int qtdPassageiros;
    char modelo[100];
    int km;

    int estaDisponivel;
    int idCliente;

}   tCarro;

typedef struct
{
    tCarro carros[100];
    int qtdCarros;

}   tConcessionaria;

tCarro LeCarro();
tCarro AlugaCarro(tCarro carro, int idCliente);
tCarro DevolveCarro(tCarro carro, int idCliente);
tConcessionaria LeCarrosConcessionaria();
tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int qtdPassageiros, int km, int idCliente);
tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int idCliente);
int ObtemNumPassageirosCarro(tCarro carro);
int ObtemClienteAlugouCarro(tCarro carro);
int ObtemKmCarro(tCarro carro);
int EstaDisponivelCarro(tCarro carro);
void ImprimeCarro(tCarro carro);
void ImprimeCliente(int idCliente, int tipo);

int main(){
    tConcessionaria concessionaria;
    concessionaria = LeCarrosConcessionaria();

    int idCliente ,qtdPassageiros, km, i = 0; char servico;
    while(scanf("%d,%c%*c", &idCliente, &servico) == 2)
    {
        if(servico == 'A')
        {
            scanf("%d,%d%*c", &qtdPassageiros, &km);
            concessionaria = AlugaCarroConcessionaria(concessionaria, qtdPassageiros, km, idCliente);
        }
        else if (servico == 'D')
        {
            concessionaria = DevolveCarroConcessionaria(concessionaria, idCliente);
        }
    }

    return 0;
}

tConcessionaria LeCarrosConcessionaria()
{
    tConcessionaria concessionaria;

    scanf("%d%*c", &concessionaria.qtdCarros);

    int i;
    for(i = 0; i < concessionaria.qtdCarros; i++)
        concessionaria.carros[i] = LeCarro();

    return concessionaria;
}

tCarro LeCarro()
{
    tCarro carro;

    scanf("%d %d %s %d%*c", &carro.id, &carro.qtdPassageiros, carro.modelo, &carro.km);
    carro.estaDisponivel = 1;

    return carro;
}

void ImprimeCarro(tCarro carro)
{
    printf("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.modelo, carro.qtdPassageiros, carro.km );
}

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int qtdPassageiros, int km, int idCliente)
{
    int i;

    if(qtdPassageiros != -1 && km != -1)
    {
        for(i = 0; i < concessionaria.qtdCarros; i++)
        {
            if(ObtemNumPassageirosCarro(concessionaria.carros[i]) == qtdPassageiros && ObtemKmCarro(concessionaria.carros[i]) <= km && EstaDisponivelCarro(concessionaria.carros[i]))
            {
                concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], idCliente);
                ImprimeCliente(idCliente, 1);
                ImprimeCarro(concessionaria.carros[i]);
                break;
            }
        }
    }
    else if(qtdPassageiros != -1 && km == -1)
    {
        for(i = 0; i < concessionaria.qtdCarros; i++)
        {
            if(ObtemNumPassageirosCarro(concessionaria.carros[i]) == qtdPassageiros && EstaDisponivelCarro(concessionaria.carros[i]))
            {
                concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], idCliente);
                ImprimeCliente(idCliente, 1);
                ImprimeCarro(concessionaria.carros[i]);
                break;
            }
        }
    }
    else if(qtdPassageiros == -1 && km != -1)
    {
        for(i = 0; i < concessionaria.qtdCarros; i++)
        {
            if(ObtemKmCarro(concessionaria.carros[i]) <= km && EstaDisponivelCarro(concessionaria.carros[i]))
            {    
                concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], idCliente);
                ImprimeCliente(idCliente, 1);
                ImprimeCarro(concessionaria.carros[i]);
                break;
            }
        }
    }
    else
    {
        for(i = 0; i < concessionaria.qtdCarros; i++)
        {
            if(EstaDisponivelCarro(concessionaria.carros[i])){
                concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], idCliente);
                ImprimeCliente(idCliente, 1);
                ImprimeCarro(concessionaria.carros[i]);
                break;
            }
        }
    }

    if(i == concessionaria.qtdCarros)
        printf("Carro Indisponivel\n");

    return concessionaria;
}

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int idCliente)
{
    int i;
    for(i = 0; i < concessionaria.qtdCarros; i++)
    {
        if(ObtemClienteAlugouCarro(concessionaria.carros[i]) == idCliente)
            {
                concessionaria.carros[i] = DevolveCarro(concessionaria.carros[i], idCliente);
                ImprimeCliente(idCliente, 2);
                ImprimeCarro(concessionaria.carros[i]);
                break;
            }
    }

    return concessionaria;
}

int ObtemNumPassageirosCarro(tCarro carro)
{
    return carro.qtdPassageiros;
}

int ObtemClienteAlugouCarro(tCarro carro)
{
    return carro.idCliente;
}

int ObtemKmCarro(tCarro carro)
{
    return carro.km;
}

int EstaDisponivelCarro(tCarro carro)
{
    if(carro.estaDisponivel == 1)
        return 1;
    else
        return 0;
}

tCarro AlugaCarro(tCarro carro, int idCliente)
{
    carro.estaDisponivel = 0;
    carro.idCliente = idCliente;

    return carro;
}

tCarro DevolveCarro(tCarro carro, int idCliente)
{
    carro.estaDisponivel = 1;
    carro.idCliente = 0;

    return carro;
}

void ImprimeCliente(int idCliente, int tipo)
{
    if(tipo == 1)
    {
        printf("Alugado (cliente %d) -> ", idCliente);
    }
    else if (tipo == 2)
    {
        printf("Devolvido (cliente %d) -> ", idCliente);
    }
}
