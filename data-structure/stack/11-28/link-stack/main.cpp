#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkStackNode {
	ElemType data;
	struct LinkStackNode* next;
}LinkStackNode;

void initLinkStack(LinkStackNode*& S) {
	S = (LinkStackNode*)malloc(sizeof(LinkStackNode));

	S->next = NULL;
}

void destoryLinkStack(LinkStackNode*& S) {
	LinkStackNode* pre = S, * p = S->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

bool isEmptyLinkStack(LinkStackNode* S) {
	return S->next == NULL;
}

void pushLinkStack(LinkStackNode*& S, ElemType e) {
	LinkStackNode* p;

	p = (LinkStackNode*)malloc(sizeof(LinkStackNode));

	p->data = e;

	p->next = S->next;

	S->next = p;
}

bool popLinkStack(LinkStackNode*& S, ElemType& e) {
	if (S->next == NULL)
	{
		return false;
	}

	LinkStackNode* p = S->next;

	e = p->data;

	S->next = p->next;

	free(p);

	return true;
}

bool getTopLinkStack(LinkStackNode* S, ElemType& e) {
	if (S->next == NULL)
	{
		return false;
	}

	e = S->next->data;

	return true;
}

int main() {
	return 0;
}