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
	if (i < 1 || i > L->length)
	{
		return false;
	}

	e = L->data[i - 1];

	return true;
}

int getLocateSqList(SqList* L, ElemType e) {
	for (int j = 0; j < L->length; j++)
	{
		if (e == L->data[j])
		{
			return j + 1;
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

bool deleteSqList(SqList*& L, int i, ElemType& e) {
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
	ElemType a[] = { 3,1,2,3 };

	SqList* L;

	createSqList(L, a, 4);

	//¥Ú”°1 2 3
	dispSqList(L);

	ElemType e1;

	//e1 = 2
	getElemSqList(L, 3, e1);

	//i1 = 1
	int i1 = getLocateSqList(L, 3);

	//L = 3 1 2 4 3
	insertSqList(L, 4, 4);

	ElemType e2;

	//e2 = 3£¨L = 1 2 4 3
	deleteSqList(L, 1, e2);

	return 0;
}