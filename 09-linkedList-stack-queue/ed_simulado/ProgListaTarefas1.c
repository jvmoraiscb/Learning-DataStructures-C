/*
 * ProgListaTarefas1.c
 *
 *  Primeiro Testador: vale 6,0
 *  Testa: Criação, inserção e impressão
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

    printf ("\n Lista de Tarefas: \n");
    //imprime a lista de tarefas
    imprimeListaTarefas(lista);

}

