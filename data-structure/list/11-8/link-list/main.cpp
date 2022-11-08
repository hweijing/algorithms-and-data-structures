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

//销毁单链表
void destroyLinkList(LinkNode*& L) {
	LinkNode* pre = L, * p = L->next;

	while (p != NULL)
	{
		free(p);
		pre = p;
		p = p->next;
	}

	free(pre);
}

//判断单链表是否为空
bool isEmptyLinkLisk(LinkNode* L) {
	return L->next == NULL;
}

//求单链表的长度
int lengthLinkList(LinkNode* L) {
	LinkNode* p;

	p = L->next;

	int n = 0;

	while (p != NULL)
	{
		n++;
		p = p->next;
	}

	return n;
}

//输出单链表
void getLinkList(LinkNode* L) {
	LinkNode* p = L->next;

	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

//求单链表中的某个数据元素值
bool getElemLinkList(LinkNode* L, int i, ElemType& e) {
	if (i < 1)
	{
		return false;
	}

	LinkNode* p = L;

	int j = 0;

	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
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

int main() {
	ElemType a[] = { 3,2,1 };

	LinkNode* L;

	//createLinkListF(L, a, 3);

	createLinkListR(L, a, 3);

	int n = lengthLinkList(L);

	getLinkList(L);

	ElemType v;

	getElemLinkList(L, 3, v);

	return 0;
}