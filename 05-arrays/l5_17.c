/* 
(BOCA:L5_17) Problema: Faça um programa que leia palavras de um texto e
imprima o texto de trás para frente com as palavras separadas por espaço e sem
pontuação ou qualquer outro caractere que não seja letra. Percebe que a palavra em
si deve permanecer com sua ordem natural de letras.
 Entrada: um texto contendo no máximo 500 palavras. Considere palavras com no máximo
500 caracteres.
 Saída: o texto impresso de trás para frente com as palavras separadas por espaço e sem
caracteres que não sejam letra.
 Exemplo de Entrada:
A computer is a general-purpose device that can be programmed to carry out a set of
arithmetic or logical operations automatically. Since a sequence of operations can be
readily changed, the computer can solve more than one kind of problem.
Conventionally, a computer consists of at least one processing element, typically a central
processing unit (CPU), and some form of memory. The processing element carries out
arithmetic and logic operations, and a sequencing and control unit can change the order of
operations in response to stored information. Peripheral devices allow information to be
retrieved from an external source, and the result of operations saved and retrieved.
 Exemplo de Saída:
retrieved and saved operations of result the and source external an from retrieved be to
information allow devices Peripheral information stored to response in operations of order
the change can unit control and sequencing a and operations logic and arithmetic out
carries element processing The memory of form some and CPU unit processing central a
typically element processing one least at of consists computer a Conventionally problem of
kind one than more solve can computer the changed readily be can operations of sequence
a Since automatically operations logical or arithmetic of set a out carry to programmed be
can that device purpose general a is computer A
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char palavra[500]
} tTexto;

void leTexto(tTexto *texto);
void imprimeTexto(tTexto *texto);

int main()
{
    tTexto texto [501];

    leTexto(texto);
    imprimeTexto(texto);
}

void leTexto(tTexto *texto)
{
    int i;

    for(i = 0; i < 501; i++)
    {
        texto[i].palavra[0] = '\0';
    }

    for(i = 0; i < 501; i++)
    {
        scanf("%[a-zA-Z]%*[^a-zA-Z]", texto[i].palavra);
    }
}

void imprimeTexto(tTexto *texto)
{
    int i;

    for(i = 500; i >= 0; i--)
    {
        if(texto[i].palavra[0] != '\0'){
            if(i != 0)
                printf("%s ", texto[i].palavra);
            else
                printf("%s", texto[i].palavra);
        }
    }
}