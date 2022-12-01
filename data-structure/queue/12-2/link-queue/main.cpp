#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

typedef struct LinkQueueNode {
	struct LinkNode* front;
	struct LinkNode* rear;
};

void initLinkQueue(LinkQueueNode*& Q) {
	Q = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));

	Q->front = Q->rear = NULL;
}

void destoryLinkQueue(LinkQueueNode*& Q) {
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

bool isEmptyLinkQueue(LinkQueueNode* Q) {
	return Q->rear == NULL;
}

void enLinkQueue(LinkQueueNode*& Q, ElemType e) {
	LinkNode* s;

	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->data = e;

	s->next = NULL;

	if (Q->rear == NULL)
	{
		Q->front = Q->rear = s;
	}
	else
	{
		Q->rear->next = s;
		Q->rear = s;
	}
}

bool deLinkQueue(LinkQueueNode*& Q, ElemType& e) {
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