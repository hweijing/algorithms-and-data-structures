#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct DLinkNode {
	ElemType data;
	struct DLinkNode* prev;
	struct DLinkNode* next;
}DLinkNode;

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

	r = L;

	r->prev = NULL;

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

bool insertDLinkList(DLinkNode*& L, int i, ElemType e) {
	if (i < 1)
	{
		return false;
	}

	DLinkNode* p = L, * s;

	int j = 0;

	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (p == NULL)
	{
		return false;
	}

	s = (DLinkNode*)malloc(sizeof(DLinkNode));

	s->data = e;

	s->prev = p;

	s->next = p->next;

	if (p->next != NULL)
	{
		p->next->prev = s;
	}

	p->next = s;

	return true;
}

bool deleteDLinkList(DLinkNode*& L, int i, ElemType& e) {
	if (i < 1)
	{
		return false;
	}

	DLinkNode* p = L, * q;

	int j = 0;

	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (p == NULL)
	{
		return false;
	}

	q = p->next;

	if (q == NULL)
	{
		return false;
	}

	e = q->data;

	p->next = q->next;

	if (q->next != NULL)
	{
		q->next->prev = p;
	}

	free(q);

	return true;
}

int main() {
	return 0;
}