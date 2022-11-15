#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct DLinkNode {
	ElemType data;
	struct DLinkNode* prev;
	struct DLinkNode* next;
}DLinkNode;

//头插法
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
		if (L->next != NULL) //第一次循环时，因为没有首节点，所以不会进 if
		{
			L->next->prev = s;  //除了第一次循环，每次循环创建新结点时都要把新创建结点的指针赋给上一结点的前指针，达到每次创建的新结点都排在上一结点之前
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