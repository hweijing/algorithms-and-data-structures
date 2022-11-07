#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//初始化单链表
void initLinkList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;
}

void destroyLinkList(LinkNode*& L) {
	LinkNode* pre = L, *p = L->next; //pre 是头指针，p 是首结点的外指针

	while (p != NULL) //当 p 为最后一个结点的内指针时，p 的值为 NULL，此时 pre 指向最后一个结点
	{
		free(pre); //第一轮循环时重置头指针，重置后 pre 不指向任何结点
		pre = p; //使 pre 指向 p 指向的结点
		p = pre->next; //让 p 指向后一结点
	}

	free(pre);
}

//头插法
void createLinkListF(LinkNode*& L, ElemType a[], int n) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;

	LinkNode* s;

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//尾插法
void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* r, * s;

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

int main() {
	ElemType a[] = { 1,2 };

	LinkNode* L;

	//createLinkListF(L, a, 2);

	createLinkListR(L, a, 2);

	LinkNode* s = L->next;

	destroyLinkList(L);

	return 0;
}