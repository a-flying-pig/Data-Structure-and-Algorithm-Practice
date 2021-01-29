/*
 * graph_table.c
 *
 *  Created on: 2020��11��25��
 *      Author: Administrator
 */
#include "graph_table.h"


LGraph CreateGraph(int VertexNum)
{
    /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V;
	LGraph Graph;

	Graph = (LGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӱ�ͷָ�� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ������Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	/* ����� <V1, V2> */
	/* ΪV2�����µ��ڽӵ� */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* ��V2����V1�ı�ͷ */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/* ���������ͼ����Ҫ����� <V2, V1> */
	/* ΪV1�����µ��ڽӵ� */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	/* ��V1����V2�ı�ͷ */
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
	scanf("%d", &Nv); /* ���붥����� */
	printf("the vertex number is :%d\n\n", Nv);
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫��û�бߵ�ͼ */

	printf("please input the edge number:\n");
	scanf("%d", &(Graph->Ne)); /* ������� */
	printf("the edge number is :%d\n\n", Graph->Ne);

	printf("please input the edge details:\n");
	if (Graph->Ne != 0) { /* ����б� */
		E = (Edge) malloc(sizeof(struct ENode)); /* �����߽�� */
		/* ����ߣ� ��ʽΪ����� �յ� Ȩ�� ���������ڽӱ� */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
			printf("read edge, start:%d, end:%d, weight:%d\n", E->V1, E->V2, E->Weight);
			InsertEdge(Graph, E);
		}
	}

	printf("\n");
	printf("please input the vertex data:\n");
	/* ������������ݵĻ����������� */
	for (V = 0; V < Graph->Nv; V++) {
		setbuf(stdin, NULL);
		scanf("%c", &(Graph->G[V].Data));
		printf("vertex %d data is :%c\n", V, Graph->G[V].Data);
	}

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




















