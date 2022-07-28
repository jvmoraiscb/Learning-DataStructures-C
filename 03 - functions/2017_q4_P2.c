/* 
Problema: (BOCA: P2_2017_Q4) O contador de letrinhas! Um escritor maluco
precisava manter a contagem das letras que estava escrevendo para fluir melhor as
ideias. Para isso, ele criou uma maneira de marcar o texto com símbolos em pontos
especiais, em que a contagem deveria ser feita. Em sua contagem, ele considerava 3
tipos de elementos: letras, vogais e consoantes. Ele utilizava símbolos para saber o
que contar até aquele, e a partir daquele, momento do texto conforme a seguir:
➢ O símbolo *1* no texto representava uma contagem de todas as letras, vogais
e consoantes até aquele ponto do texto. Além disso, ele marcava o início da
contagem para os 3 elementos a partir daquele ponto.
➢ O símbolo *2* no texto representava uma contagem de todas as vogais até
aquele ponto do texto. Além disso, ele marcava o início da contagem das
vogais a partir daquele ponto.
➢ O símbolo *3* no texto representava uma contagem de todas as consoantes
até aquele ponto do texto. Além disso, ele marcava o início da contagem das
consoantes a partir daquele ponto.
A contagem era sempre feita em relação ao último ponto de marcação referente a
um elemento específico (letras, vogais ou consoantes). Os asteriscos ‘*’ eram
considerados caracteres especiais para representar os símbolos, portanto sempre
eram utilizados no texto em pares, ex. *1*, *2*, *3*. Contudo, as vezes o escritor
estava cansado e representava o símbolo de forma errada (ex. *4*, *wqe2*, etc),
porém mantendo os asteriscos ainda em pares. Seu papel a construir um programa
para ler o texto e fazer a contagem de acordo com os marcadores.
• Entrada: um texto terminado com ponto ‘.’ e com alguns marcadores entre asteriscos. Os
asteriscos estão sempre em pares.
• Saída: somente as letras do texto original com o resultado da contagem dependendo do
marcador encontrado. Se um marcador *1* for encontrado, a contagem das letras, vogais e
consoantes deverão ser apresentadas até aquele momento do texto utilizando o formato
“*L:#1 V:#2 C:#3*”, em que #1 representa a contagem de letras até aquele momento, #2
representa a contagem de vogais até aquele momento e #3 representa a contagem de
consoantes até aquele momento (todos considerando a contagem a partir de seu último
marcador, i.e. *1* para letras, *1* ou *2* para vogais e *1* ou *3* para consoantes). Se
um marcador *2* for encontrado, a contagem das vogais deverá ser apresentada até
aquele momento do texto utilizando o formato “*V:#2*”, em que #2 representa a
contagem de vogais até aquele momento (considerando a contagem a partir de seu último
marcador, i.e. um *1* ou um *2*). Se um marcador *3* for encontrado, a contagem das
consoantes deverá ser apresentada até aquele momento do texto utilizando o formato
“*C:#3*”, em que #3 representa a contagem de consoantes até aquele momento 
(considerando a contagem a partir de seu último marcador, i.e. um *1* ou um *3*). Um
símbolo errado deverá ser substituído por “*ERRO*”. Ver exemplos abaixo!
O programa deve ser entregue modularizado, para isso crie:
a) Uma função que recebe um caractere e retorna verdadeiro se ele for letra e falso
caso contrário. Cabeçalho: int EhLetra(char c);
b) Uma função que recebe um caractere e retorna verdadeiro se ele for vogal e falso
caso contrário. Cabeçalho: int EhVogal(char c);
c) Uma função que recebe um caractere representando o primeiro possível caractere
de um dos símbolos. Essa função deverá retornar 0, caso o caractere informado não
seja ‘*’. Caso contrário, ela deverá ler e identificar o símbolo e retorna o valor do
respectivo símbolo (i.e. 1,2 ou 3 para os símbolos *1*, *2* ou *3*
respectivamente). A função deverá retornar -1 caso o símbolo não seja válido e
deverá sempre consumir todos os caracteres até o próximo asterisco. Cabeçalho:
int ReconheceSimbolo(char c);
• Exemplo de Entrada:
Vamos contar letrinhas *1*, e mais algumas*2*, e outras*3*coisas.
Essa 134¨%¨(*1*eh*3*1 test*3*e*2**3**4*.
OLA(*1 we* mundo *3*)! Hello *3* *world* again!*2**3**4*.
• Exemplo de Saída:
Vamoscontarletrinhas*L:20 V:7 C:13*emaisalgumas*V:6*eoutras*C:9*coisas.
Essa*L:4 V:2 C:2*eh*C:1*test*C:3*e*V:3**C:0**ERRO*.
OLA*ERRO*mundo*C:4*Hello*C:3**ERRO*again*V:9**C:2**ERRO*.
*/

#include <stdio.h>

int EhLetra(char c);
int EhVogal(char c);
int ReconheceSimbolo(char c);

void main ()
{
    int simbolo, nLetras = 0, nVogais = 0, nConsoantes = 0; char c;

    while (1)
    {
        scanf("%c", &c);
        simbolo = ReconheceSimbolo(c);

        if (c == '.'){
            printf(".");
            break;
        }
        else if (simbolo != 0)
        {
            if (simbolo == 1){
                printf("*L:%d V:%d C:%d*", nLetras, nVogais, nConsoantes);
                nLetras = 0; nVogais = 0; nConsoantes = 0;
            }
            else if (simbolo == 2){
                printf("*V:%d*", nVogais);
                nVogais = 0;
            }
            else if (simbolo == 3){
                printf("*C:%d*", nConsoantes);
                nConsoantes = 0;
            }
            else if (simbolo == -1)
            {
                printf("*ERRO*");
            }
        }
        else if (EhLetra(c))
        {
            nLetras += 1;
            if (EhVogal(c))
                nVogais += 1;
            else
                nConsoantes += 1;
            printf("%c", c);
        }
    }
}

int EhLetra(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int EhVogal(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
        return 0;
}

int ReconheceSimbolo(char c)
{
    int num; char cSimbolo, nRepeticoes = 0;

    if (c != '*')
        return 0;
    else
    {
        while(1)
        {
            scanf("%c", &cSimbolo);
            if (cSimbolo == '*'){
                if (nRepeticoes != 0)
                    return num;
                else
                    return -1;
                break;
            }
            else if (nRepeticoes == 0)
            {
                if (cSimbolo == '1')
                    num = 1;
                else if (cSimbolo == '2')
                    num = 2;
                else if (cSimbolo == '3')
                    num = 3;
                else
                    num = -1;
                nRepeticoes = 1;
            }
            else if (nRepeticoes != 0)
                num = -1;
        }
    }
}