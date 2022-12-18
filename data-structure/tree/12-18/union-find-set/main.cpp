#include <stdio.h>

#define MaxSize 10

typedef struct UFSNode {
	int data;
	int rank;
	int parent;
};

void makeSet(UFSNode t[], int n) { //创建并查集，从数组下标为 0 开始，t 是一个由结构体组成的数组
	for (int i = 1; i <= n; i++)
	{
		t[i].data = i; //每个结点的值就是它自己的值

		t[i].rank = 0; //每个结点的秩默认为 -1，此时无论有多少个结点，该集合都是一个分离的森林，即一个结点就是一棵树

		t[i].parent = i; //每个结点的双亲结点的下标就是它自己
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
