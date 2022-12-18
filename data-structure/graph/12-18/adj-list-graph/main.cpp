#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef struct SideNode { //�߽�㣬������û��ͷ��㵥����
	int name; //�߽�������
	struct SideNode* next; //ָ����һ���߽��
	int weight; //�߽���Ȩ��
};

typedef struct HeadNode {
	int name; //ͷ��������
	struct SideNode* firstsnode; //ָ���һ���߽�㣬�������ͷ���
};

typedef struct AdjGraph {
	struct HeadNode adjlist[MaxSize]; //��ͷ���Ľṹ����ɵ����飬���ǽṹ��ָ��
	int n; //ͼ�н��ĸ���
	int e; //ͼ�бߵĸ���
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