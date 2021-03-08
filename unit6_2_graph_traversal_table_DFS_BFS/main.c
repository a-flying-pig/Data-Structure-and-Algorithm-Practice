/*
 * main.c
 *
 *  Created on: 2020Äê11ÔÂ25ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include "graph_table.h"

int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("hello graph!\n");
	//LGraph graph = BuildGraph();

	LGraph graph = BuildGraphExist();

//	printf("print graph:\n");
//	PrintGraph(graph);
//	printf("print graph end\n");

//	printf("\n visit the graph(DFS):\n");
//	DFS(graph, 0, Visit);
//	printf("\n visit the graph end \n");

	printf("\n visit the graph(BFS):\n");
	BFS(graph, 0, Visit);
	printf("\n visit the graph end \n");

	return 0;
}


