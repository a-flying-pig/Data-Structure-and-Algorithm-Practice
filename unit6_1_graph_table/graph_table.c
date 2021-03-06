/*
 * graph_table.c
 *
 *  Created on: 2020年11月25日
 *      Author: Administrator
 */
#include "graph_table.h"


LGraph CreateGraph(int VertexNum)
{
    /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V;
	LGraph Graph;

	Graph = (LGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	Graph->G = (AdjList) malloc(sizeof(struct Vnode) * VertexNum);

	/* 初始化邻接表头指针 */
	/* 注意：这里默认顶点编号从0开始，到（Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	/* 插入边 <V1, V2> */
	/* 为V2建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* 将V2插入V1的表头 */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/* 如果是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	/* 将V1插入V2的表头 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	printf("please input the vertex number:\n");
	scanf("%d", &Nv); /* 读入顶点个数 */
	printf("the vertex number is :%d\n\n", Nv);
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但是没有边的图 */

	printf("please input the edge number:\n");
	scanf("%d", &(Graph->Ne)); /* 读入边数 */
	printf("the edge number is :%d\n\n", Graph->Ne);

	printf("please input the edge details:\n");
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge) malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边， 格式为“起点 终点 权重 ”，插入邻接表 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			printf("read edge, start:%d, end:%d, weight:%d\n", E->V1, E->V2, E->Weight);
			InsertEdge(Graph, E);
		}
	}

	printf("\n");
	printf("please input the vertex data:\n");
	/* 如果顶点有数据的话，读入数据 */
	for (V = 0; V < Graph->Nv; V++) {
		setbuf(stdin, NULL);
		scanf("%c", &(Graph->G[V].Data));
		printf("vertex %d data is :%c\n", V, Graph->G[V].Data);
	}

	return Graph;
}

LGraph BuildGraphExist()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	//printf("please input the vertex number:\n");
	//scanf("%d", &Nv); /* 读入顶点个数 */
	//printf("the vertex number is :%d\n\n", Nv);
	Graph = CreateGraph(6); /* 初始化有Nv个顶点但是没有边的图 */

	//printf("please input the edge number:\n");
	//scanf("%d", &(Graph->Ne)); /* 读入边数 */
	//printf("the edge number is :%d\n\n", Graph->Ne);

	Graph->Ne = 8;

	//printf("please input the edge details:\n");
	//if (Graph->Ne != 0) { /* 如果有边 */
		//E = (Edge) malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边， 格式为“起点 终点 权重 ”，插入邻接表 */
		//for (i = 0; i < Graph->Ne; i++) {
			//scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			//printf("read edge, start:%d, end:%d, weight:%d\n", E->V1, E->V2, E->Weight);
			//InsertEdge(Graph, E);
		//}
	//}
	E = (Edge) malloc(sizeof(struct ENode)); /* 建立边结点 */
	E->V1 = 0, E->V2 = 1, E->Weight = 1;
	InsertEdge(Graph, E);

	E->V1 = 0, E->V2 = 2, E->Weight = 2;
	InsertEdge(Graph, E);

	E->V1 = 0, E->V2 = 3, E->Weight = 3;
	InsertEdge(Graph, E);

	E->V1 = 1, E->V2 = 5, E->Weight = 2;
	InsertEdge(Graph, E);

	E->V1 = 3, E->V2 = 5, E->Weight = 7;
	InsertEdge(Graph, E);

	E->V1 = 2, E->V2 = 4, E->Weight = 5;
	InsertEdge(Graph, E);

	E->V1 = 3, E->V2 = 2, E->Weight = 3;
	InsertEdge(Graph, E);

	E->V1 = 5, E->V2 = 4, E->Weight = 6;
	InsertEdge(Graph, E);

	printf("\n");
	printf("please input the vertex data:\n");
	/* 如果顶点有数据的话，读入数据 */
//	for (V = 0; V < Graph->Nv; V++) {
//		setbuf(stdin, NULL);
//		scanf("%c", &(Graph->G[V].Data));
//		printf("vertex %d data is :%c\n", V, Graph->G[V].Data);
//	}
	Graph->G[0].Data = '0';
	Graph->G[1].Data = '1';
	Graph->G[2].Data = '2';
	Graph->G[3].Data = '3';
	Graph->G[4].Data = '4';
	Graph->G[5].Data = '5';

	return Graph;
}

void PrintGraph(LGraph graph) {
    printf("start print the graph:\n");
    int i;
    for (i = 0; i < graph->Nv; i++) {
    	printf("vertex: %d data:%c\n", i, graph->G[i].Data);
    	PtrToAdjVNode node = graph->G[i].FirstEdge;
    	while (node != NULL) {
        	printf("linked table, vertex:%d, weight:%d\n", node->AdjV, node->Weight);
        	node = node->Next;
    	}
    }
}




















