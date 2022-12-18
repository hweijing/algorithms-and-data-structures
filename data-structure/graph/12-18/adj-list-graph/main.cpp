#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef struct SideNode { //边界点，类似于没有头结点单链表
	int name; //边界点的名称
	struct SideNode* next; //指向下一个边界点
	int weight; //边界点的权重
};

typedef struct HeadNode {
	int name; //头结点的名称
	struct SideNode* firstsnode; //指向第一个边界点，单链表的头结点
};

typedef struct AdjGraph {
	struct HeadNode adjlist[MaxSize]; //由头结点的结构体组成的数组，不是结构体指针
	int n; //图中结点的个数
	int e; //图中边的个数
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

void dispAdjGraph(AdjGraph* g) {
	SideNode* p;

	for (int i = 0; i < g->n; i++)
	{
		printf("%3d:", g->adjlist[i].name);

		p = g->adjlist[i].firstsnode;

		while (p != NULL)
		{
			printf("%3d[%d]->", p->name, p->weight);

			p = p->next;
		}

		printf("^\n");
	}
}

void destoryAdjGraph(AdjGraph *&g) {
	SideNode* pre, * p;

	for (int i = 0; i < g->n; i++)
	{
		pre = g->adjlist[i].firstsnode;

		if (pre != NULL)
		{
			p = pre->next;

			while (p != NULL)
			{
				free(pre);

				pre = p;

				p = p->next;
			}

			free(pre);
		}
	}

	free(g);
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

	dispAdjGraph(g);

	return 0;
}