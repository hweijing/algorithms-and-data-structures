#include <stdio.h>

#define MaxSize 10

typedef struct UFSNode {
	int data;
	int rank;
	int parent;
};

void makeSet(UFSNode t[], int n) { //�������鼯���������±�Ϊ 0 ��ʼ��t ��һ���ɽṹ����ɵ�����
	for (int i = 1; i <= n; i++)
	{
		t[i].data = i; //ÿ������ֵ�������Լ���ֵ

		t[i].rank = 0; //ÿ��������Ĭ��Ϊ -1����ʱ�����ж��ٸ���㣬�ü��϶���һ�������ɭ�֣���һ��������һ����

		t[i].parent = i; //ÿ������˫�׽����±�������Լ�
	}
}

int findSet(UFSNode t[], int e) {
	if (e != t[e].parent)
	{
		t[e].parent = findSet(t, t[e].parent);
	}

	return t[e].parent;
}

void unionSet(UFSNode t[], int x, int y) {
	x = findSet(t, x);

	y = findSet(t, y);

	if (t[x].rank > t[y].rank)
	{
		t[y].parent = x;
	}
	else
	{
		t[x].parent = y;

		if (t[x].rank == t[y].rank)
		{
			t[y].rank++;
		}
	}
}

int main() {
	UFSNode t[MaxSize];

	makeSet(t, MaxSize);

	int p = findSet(t, 4);

	unionSet(t, 3, 4);

	unionSet(t, 3, 5);

	unionSet(t, 5, 6);

	unionSet(t, 7, 8);

	unionSet(t, 4, 8);

	return 0;
}
