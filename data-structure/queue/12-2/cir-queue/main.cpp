#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef int ElemType;

typedef struct CirQueue {
	ElemType data[MaxSize];
	int front;
	int rear;
};

void initCirQueue(CirQueue*& Q) {
	Q = (CirQueue*)malloc(sizeof(CirQueue));

	Q->front = Q->rear = 0;
}

void destoryCirQueue(CirQueue*& Q) {
	free(Q);
}

bool isEmptyCirQueue(CirQueue* Q) {
	return Q->front == Q->rear;
}

bool enCirQueue(CirQueue*& Q, ElemType e) {
	if ((Q->rear + 1) % MaxSize == Q->front)
	{
		return false;
	}


	Q->rear = (Q->rear + 1) % MaxSize;

	Q->data[Q->rear] = e;

	return true;
}

bool deCirQueue(CirQueue*& Q, ElemType& e) {
	if (Q->front == Q->rear) {
		return false;
	}

	Q->front = (Q->front + 1) % MaxSize;

	e = Q->data[Q->front];

	return true;
}

int main() {
	return 0;
}