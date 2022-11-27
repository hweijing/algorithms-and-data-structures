#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//初始化链栈，与初始化单链表一样
void initLinkStack(LinkNode*& S) {
	S = (LinkNode*)malloc(sizeof(LinkNode));

	S->next = NULL;
}

//销毁链栈，与销毁单链表一样
void destoryLinkStack(LinkNode*& S) {
	LinkNode* pre = S, * p = S->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

//判空链栈，与判空单链表一样
bool isEmptyLinkStack(LinkNode* S) {
	return S->next == NULL;
}

//进栈
void pushLinkStack(LinkNode*& S, ElemType e) {
	LinkNode* p;

	p = (LinkNode*)malloc(sizeof(LinkNode));

	p->data = e;

	p->next = S->next;

	S->next = p;
}

//出栈
bool popLinkStack(LinkNode *&S, ElemType &e) {
	if (S->next == NULL)
	{
		return false;
	}

	LinkNode* p = S->next;

	e = p->data;

	S->next = p->next;

	free(p);

	return true;
}

//取栈顶元素
bool getTopLinkStack(LinkNode *S, ElemType &e) {
	if (S->next == NULL)
	{
		return false;
	}

	LinkNode* p = S->next;

	e = p->data;

	return true;
}

int main() {
	return 0;
}