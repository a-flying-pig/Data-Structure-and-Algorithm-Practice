/*
 * graph_table.h
 *
 *  Created on: 2020年11月24日
 *      Author: Administrator
 */

#ifndef GRAPH_TABLE_H_
#define GRAPH_TABLE_H_

#include <stdlib.h>
#include <stdio.h>

//#define NULL ((void *)0);
/* 图的邻接表表示法 */
#define MaxVertexNum 100 /* 最大顶点数设为100 */
typedef int Vertex; /* 用顶点下标表示顶点，为整型 */
typedef int WeightType; /* 边的权值设为整型 */
typedef char DataType; /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2; /* 有向边<V1, V2> */
	WeightType Weight; /* 权重 */
};

typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV; /* 邻接点下标 */
	WeightType Weight; /* 边权重 */
	PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
	PtrToAdjVNode FirstEdge; /* 表头指针 */
    DataType Data;           /* 存顶点的数据 */
    /* 注意：很多情况下，定点无数据，此时Data可以不用出现 */
} AdjList[MaxVertexNum]; /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;     /* 顶点数 */
	int Ne;     /* 边数 */
	AdjList G;  /* 邻接表 */
	int* Visited; /* 是否被访问过 */
};

typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
void PrintGraph(LGraph graph);
LGraph BuildGraphExist();

/* 邻接表存储的图 - DFS */
void Visit(LGraph Graph, Vertex V);

/* Visited[]为全局变量，已经初始化为 0 */
void DFS( LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex) );
void BFS( LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex) );

#endif /* GRAPH_TABLE_H_ */
