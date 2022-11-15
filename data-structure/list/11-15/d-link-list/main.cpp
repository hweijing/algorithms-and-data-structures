#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct DLinkNode {
	ElemType data;
	struct DLinkNode* prev;
	struct DLinkNode* next;
}DLinkNode;

//ͷ�巨
void createDLinkList(DLinkNode*& L, ElemType a[], int n) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));

	DLinkNode* s;

	L->prev = L->next = NULL;

	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		s->prev = L;
		if (L->next != NULL) //��һ��ѭ��ʱ����Ϊû���׽ڵ㣬���Բ���� if
		{
			L->next->prev = s;  //���˵�һ��ѭ����ÿ��ѭ�������½��ʱ��Ҫ���´�������ָ�븳����һ����ǰָ�룬�ﵽÿ�δ������½�㶼������һ���֮ǰ
		}
		L->next = s;
	}
}

int main() {
	ElemType a[] = { 1,2,3 };

	DLinkNode* L;

	createDLinkList(L, a, 3);

	return 0;
}