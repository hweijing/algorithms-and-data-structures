#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct DLinkNode {
	ElemType data;
	struct DLinkNode* prev;
	struct DLinkNode* next;
};

void createDLinkListF(DLinkNode*& L, ElemType a[], int n) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));

	DLinkNode* s;

	L->prev = L->next = NULL;

	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->prev = L;
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prev = s;
		}
		L->next = s;
	}
}

void createDLinkListR(DLinkNode*& L, ElemType a[], int n) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));

	DLinkNode* s, * r;

	L->prev = NULL;

	r = L;

	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->prev = r;
		r->next = s;
		r = s;
	}

	r->next = NULL;
}

int main() {
	ElemType a[] = { 1,2,3 };

	DLinkNode* L;

	createDLinkListR(L, a, 3);
	
	return 0;
}