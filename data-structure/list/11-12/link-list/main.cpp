#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
} LinkNode;

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

bool isEmptyLinkLisk(LinkNode* L) {
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

	while (p != NULL && j < i) //跳出循环的条件是 p 指向了空结点或 p 指向了第 i 个结点
	{
		p = p->next;
		j++;
	}

	if (p == NULL) //当 p 指向空结点时，表示输入的位序大于链表的长度，此时返回 false
	{
		return false;
	}

	e = p->data;

	return true;
}

int getLocateLinkList(LinkNode* L, ElemType e) {
	int i = 1;

	LinkNode* p = L->next;

	while (p != NULL) //当 p 指向空结点时，表示链表中没有与 e 相同的元素，此时返回 0
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

int main() {
	ElemType a[] = { 2,1,4,3,3,5 };

	LinkNode* L;

	createLinkListR(L, a, 6);

	//i = 4
	int i = getLocateLinkList(L, 3);

	return 0;
}