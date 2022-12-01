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
	return Q->rear == NULL; //如果队列为空，则队头结点的 front 和 rear 都为 NULL，任何一个条件成立即可
}

void enLinkQueue(LinkQueueFNode*& Q, ElemType e) {
	LinkNode* s;

	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->data = e;

	s->next = NULL;

	/*
		若队列为空，则使队头结点的 front 和 next 都指向要进队的结点；
		若队列非空，队头结点的 front 和 rear 可能相同（在队中只有一个结点的情况下），也可能不同（在队中至少有两个结点的时候），则先改变原队中最后一个结点的 next，再改变队头结点的 rear
	*/
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

bool deLinkQueue(LinkQueueFNode*& Q, ElemType& e) {
	if (Q->rear == NULL)
	{
		return false;
	}

	LinkNode* p = Q->front;

	e = p->data;

	/*
		若队中只有一个结点时，即队头结点的 front = rear，则把 front 和 rear 置为 NULL;
		若队中至少有两个结点时，则把队头元素的 front 向后移动一次，即 front = front-> next
	*/
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