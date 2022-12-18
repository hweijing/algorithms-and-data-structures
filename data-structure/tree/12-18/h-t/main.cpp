#include <stdio.h>

typedef struct HTNode {
	char data;
	double weight;
	int parent;
	int lchild;
	int rchild;
};

void createHTree(HTNode ht[], int n0) {
	int i, k, lnode, rnode; //lnode �� rnode �ֱ��¼��СȨ�ص���������λ��

	double min1, min2; //����Ȩ��

	for ( i = 0; i < 2*n0 - 1; i++) //���� ht ���飬
	{
		ht[i].lchild = ht[i].rchild = ht->parent = -1;
	}

	for ( i = n0; i <= 2*n0 - 2; i++)
	{
		min1 = min2 = 32767;

		lnode = rnode = -1;

		for ( k = 0; k <= i - 1; k++)
		{
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)
				{
					min2 = min1;

					rnode = lnode;

					min1 = ht[k].weight;

					lnode = k;
				}
				else
				{
					min2 = ht[k].weight;

					rnode = k;
				}
			}
		}

		ht[i].weight = ht[lnode].weight + ht[rnode].weight;

		ht[i].lchild = lnode;

		ht[i].rchild = rnode;

		ht[lnode].parent = i;

		ht[rnode].parent = i;
	}
}

int main() {
	return 0;
}