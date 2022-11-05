#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqList {
	ElemType data[MaxSize];
	int length;
}SqList;

void initSqList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));

	L->length = 0;
}

void destroySqList(SqList*& L) {
	free(L);
}

bool isEmptySqList(SqList* L) {
	return L->length == 0;
}

int lengthSqList(SqList* L) {
	return L->length;
}

void getSqList(SqList* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->data[i]);
	};

	printf("-------------------------------\n");
}

void createSqList(SqList*& L, ElemType a[], int n) {
	int i = 0, k = 0;

	L = (SqList*)malloc(sizeof(SqList));

	while (i < n)
	{
		L->data[k] = a[i];
		i++;
		k++;
	}

	L->length = k;
}

int getSqListLocate(SqList* L, ElemType e) { //返回位序
	for (int i = 0; i < L->length; i++)
	{
		if (e == L->data[i])
		{
			return i + 1;
		}
	}

	return 0;
}

bool insertSqList(SqList*& L, int i, ElemType e) { //输入位序
	if (i < 1 || i > L->length + 1 || L->length == MaxSize)
	{
		return false;
	}

	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}

	L->data[i - 1] = e;

	L->length++;

	return true;
}

bool deleteSqList(SqList*& L, int i, ElemType& e) { //输入位序
	if (i < 1 || i > L->length)
	{
		return false;
	}

	e = L->data[i - 1];

	for (int j = i; j < L->length; j++)
	{
		L->data[j - 1] = L->data[j];
	}

	L->length--;

	return true;
}

int main() {
	ElemType a[] = { 1,2,3 };

	SqList* L;

	ElemType b;

	createSqList(L, a, 3);

	//3
	//printf("%d", getSqListLocate(L, 3));

	insertSqList(L, 4, 4);

	//1 2 3 4
	getSqList(L);

	deleteSqList(L, 2, b);

	//1 3 4
	getSqList(L);

	//3
	printf("%d\n", lengthSqList(L));

	printf("-------------------------------\n");

	//false
	printf(isEmptySqList(L) ? "true" : "false");

	return 0;
}

