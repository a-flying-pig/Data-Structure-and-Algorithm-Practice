/*
 * graph_matrix.c
 *
 *  Created on: 2020年11月23日
 *      Author: Administrator
 */
#include "graph_matrix.h"


MGraph CreateGraph(int VertexNum)
{
	/* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	Nv = 0;
	printf("please input vertex number:\n");
	scanf("%d", &Nv); /* 读入顶点个数 */
	printf("read Nv:%d\n", Nv);
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	printf("please input edge number:\n");
	scanf("%d", &(Graph->Ne)); /* 读入边数 */
	printf("read Ne:%d\n", Graph->Ne);
	printf("\n");
	printf("please input edge details:\n");
	if (Graph->Ne != 0) {  //如果有边
		E = (Edge)malloc(sizeof(struct ENode));  //建立边结点
		 // 读入边，格式为“ 起点 终点 权重”，插入邻接矩阵
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			 // 注意：如果权重不是整型，Weight的读入格式要改
			printf("read start:%d, end:%d, weight:%d insert this edge\n", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}

	printf("\n");
	printf("please input vertex data:\n");
	/* 如果顶点有数据的话，读入数据 */
	for (V=0; V < Graph->Nv; V++) {
		setbuf(stdin,NULL); // more info:https://blog.csdn.net/jack0201/article/details/77533168
		                    // more info:http://c.biancheng.net/view/160.html
		scanf("%c", &(Graph->Data[V]));
        printf("read vertex data:%c\n", Graph->Data[V]);
	}
        //char i1, j, k;
        //scanf("\n%c%c%c", &i1, &j, &k);
        //printf("i1 = %c, j = %c, k = %c\n", i1, j, k);
	return Graph;
}

void printGraph(MGraph graph)
{
	printf("\n");
	int i, j;
	for (i = 0; i < graph->Nv; i++) {
		for (j = 0; j < graph->Nv; j++) {
			printf(" start:%d end:%d  weight:%d \n", i, j, graph->G[i][j]);
		}
		printf("vertex data:%c \n", graph->Data[i]);
	}
}


