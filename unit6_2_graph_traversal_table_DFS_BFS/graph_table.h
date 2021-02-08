/*
 * graph_table.h
 *
 *  Created on: 2020��11��24��
 *      Author: Administrator
 */

#ifndef GRAPH_TABLE_H_
#define GRAPH_TABLE_H_

#include <stdlib.h>
#include <stdio.h>

//#define NULL ((void *)0);
/* ͼ���ڽӱ��ʾ�� */
#define MaxVertexNum 100 /* ��󶥵�����Ϊ100 */
typedef int Vertex; /* �ö����±��ʾ���㣬Ϊ���� */
typedef int WeightType; /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType; /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2; /* �����<V1, V2> */
	WeightType Weight; /* Ȩ�� */
};

typedef PtrToENode Edge;

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV; /* �ڽӵ��±� */
	WeightType Weight; /* ��Ȩ�� */
	PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
	PtrToAdjVNode FirstEdge; /* ��ͷָ�� */
    DataType Data;           /* �涥������� */
    /* ע�⣺�ܶ�����£����������ݣ���ʱData���Բ��ó��� */
} AdjList[MaxVertexNum]; /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;     /* ������ */
	int Ne;     /* ���� */
	AdjList G;  /* �ڽӱ� */
	int* Visited; /* �Ƿ񱻷��ʹ� */
};

typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
void PrintGraph(LGraph graph);
LGraph BuildGraphExist();

/* �ڽӱ�洢��ͼ - DFS */
void Visit(LGraph Graph, Vertex V);

/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊ 0 */
void DFS( LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex) );
void BFS( LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex) );

#endif /* GRAPH_TABLE_H_ */
