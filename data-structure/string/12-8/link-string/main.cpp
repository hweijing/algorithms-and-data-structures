#include <stdio.h>
#include <malloc.h>

typedef struct LinkNode {
	char data;
	struct LinkNode* next;
};

void createLinkString(LinkNode*& s, char str[]) {
	s = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* p, * r;

	r = s;

	for (int i = 0; str[i] != '\0'; i++)
	{
		p = (LinkNode*)malloc(sizeof(LinkNode));
		p->data = str[i];
		r->next = p;
		r = p;
	}

	r->next = NULL;

}

void destoryLinkString(LinkNode*& s) {
	LinkNode* pre = s, * p = s->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

int lengthLinkString(LinkNode* s) {
	LinkNode* p = s->next;

	int i = 0;

	while (p != NULL)
	{
		i++;
		p = p->next;
	}

	return i;
}

void dispLinkString(LinkNode* s) {
	LinkNode* p = s->next;

	while (p != NULL)
	{
		printf("%c\n", p->data);
		p = p->next;
	}
}

void copyLinkString(LinkNode*& s, LinkNode* t) {
	s = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* p = t->next, * q, * r;

	r = s;

	while (p != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;
}

int main() {
	return 0;
}