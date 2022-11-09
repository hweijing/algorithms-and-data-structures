#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

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
		free(pre);
		pre = p;
		p = pre->next;
	}

	free(pre);
}

//判断单链表是否为空表
bool isEmptyLinkList(LinkNode* L) {
	return L->next == NULL;
}

//求单链表的长度
int lengthLinkList(LinkNode* L) {
	int n = 0;

	LinkNode* p = L;

	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}

	return n;
}

//输出单链表
void dispLinkList(LinkNode* L) {
	LinkNode* p = L->next;

	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

//求单链表中某个数据元素值
bool getElemLinkList(LinkNode* L, int i, ElemType& e) { //输入结点的位序
	if (i < 1)
	{
		return false;
	}

	int j = 0; //记录 p 指针移动的次数，若求第 n 个结点的值，则 p 指针从头结点开始移动，一共需要移动 n 次

	LinkNode* p = L;

	while (j < i && p != NULL)
	{
		p = p->next; //当 i 超过结点的个数时，会使 p 指针在最后一次循环时指向一个不存在的结点，此时 p = NULL，j 依然记录了一次指针移动，但是会在下面的 if 判断语句中返回 false
		j++;
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

	LinkNode* s, * r = L;

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
	ElemType a[] = { 1,4,7 };

	LinkNode* L;

	//createLinkListF(L, a, 3);

	createLinkListR(L, a, 3);

	lengthLinkList(L);

	dispLinkList(L);

	ElemType data;

	getElemLinkList(L, 5, data);

	return 0;
}