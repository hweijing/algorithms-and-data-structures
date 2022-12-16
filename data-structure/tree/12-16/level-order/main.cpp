#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
};

typedef struct CirQueue {
	struct BTNode* data[MaxSize];
	int front;
	int rear;
};

void initCirQueue(CirQueue*& q) {
	q = (CirQueue*)malloc(sizeof(CirQueue));

	q->front = q->rear = 0;
}

void destoryCirQueue(CirQueue*& q) {
	free(q);
}

bool isEmptyCirQueue(CirQueue* q) {
	return q->front == q->rear;
}

bool enCirQueue(CirQueue*& q, BTNode* e) {
	if ((q->rear + 1) % MaxSize == q->front)
	{
		return false;
	}

	q->rear = (q->rear + 1) % MaxSize;

	q->data[q->rear] = e;

	return true;
}

bool deCirQueue(CirQueue*& q, BTNode*& e) {
	if (q->front == q->rear)
	{
		return false;
	}

	q->front = (q->front + 1) % MaxSize;

	e = q->data[q->front];

	return true;
}

void levelOrder(BTNode* b) {
	CirQueue* q;

	BTNode* p;

	initCirQueue(q);

	enCirQueue(q, b);

	while (!isEmptyCirQueue(q))
	{
		deCirQueue(q, p);

		printf("%c", p->data);

		if (p->lchild != NULL)
		{
			enCirQueue(q, p->lchild);
		}

		if (p->rchild != NULL)
		{
			enCirQueue(q, p->rchild);
		}
	}

	destoryCirQueue(q);
}

int main() {
	return 0;
}
