#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqList {
	ElemType data[MaxSize];
	int length;
}SqList;

void createSqList(SqList*& L, ElemType a[], int n) {
	int k = 0;

	L = (SqList*)malloc(sizeof(SqList));

	for (int i = 0; i < n; i++)
	{
		L->data[i] = a[i];
		k++;
	}

	L->length = k;
}

int main() {
	int a[] = { 1,2,3 };

	SqList* L;

	createSqList(L, a, 3);

	return 0;
}