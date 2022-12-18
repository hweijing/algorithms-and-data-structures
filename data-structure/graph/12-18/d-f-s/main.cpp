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

//深度优先遍历
int visited[MaxSize] = { 0 };

void DFS(AdjGraph *g, int e) { //e 为初始顶点，因为该邻接矩阵对应的图不是强连通图，所以无法一次遍历完成
	visited[e] = 1;

	printf("%d", g->adjlist[e].name);

	SideNode* p = g->adjlist[e].firstsnode;

	while (p != NULL)
	{
		if (visited[p->name] == 0)
		{
			DFS(g, p->name);
		}

		p = p->next;
	}
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

	//0 1 2 4 3 
	//DFS(g, 0);

	//1 2 4
	//DFS(g, 1);

	//2 4
	DFS(g, 2);

	return 0;
}