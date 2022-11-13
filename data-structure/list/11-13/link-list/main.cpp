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

void initLinkList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;
}

void destroyLinkList(LinkNode*& L) {
	LinkNode* pre = L, * p = L->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

void dispLinkList(LinkNode* L) {
	LinkNode* p = L->next;

	while (p != NULL)
	{
		printf("%d\n", p->data);
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

	while (j < i && p != NULL)
	{
		p = p->next;
		j++;
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
		p = p->next;
		i++;
	}

	return 0;
}

bool insertLinkList(LinkNode*& L, int i, ElemType e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L, * s; //p ָ��Ҫ�������ǰһ�����

	int j = 0;

	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}


	if (p == NULL) //��Ҫ����Ľ���λ���������ĳ��� + 1 ʱ������ false
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

	LinkNode* p = L, * q; //p ָ��Ҫɾ������ǰһ����㣬q ָ��Ҫɾ���Ľ��

	int j = 0;

	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}

	if (p == NULL) //��Ҫɾ���Ľ���λ���������ĳ��� + 1 ʱ������ false 
	{
		return false;
	}

	q = p->next; //�� q ָ����Ҫɾ���Ľ��

	if (q == NULL) //����Ҫɾ����Ԫ�ص�λ���������ĳ���ʱ������ false
	{
		return false;
	}

	e = q->data; //���Ҫɾ������ֵ

	p->next = q->next;

	free(q);

	return true;
}

int main() {
	ElemType a[] = { 2,1,4,3,5 };

	LinkNode* L;

	return 0;
}