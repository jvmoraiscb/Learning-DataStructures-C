/*
(BOCA:L4_1) Problema: Faça um programa para ler produtos formados pelos
campos: código (int), preço (float), quantidade em estoque (int). O programa deverá
ao final imprimir uma lista dos produtos que estão em falta, o produto mais caro e o
mais barato. Para isso, implemente e use o tipo tProduto contendo os campos
necessários, e com as seguintes operações: tProduto LeProduto(), int
EhProduto1MaiorQ2(tProduto p1, tProduto p2), int EhProduto1MenorQ2(tProduto
p1, tProduto p2), int TemProdutoEmEstoque(tProduto p), void
ImprimeProduto(tProduto p).
• Entrada: Sua entrada deverá conter o número n de produtos a serem lidos (n>0), seguido
dos produtos em si. Cada produto será dado por seu código, preço e quantidade em
estoque separados por um “;”.
• Saída: Sua saída deverá uma lista dos produtos que estão em falta (em ordem de
ocorrência) precedidos de “FALTA:”, o produto mais caro precedido de “MAIOR:” e o mais
barato precedido de “MENOR:” (em caso de empate, imprima somente a primeira
ocorrência).
• Exemplo de Entrada:
5
234;32.9;2
5324;10.1;0
5454;20.23;22
564;12.1;0
6724;30.1;4
• Exemplo de Saída:
FALTA:COD 5324, PRE 10.10, QTD 0
FALTA:COD 564, PRE 12.10, QTD 0
MAIOR:COD 234, PRE 32.90, QTD 2
MENOR:COD 5324, PRE 10.10, QTD 0 
*/
#include <stdio.h>

typedef struct
{
    int codigo;
    float preco;
    int quantidadeEstoque;
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto produto1, tProduto produto2);
int EhProduto1MenorQ2(tProduto produto1, tProduto produto2);
int TemProdutoEmEstoque(tProduto produto);
void ImprimeProduto(tProduto produto);

void main ()
{
    int nProdutos, produto;
    tProduto produtoAtual, produtoMaisCaro, produtoMaisBarato;

    produtoMaisBarato.preco = 320000;
    produtoMaisCaro.preco = -1;

    scanf("%d", &nProdutos);
    for (produto = 1; produto <= nProdutos; produto++)
    {
        produtoAtual = LeProduto();
        if (EhProduto1MaiorQ2(produtoAtual, produtoMaisCaro))
            produtoMaisCaro = produtoAtual;
        if (EhProduto1MenorQ2(produtoAtual, produtoMaisBarato))
            produtoMaisBarato = produtoAtual;
        if (TemProdutoEmEstoque(produtoAtual) == 0)
        {
            printf("FALTA:");
            ImprimeProduto(produtoAtual);
        }
    }
    
    printf("MAIOR:");
    ImprimeProduto(produtoMaisCaro);
    printf("MENOR:");
    ImprimeProduto(produtoMaisBarato);
}

tProduto LeProduto()
{
    tProduto produto;

    scanf("%d;%f;%d", &produto.codigo, &produto.preco, &produto.quantidadeEstoque);

    return produto;
}

void ImprimeProduto(tProduto produto)
{
    printf("COD %d, PRE %.2f, QTD %d\n", produto.codigo, produto.preco, produto.quantidadeEstoque);
}

int TemProdutoEmEstoque(tProduto produto)
{
    if (produto.quantidadeEstoque != 0)
        return 1;
    else
        return 0;
}

int EhProduto1MaiorQ2(tProduto produto1, tProduto produto2)
{
    if (produto1.preco > produto2.preco)
        return 1;
    else
        return 0;
}

int EhProduto1MenorQ2(tProduto produto1, tProduto produto2)
{
    if (produto1.preco < produto2.preco)
        return 1;
    else
        return 0;
}

