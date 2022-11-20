#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqList {
	ElemType data[MaxSize];
	int length;
}SqList;

void createSqList(SqList*& L, ElemType a[], int n) {
	L = (SqList*)malloc(sizeof(SqList));

	int k = 0;


	for (int i = 0; i < n; i++)
	{
		L->data[k] = a[i];
		k++;
	}

	L->length = k;
}

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

void dispSqList(SqList* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->data[i]);
	}
}

bool getElemSqList(SqList* L, int i, ElemType& e) {
	if (i < 1 || L->length == 0)
	{
		return false;
	}

	e = L->data[i - 1];

	return true;
}

int getLocateSqList(SqList* L, ElemType e) {
	for (int i = 0; i < L->length; i++)
	{
		if (e == L->data[i])
		{
			return i + 1;
		}
	}

	return 0;
}

bool insertSqList(SqList*& L, int i, ElemType e) {
	if (i < 1 || i > L->length + 1 || L->length == MaxSize)
	{
		return false;
	}

	for (int j = L->length - 1; j >= i - 1; j--)
	{
		L->data[j + 1] = L->data[j];
	}

	L->data[i - 1] = e;

	L->length++;

	return true;
}

bool deleteSqlist(SqList*& L, int i, ElemType& e) {
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

	createSqList(L, a, 3);

	ElemType e;

	getElemSqList(L, 4, e);

	getLocateSqList(L, 3);

	insertSqList(L, 4, 4);

	insertSqList(L, 1, 0);

	deleteSqlist(L, 5, e);

	dispSqList(L);

	return 0;
}