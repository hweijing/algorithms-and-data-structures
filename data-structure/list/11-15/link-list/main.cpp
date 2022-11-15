#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

void createLinkListF(LinkNode*& L, ElemType a[], int n) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* s;

	L->next = NULL;

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* s, * r;

	r = L;

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}

	r->next = NULL;
}

bool insertLinkList(LinkNode*& L, int i, ElemType e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L, * s;

	int j = 0;

	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}

	if (p == NULL)
	{
		return false;
	}

	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->data = e;

	s->next = p->next;

	p->next = s;

	return true;
}

bool deleteLinkList(LinkNode*& L, int i, ElemType& e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L, * q;

	int j = 0;

	while (j < i - 1 && p != NULL)
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

	free(q);

	return true;
}

int main() {
	ElemType a[] = { 1,7,4 };

	LinkNode* L;

	createLinkListR(L, a, 3);

	insertLinkList(L, 3, 2);

	ElemType data;

	deleteLinkList(L, 1, data);

	return 0;
}