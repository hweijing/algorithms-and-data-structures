#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

void initLinkStack(LinkNode*& s) {
	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->next = NULL;
}

void destroyLinkStack(LinkNode*& s) {
	LinkNode* pre = s, * p = s->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

bool isEmptyLinkStack(LinkNode* s) {
	return s->next == NULL;
}

void pushLinkStack(LinkNode*& s, ElemType e) {
	LinkNode* p;

	p = (LinkNode*)malloc(sizeof(LinkNode));

	p->data = e;

	p->next = s->next;

	s->next = p;
}

bool popLinkStack(LinkNode*& s, ElemType& e) {
	if (s->next == NULL)
	{
		return false;
	}

	LinkNode* p = s->next;

	e = p->data;

	s->next = p->next;

	free(p);

	return true;
}

bool getTopLinkStack(LinkNode* s, ElemType& e) {
	if (s->next == NULL)
	{
		return false;
	}

	LinkNode* p = s->next;

	e = p->data;

	return true;
}

int main() {
	return 0;
}