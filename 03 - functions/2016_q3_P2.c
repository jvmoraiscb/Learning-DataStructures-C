/* 
Problema: (BOCA: P2_2016_Q3) A gula é considerada um dos sete pecados
capitais. Uma padaria resolveu identificar seu cliente mais guloso e pediu para que
você fizesse um programa para ajuda-los. Nessa padaria, o cliente será considerado
o mais guloso quando ele for o que comprar a maior quantidade de um mesmo
produto. Portanto, o programa deve receber uma lista de clientes com os produtos
comprados por eles, e imprimir o código do primeiro cliente da lista que comprou a
maior quantidade de um mesmo produto seguido da quantidade comprada daquele
produto.
 Entrada: uma lista de clientes com um cliente por linha. Cada linha tem um número inteiro
não negativo representando o código do cliente seguido dos produtos comprados por
aquele cliente (representados por letras maiúsculas, portanto outros caracteres devem ser
desconsiderados na contagem). A lista de clientes acaba quando o código encontrado for -1
e a lista de produtos comprados por cada cliente acaba quando o caractere ‘0’ for lido. Os
produtos de cada cliente estão agrupados por tipo para facilitar sua contagem (ou seja,
caracteres iguais aparecem sempre lado a lado).
 Saída: Uma mensagem informando o cliente mais guloso seguido da quantidade comprada
do produto da gula. Ver formatação de saída nos exemplos abaixo.
O programa a ser entregue para a padaria deve estar modularizado para facilitar
futuras manutenções, para isso crie:
a) Uma função que recebe um caractere e retorne verdadeiro se ele for produto, e
falso caso contrário. Cabeçalho: int EhProduto(char prd);
b) Uma função que recebe um caractere e retorne verdadeiro se for o final da lista, e
falso caso contrário. Cabeçalho: int AcabaramOsProdutos(char prd);
c) Uma função que retorne a quantidade do produto mais comprado por um cliente.
Assuma que a função será chamada no início da leitura da lista de produtos do
cliente e retornará após ler o caractere terminador ‘0’.
Cabeçalho: int QtdDoProdutoMaisComprado();
 Exemplo de Entrada:
1 ABCDEFG0
2 AA***BCCCaYyyyyyDDD0
3 F0
4 ABCDEFG0
5 AABBBCCDD0
-1
3 AA***BCCCaYyyyyyDDD0
1 HHHHH0
2 F0
4 ZZZZZZMMMA0
-1
3 AA***BCCCaYyyyyyDDD0
1 ABCDEFG0
2 F0
6 ZZZZZZMMMA0
5 ZZZZZZMMMA0
-1
 Exemplo de Saída:
CLIENT:2 QTD:3
CLIENT:4 QTD:6
CLIENT:6 QTD:6
*/

#include <stdio.h>

int EhProduto(char produto);
int AcabaramOsProdutos(char produto);
int QtdDoProdutoMaisComprado();

void main()
{
    int cliente, clienteMaisGuloso, quantidadeCliente, maiorQuantidade=0;

    while (1)
    {
        scanf("%d", &cliente);
        if (cliente == -1){
            break;
        }
        quantidadeCliente = QtdDoProdutoMaisComprado();
        if (quantidadeCliente > maiorQuantidade){
            clienteMaisGuloso = cliente;
            maiorQuantidade = quantidadeCliente;
        }
    }

    printf("CLIENT:%d QTD:%d", clienteMaisGuloso, maiorQuantidade);
}

int EhProduto(char produto)
{
    if (produto >= 'A' && produto <= 'Z')
        return 1;
    else
        return 0;
}

int AcabaramOsProdutos(char produto)
{
    if (produto == '0')
        return 1;
    else
        return 0;
}

int QtdDoProdutoMaisComprado()
{
    char produto, mesmoProduto = ' '; int quantidade = 0, maiorQuantidade = 0;

    while (1)
    {
        scanf(" %c", &produto);
        if (AcabaramOsProdutos(produto))
        {
            break;
        }
        if (EhProduto(produto))
        {
            if (produto == mesmoProduto)
            {
                quantidade++;
            }
            else {
                mesmoProduto = produto;
                if (quantidade > maiorQuantidade)
                    maiorQuantidade = quantidade;
                quantidade = 1;
            }
        }
    }

    return maiorQuantidade;
}