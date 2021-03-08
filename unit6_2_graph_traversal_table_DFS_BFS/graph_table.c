/*
 * graph_table.c
 *
 *  Created on: 2020年11月25日
 *      Author: Administrator
 */
#include "graph_table.h"
#include "LinkedQueue.h"

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

    Graph->Visited = (int*) malloc(sizeof(int) * VertexNum);
    for (int i = 0; i < VertexNum; i++) {
    	Graph->Visited[i] = 0;
    }

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
	Graph = CreateGraph(6); /* 初始化有Nv个顶点但是没有边的图 */

	Graph->Ne = 8;

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
	//if (V 的所有的连接点未被 访问过) {DFS}

	for (PtrToAdjVNode node = Graph->G[V].FirstEdge; node != NULL; node = node->Next) {
		if (Graph->Visited[node->AdjV] != 1) {
			DFS(Graph, node->AdjV, VisitFunc);
		}
	}
}


void BFS(LGraph Graph, Vertex V, void (*VisitFunc)(LGraph, Vertex))
{
    // 访问该节点，然后添加到队列，以便出队列时寻找其邻接点
    VisitFunc(Graph, V);


    printf("\nenque the first node \n");
    Queue queue = createQueue();
    enque(queue, V);

    // 将该节点移出队列，然后将其邻接点中未访问过节点进行访问，然后加入队列，循环，直到所有节点访问完
    while (!isEmpty(queue)) {
        Vertex v = deque(queue); // 出队
        //printf("\ndeque the vertex:%d \n", v);

        // 出队列的结点的所有邻接点进行访问，并将已访问的添加到队列
        for (PtrToAdjVNode node = Graph->G[v].FirstEdge; node != NULL; node = node->Next) {
        	//printf("\n print the advNode vertex:%d , visited: %d\n", node->AdjV, Graph->Visited[node->AdjV]);
            if (Graph->Visited[node->AdjV] != 1) { // 如果未访问过，访问
            	//printf("\n print the doesn't visit vertex:%d \n", node->AdjV);
                VisitFunc(Graph, node->AdjV);
                Graph->Visited[node->AdjV] = 1;
                enque(queue, node->AdjV); // 访问后添加到队列
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

    // 将该节点移出队列，进行访问，然后加入其未访问过的邻接点的队列，循环，直到所有节点访问完
    while (!isEmpty(queue)) {
        Vertex v = deque(queue); // 出队
        //printf("\ndeque the vertex:%d \n", v);
        VisitFunc(Graph, v);
        Graph->Visited[v] = 1;
        // 出队列的结点的所有邻接点进行访问，并将访问的添加到队列
        for (PtrToAdjVNode node = Graph->G[v].FirstEdge; node != NULL; node = node->Next) {
        	//printf("\n print the advNode vertex:%d , visited: %d\n", node->AdjV, Graph->Visited[node->AdjV]);
            if (Graph->Visited[node->AdjV] != 1) { // 如果未访问过，添加到队列；未被访问过的顶点可能被多次添加进去，进而造成多次访问。
            	//printf("\n print the doesn't visit vertex:%d \n", node->AdjV);
                enque(queue, node->AdjV);
            }
        }
    }
}
*/














