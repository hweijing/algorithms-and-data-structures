#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

typedef struct LinkQueueFNode {
	struct LinkNode* front;
	struct LinkNode* rear;
};

void initLinkQueue(LinkQueueFNode*& Q) {
	Q = (LinkQueueFNode*)malloc(sizeof(LinkQueueFNode));

	Q->front = Q->rear = NULL;
}

void destoryLinkQueue(LinkQueueFNode*& Q) {
	LinkNode* pre = Q->front, * p;

	if (pre != NULL)
	{
		p = pre->next;

		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}

		free(pre);
	}

	free(Q);
}

bool isEmptyLinkQueue(LinkQueueFNode* Q) {
	return Q->rear = NULL;
}

void enLinkQueue(LinkQueueFNode*& Q, ElemType e) {
	LinkNode* s;

	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->data = e;

	s->next = NULL;

	if (Q->rear = NULL)
	{
		Q->front = Q->rear = s;
	}
	else
	{
		Q->rear->next = s;
		Q->rear = s;
	}
}

bool deLinkQueue(LinkQueueFNode*& Q, ElemType& e) {
	if (Q->rear == NULL)
	{
		return false;
	}

	LinkNode* p = Q->front;

	e = p->data;

	if (Q->front == Q->rear)
	{
		Q->front = Q->rear = NULL;
	}
	else
	{
		Q->front = Q->front->next;
	}

	free(p);

	return true;
}

int main() {
	return 0;
}