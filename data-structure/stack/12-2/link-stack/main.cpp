#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

void initLinkStack(LinkNode*& S) {
	S = (LinkNode*)malloc(sizeof(LinkNode));

	S->next = NULL;
}

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

bool isEmptyLinkStack(LinkNode* S) {
	return S->next == NULL;
}

void pushLinkStack(LinkNode*& S, ElemType e) {
	LinkNode* p;

	p = (LinkNode*)malloc(sizeof(LinkNode));

	p->data = e;

	p->next = S->next;

	S->next = p;
}

bool popLinkStack(LinkNode*& S, ElemType& e) {
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

bool getTopLinkStack(LinkNode* S, ElemType& e) {
	if (S->next == NULL)
	{
		return true;
	}


	e = S->next->data;

	return true;
}

int main() {
	return 0;
}