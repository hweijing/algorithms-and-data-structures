#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef struct SideNode {
	int name;
	struct SideNode* next;
	int weight;
};

typedef struct HeadNode {
	int name;
	struct SideNode* firstsnode;
};

typedef struct AdjGraph {
	struct HeadNode adjlist[MaxSize];
	int n;
	int e;
};

typedef struct CirQueue {
	int data[MaxSize];
	int front;
	int rear;
};

void initCirQueue(CirQueue*& q) {
	q = (CirQueue*)malloc(sizeof(CirQueue));

	q->front = q->rear = 0;
}

void destoryCirQueue(CirQueue*& q) {
	free(q);
}

bool isEmptyCirQueue(CirQueue* q) {
	return q->front == q->rear;
}

bool enCirQueue(CirQueue*& q, int e) {
	if ((q->rear + 1) % MaxSize == q->front)
	{
		return false;
	}

	q->rear = (q->rear + 1) % MaxSize;

	q->data[q->rear] = e;

	return true;
}

bool deCirQueue(CirQueue*& q, int& e) {
	if (q->front == q->rear)
	{
		return false;
	}

	q->front = (q->front + 1) % MaxSize;

	e = q->data[q->front];

	return true;
}

void createAdjGraph(AdjGraph*& g, int a[MaxSize][MaxSize], int n, int e) {
	g = (AdjGraph*)malloc(sizeof(AdjGraph));

	SideNode* p;

	int i, j;

	for (i = 0; i < n; i++)
	{
		g->adjlist[i].firstsnode = NULL;

		g->adjlist[i].name = i;
	}

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j >= 0; j--)
		{
			if (a[i][j] != 0 && a[i][j] != _CRT_INT_MAX)
			{
				p = (SideNode*)malloc(sizeof(SideNode));

				p->name = j;

				p->weight = a[i][j];

				p->next = g->adjlist[i].firstsnode;

				g->adjlist[i].firstsnode = p;
			}
		}
	}

	g->e = e;

	g->n = n;
}

void BFS(AdjGraph* g, int e) {
	CirQueue* q;

	SideNode* p;

	int visited[MaxSize] = { 0 }, w;

	visited[e] = 1;

	initCirQueue(q);

	printf("%d", e);

	enCirQueue(q, e);

	while (!isEmptyCirQueue(q))
	{
		deCirQueue(q, w);

		p = g->adjlist[w].firstsnode;

		while (p != NULL)
		{
			if (visited[p->name] == 0)
			{
				visited[p->name] = 1;

				printf("%d", p->name);

				enCirQueue(q, p->name);
			}

			p = p->next;
		}
	}

	destoryCirQueue(q);
}

int main() {
	int a[MaxSize][MaxSize] = {
		{0,8,_CRT_INT_MAX,5,_CRT_INT_MAX},
		{_CRT_INT_MAX,0,3,_CRT_INT_MAX,_CRT_INT_MAX},
		{_CRT_INT_MAX,_CRT_INT_MAX,0,_CRT_INT_MAX,6},
		{_CRT_INT_MAX,_CRT_INT_MAX,9,0,_CRT_INT_MAX},
		{_CRT_INT_MAX,_CRT_INT_MAX,_CRT_INT_MAX,_CRT_INT_MAX,0}
	};

	AdjGraph* g;

	createAdjGraph(g, a, 5, 8);

	//0 1 3 2 4
	//BFS(g, 0);

	//1 2 4
	BFS(g, 1);

	return 0;
}