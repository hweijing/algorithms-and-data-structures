#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqList {
	ElemType data[MaxSize];
	int length;
};

//��ʼ��˳���
void initSqList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));

	L->length = 0;
}

//����˳���
void destroySqList(SqList*& L) {
	free(L);
}

//��ѯ˳����Ƿ�Ϊ��
bool isEmptySqList(SqList* L) {
	return L->length == 0;
}

//��ѯ˳���ĳ���
int lengthSqList(SqList* L) {
	return L->length;
}

//��ѯ˳����е�����Ԫ��
void getSqList(SqList* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->data[i]);
	}
}

//��ѯָ��λ���Ԫ��
bool getElemSqList(SqList* L, ElemType& e, int i) { //����λ�����Ԫ��
	if (i < 1 || i > L->length)
	{
		return false;
	}

	e = L->data[i - 1];

	return true;
}

//��ѯԪ����˳����е�һ�γ��ֵ�λ�����û�оͷ��� 0
int getLocateSqlist(SqList* L, ElemType e) { //����Ԫ�أ�����λ��
	for (int i = 0; i < L->length; i++)
	{
		if (e == L->data[i])
		{
			return i + 1;
		}
	}

	return 0;
}

//����Ԫ�ص�ָ��λ��
bool insertSqList(SqList*& L, ElemType e, int i) { //����Ԫ�غ�λ��
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

//ɾ��ָ��λ���Ԫ��
bool deleteSqList(SqList*& L, ElemType& e, int i) { //����Ԫ�غ�λ��
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

//����˳���
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