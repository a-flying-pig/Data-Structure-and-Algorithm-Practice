/*
 * main.c
 *
 *  Created on: 2020Äê11ÔÂ25ÈÕ
 *      Author: Administrator
 */
#include "graph_table.h"

int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("hello graph!\n");
	//LGraph graph = BuildGraph();

	LGraph graph = BuildGraphExist();
	printf("print graph:\n");
	PrintGraph(graph);
	printf("print graph end\n");
	return 0;
}


