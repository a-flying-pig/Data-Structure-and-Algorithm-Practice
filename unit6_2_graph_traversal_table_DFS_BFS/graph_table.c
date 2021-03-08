/*
 * graph_table.c
 *
 *  Created on: 2020��11��25��
 *      Author: Administrator
 */
#include "graph_table.h"
#include "LinkedQueue.h"

LGraph CreateGraph(int VertexNum)
{
    /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V;
	LGraph Graph;

	Graph = (LGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	Graph->G = (AdjList) malloc(sizeof(struct Vnode) * VertexNum);
	/* ��ʼ���ڽӱ�ͷָ�� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ������Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

    Graph->Visited = (int*) malloc(sizeof(int) * VertexNum);
    for (int i = 0; i < VertexNum; i++) {
    	Graph->Visited[i] = 0;
    }

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

LGraph BuildGraphExist()
{
	LGraph Graph;
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
	Graph->G[0].Data = 'a';
	Graph->G[1].Data = 'b';
	Graph->G[2].Data = 'c';
	Graph->G[3].Data = 'd';
	Graph->G[4].Data = 'e';
	Graph->G[5].Data = 'f';

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

void Visit(LGraph Graph, Vertex V)
{
	printf("visiting vertex:%d, data:%c\n", V, Graph->G[V].Data);
	 Graph->Visited[V] = 1;
}

void DFS( LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex))
{
	VisitFunc(Graph, V);
	//if (V �����е����ӵ�δ�� ���ʹ�) {DFS}

	for (PtrToAdjVNode node = Graph->G[V].FirstEdge; node != NULL; node = node->Next) {
		if (Graph->Visited[node->AdjV] != 1) {
			DFS(Graph, node->AdjV, VisitFunc);
		}
	}
}


void BFS(LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex))
{
    // ���ʸýڵ㣬Ȼ����ӵ����У��Ա������ʱѰ�����ڽӵ�
    VisitFunc(Graph, V);


    printf("\nenque the first node \n");
    Queue queue = createQueue();
    enque(queue, V);

    // ���ýڵ��Ƴ����У�Ȼ�����ڽӵ���δ���ʹ��ڵ���з��ʣ�Ȼ�������У�ѭ����ֱ�����нڵ������
    while (!isEmpty(queue)) {
        Vertex v = deque(queue); // ����
        //printf("\ndeque the vertex:%d \n", v);

        // �����еĽ��������ڽӵ���з��ʣ������ѷ��ʵ���ӵ�����
        for (PtrToAdjVNode node = Graph->G[v].FirstEdge; node != NULL; node = node->Next) {
        	//printf("\n print the advNode vertex:%d , visited: %d\n", node->AdjV, Graph->Visited[node->AdjV]);
            if (Graph->Visited[node->AdjV] != 1) { // ���δ���ʹ�������
            	//printf("\n print the doesn't visit vertex:%d \n", node->AdjV);
                VisitFunc(Graph, node->AdjV);
                Graph->Visited[node->AdjV] = 1;
                enque(queue, node->AdjV); // ���ʺ���ӵ�����
            }
        }
    }
}


/*
void BFS(LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex))
{

    PtrToAdjVNode adjVNode = Graph->G[V].FirstEdge;

    printf("\nenque the first node \n");
    Queue queue = createQueue();
    enque(queue, V);

    // ���ýڵ��Ƴ����У����з��ʣ�Ȼ�������δ���ʹ����ڽӵ�Ķ��У�ѭ����ֱ�����нڵ������
    while (!isEmpty(queue)) {
        Vertex v = deque(queue); // ����
        //printf("\ndeque the vertex:%d \n", v);
        VisitFunc(Graph, v);
        Graph->Visited[v] = 1;
        // �����еĽ��������ڽӵ���з��ʣ��������ʵ���ӵ�����
        for (PtrToAdjVNode node = Graph->G[v].FirstEdge; node != NULL; node = node->Next) {
        	//printf("\n print the advNode vertex:%d , visited: %d\n", node->AdjV, Graph->Visited[node->AdjV]);
            if (Graph->Visited[node->AdjV] != 1) { // ���δ���ʹ�����ӵ����У�δ�����ʹ��Ķ�����ܱ������ӽ�ȥ��������ɶ�η��ʡ�
            	//printf("\n print the doesn't visit vertex:%d \n", node->AdjV);
                enque(queue, node->AdjV);
            }
        }
    }
}
*/














