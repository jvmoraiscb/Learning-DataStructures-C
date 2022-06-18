/*

 * ProgListaTarefas2.c
 *
 * Segundo Testador: vale 8,0
 * Testa: Criação, inserção, impressão e retirada
 *
 *      Author: pdcosta
 */


#include <stdio.h>
#include "ListaTarefas.h"


int main()
{

    //criando a lista de tarefas de Paulo
	ListaTarefas* lista = criaListaTarefas();

	//------------- criando base de dados para testes
	Tarefa* tarefaProva = criaTarefa("EstudarProvaED");
    insereProcedimentoTarefa(tarefaProva, "Pegar material no site");
    insereProcedimentoTarefa(tarefaProva, "Baixar os slides");
    insereProcedimentoTarefa(tarefaProva, "Refazer todos os labs");
    insereProcedimentoTarefa(tarefaProva, "Fazer o trabalho!");

   //inserindo a tarefa na lista
    insereTarefaLista(lista, tarefaProva);

	Tarefa* tarefaTrabalho = criaTarefa("FazerTrabalhoED");
    insereProcedimentoTarefa(tarefaTrabalho, "Ler especificação");
    insereProcedimentoTarefa(tarefaTrabalho, "Marcar reuniões com a dupla");
    insereProcedimentoTarefa(tarefaTrabalho, "Projetar solução");
    insereProcedimentoTarefa(tarefaTrabalho, "Codificar!!!");

    insereTarefaLista(lista, tarefaTrabalho);

	Tarefa* tarefaMatricula = criaTarefa("MatricularIngles");
    insereProcedimentoTarefa(tarefaMatricula, "Preparar documentação");
    insereProcedimentoTarefa(tarefaMatricula, "Fazer prova nivelamento");
    insereProcedimentoTarefa(tarefaMatricula, "Pagar inscrição");

    insereTarefaLista(lista, tarefaMatricula);

    //-----------------------------------------------------


    // agora vamos manipular a lista para ver se as funções foram corretamente implementadas :)


    printf ("\n Lista de Tarefas: \n");
    //imprime a lista de tarefas
    imprimeListaTarefas(lista);

    // retira a tarefa do meio da lista
    Tarefa* t1 = retiraTarefaLista (lista, "FazerTrabalhoED");

     printf ("\n Lista de Tarefas: \n");
    //imprime a lista de tarefas novamente
    imprimeListaTarefas(lista);

    //agora tenta retirar uma tarefa inexistente
    Tarefa* t2 = retiraTarefaLista (lista, "FazerTrabalhoED");

    if (t2==NULL)
     	printf ("\n Lista vazia ou tarefa não encontrada \n");


    //agora vamos retirar uma tarefa no início da lista
    Tarefa* t3 = retiraTarefaLista(lista, "MatricularIngles");


    printf ("\n Lista de Tarefas: \n");
    //imprime a lista de tarefas novamente
    imprimeListaTarefas(lista);

    //agora vamos inserir t1 e t3 novamente na lista
    insereTarefaLista(lista, t3);
    insereTarefaLista(lista, t1);

     printf ("\n Lista de Tarefas: \n");
     imprimeListaTarefas(lista);

}


