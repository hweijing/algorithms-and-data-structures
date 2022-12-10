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

void destroyLinkString(LinkNode*& s) {
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
		printf("%c", p->data);
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

bool equalLinkString(LinkNode* s, LinkNode* t) {
	LinkNode* p = s->next, * q = t->next;

	while (p != NULL && q != NULL && p->data == q->data)
	{
		p = p->next;
		q = q->next;
	}

	if (p == NULL && q == NULL)
	{
		return true;
	}

	return false;
}

LinkNode* concatLinkString(LinkNode* s, LinkNode* t) {
	LinkNode* str, * p, * q, * r;

	str = (LinkNode*)malloc(sizeof(LinkNode));

	r = str;

	p = s->next;

	while (p != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	p = t->next;

	while (p != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;

	return str;
}

LinkNode* subLinkString(LinkNode* s, int i, int j) {
	LinkNode* str, * p = s->next, * q, * r;

	str = (LinkNode*)malloc(sizeof(LinkNode));

	str->next = NULL;

	r = str;

	if (i < 1 || i > lengthLinkString(s) || j < 0 || i + j - 1 > lengthLinkString(s))
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; i++) //ÈÃ p Ìø i - 1 ´Î
	{
		p = p->next;
	}

	for (k = 0; k < j; k++)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;

	return str;
}

LinkNode* insLinkString(LinkNode* s, int i, LinkNode* t) {
	LinkNode* str, * p = s->next, * p1 = t->next, * q, * r;

	str = (LinkNode*)malloc(sizeof(LinkNode));

	str->next = NULL;

	r = str;

	if (i < 1 || i > lengthLinkString(s) + 1)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	while (p1 != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}

	while (p != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;

	return str;
}

LinkNode* delLinkString(LinkNode* s, int i, int j) {
	LinkNode* str, * p = s->next, * q, * r;

	str = (LinkNode*)malloc(sizeof(LinkNode));

	str->next = NULL;

	r = str;

	if (i < 1 || i > lengthLinkString(s) || j < 0 || i + j - 1 > lengthLinkString(s))
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	for (k = 0; k < j; k++)
	{
		p = p->next;
	}

	while (p != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;

	return str;
}

LinkNode* repLinkString(LinkNode* s, int i, int j, LinkNode* t) {
	LinkNode* str, * p = s->next, * p1 = t->next, * q, * r;

	str = (LinkNode*)malloc(sizeof(LinkNode));

	str->next = NULL;

	r = str;

	if (i < 1 || i > lengthLinkString(s) || j < 0 || i + j - 1 > lengthLinkString(s))
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	for (k = 0; k < j; k++)
	{
		p = p->next;
	}

	while (p1 != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}

	while (p != NULL)
	{
		q = (LinkNode*)malloc(sizeof(LinkNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;

	return str;
}

int main() {
	return 0;
}