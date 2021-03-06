/*
 * graph_matrix.c
 *
 *  Created on: 2020��11��23��
 *      Author: Administrator
 */
#include "graph_matrix.h"


MGraph CreateGraph(int VertexNum)
{
	/* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph) malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->G =(WeightType**) malloc(sizeof(WeightType*) * VertexNum);
	for(int i = 0; i < VertexNum; i++) {
		Graph->G[i] = (WeightType*) malloc(sizeof(WeightType) * VertexNum);
	}
	Graph->Data = (DataType*) malloc(sizeof(DataType) * VertexNum);
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	Graph->Visited = (int*) malloc(sizeof(int) * VertexNum);
	for (int i = 0; i < Graph->Nv; i++) {
		Graph->Visited[i] = 0;
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* ��������ͼ����Ҫ�����<V2, V1> */
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
	scanf("%d", &Nv); /* ���붥����� */
	printf("read Nv:%d\n", Nv);
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	printf("please input edge number:\n");
	scanf("%d", &(Graph->Ne)); /* ������� */
	printf("read Ne:%d\n", Graph->Ne);
	printf("\n");
	printf("please input edge details: start_vertex end_vertex weight\n");
	if (Graph->Ne != 0) {  //����б�
		E = (Edge)malloc(sizeof(struct ENode));  //�����߽��
		 // ����ߣ���ʽΪ�� ��� �յ� Ȩ�ء��������ڽӾ���
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			 // ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ��
			printf("read start:%d, end:%d, weight:%d insert this edge\n", E->V1, E->V2, E->Weight);
			InsertEdge(Graph, E);
		}
	}

	printf("\n");
	printf("please input vertex data:\n");
	/* ������������ݵĻ����������� */
	for (V=0; V < Graph->Nv; V++) {
		setbuf(stdin,NULL); // char����ʱ��Ҫ���buffer��more info:https://blog.csdn.net/jack0201/article/details/77533168
		                    // more info:http://c.biancheng.net/view/160.html
		scanf("%c", &(Graph->Data[V]));
        printf("read vertex data:%c\n", Graph->Data[V]);
	}
        //char i1, j, k;
        //scanf("\n%c%c%c", &i1, &j, &k);
        //printf("i1 = %c, j = %c, k = %c\n", i1, j, k);
	return Graph;
}

MGraph BuildGraphExist()
{
	MGraph Graph;
	Edge E;
	Graph = CreateGraph(6); /* ��ʼ����Nv�����㵫��û�бߵ�ͼ */

	Graph->Ne = 8;

	E = (Edge) malloc(sizeof(struct ENode)); /* �����߽�� */
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
	/* ������������ݵĻ����������� */
//	for (V = 0; V < Graph->Nv; V++) {
//		setbuf(stdin, NULL);
//		scanf("%c", &(Graph->G[V].Data));
//		printf("vertex %d data is :%c\n", V, Graph->G[V].Data);
//	}
	Graph->Data[0] = 'a';
	Graph->Data[1] = 'b';
	Graph->Data[2] = 'c';
	Graph->Data[3] = 'd';
	Graph->Data[4] = 'e';
	Graph->Data[5] = 'f';

	return Graph;
}

void PrintGraph(MGraph graph)
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

void Visit(MGraph Graph, Vertex V) {
	printf("visiting vertex:%d, data:%c\n", V, Graph->Data[V]);
	Graph->Visited[V] = 1;
}

void DFS(MGraph Graph, Vertex V, void (*VisitFunc)(MGraph, Vertex)) {
	VisitFunc(Graph, V);
	for(int i = 0; i < Graph->Nv; i++) { // ��V��ÿ����ͨ�Ķ���
		if (Graph->G[V][i] != INFINITY) { // �õ�����ͨ��
			if (!Graph->Visited[i]) { // ���û�з��ʹ���ȥ����
				DFS(Graph, i, VisitFunc);
			}
		}
	}
}

// void BFS(MGraph Graph, Vertex V, void (*VisitFunc)(MGraph, Vertex));
