/*
 * main.c
 *
 *  Created on: 2020Äê11ÔÂ25ÈÕ
 *      Author: Administrator
 */
#include "graph_matrix.h"

int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("hello graph!\n");
	MGraph graph = BuildGraph();
	printf("print graph:\n");
	printGraph(graph);
	printf("print graph end\n");
	return 0;
}

