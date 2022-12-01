#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

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

void initLinkList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;
}

void destoryLinkList(LinkNode*& L) {
	LinkNode* pre = L, * p = L->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

bool isEmptyLinkList(LinkNode* L) {
	return L->next == NULL;
}

int lengthLinkList(LinkNode* L) {
	LinkNode* p = L->next;

	int i = 0;

	while (p != NULL)
	{
		i++;
		p = p->next;
	}

	return i;
}

void dispLinkList(LinkNode* L) {
	LinkNode* p = L->next;

	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}

bool getElemLinkList(LinkNode* L, int i, ElemType& e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L;

	int j = 0;

	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return false;
	}

	e = p->data;

	return true;
}

int getLocateLinkList(LinkNode* L, ElemType e) {
	LinkNode* p = L->next;

	int i = 1;

	while (p != NULL)
	{
		if (e == p->data)
		{
			return i;
		}

		i++;
		p = p->next;
	}

	return 0;
}

bool insertElemLinkList(LinkNode*& L, int i, ElemType e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L, * s;

	int j = 0;

	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
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

bool deleteElemLinkList(LinkNode*& L, int i, ElemType& e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L, * q;

	int j = 0;

	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return false;
	}

	q = p->next;

	if (q = NULL)
	{
		return false;
	}

	e = q->data;

	p->next = q->next;

	free(q);

	return true;
}

int main() {
	return 0;
}