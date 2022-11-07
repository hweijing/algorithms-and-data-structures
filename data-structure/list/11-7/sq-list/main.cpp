#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqList {
	ElemType data[MaxSize];
	int length;
};

//初始化顺序表
void initSqList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));

	L->length = 0;
}

//销毁顺序表
void destroySqList(SqList*& L) {
	free(L);
}

//查询顺序表是否为空
bool isEmptySqList(SqList* L) {
	return L->length == 0;
}

//查询顺序表的长度
int lengthSqList(SqList* L) {
	return L->length;
}

//查询顺序表中的所有元素
void getSqList(SqList* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->data[i]);
	}
}

//查询指定位序的元素
bool getElemSqList(SqList* L, ElemType& e, int i) { //输入位序，输出元素
	if (i < 1 || i > L->length)
	{
		return false;
	}

	e = L->data[i - 1];

	return true;
}

//查询元素在顺序表中第一次出现的位序，如果没有就返回 0
int getLocateSqlist(SqList* L, ElemType e) { //输入元素，返回位序
	for (int i = 0; i < L->length; i++)
	{
		if (e == L->data[i])
		{
			return i + 1;
		}
	}

	return 0;
}

//插入元素到指定位序
bool insertSqList(SqList*& L, ElemType e, int i) { //输入元素和位序
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

//删除指定位序的元素
bool deleteSqList(SqList*& L, ElemType& e, int i) { //输入元素和位序
	if (i < 1 || i > L->length)
	{
		return false;
	}

	e = L->data[i - 1];

	for (int j = i - 1; j < L->length; j++)
	{
		L->data[j] = L->data[j + 1];
	}

	L->length--;

	return true;
}

//创建顺序表
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
	ElemType a[] = { 3,2,1 };

	SqList* L;

	createSqList(L, a, 3);

	insertSqList(L, 4, 1);

	int s = getLocateSqlist(L, 6);

	ElemType e;

	deleteSqList(L, e, 4);

	return 0;
}