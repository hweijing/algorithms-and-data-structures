#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef int ElemType;

typedef struct SqQueue {
	ElemType data[MaxSize];
	int front;
	int rear;
};

void initSqQueue(SqQueue*& Q) {
	Q = (SqQueue*)malloc(sizeof(SqQueue));

	Q->front = Q->rear = -1;
}

void destorySqQueue(SqQueue*& Q) {
	free(Q);
}

bool isEmptySqQueue(SqQueue* Q) {
	return Q->front == Q->rear;
}

bool enSqQueue(SqQueue*& Q, ElemType e) {
	if (Q->rear == MaxSize - 1)
	{
		return false;
	}

	Q->rear++;

	Q->data[Q->rear] = e;

	return true;
}

bool deSqQueue(SqQueue*& Q, ElemType& e) {
	if (Q->front == Q->rear) {
		return false;
	}

	Q->front++;

	e = Q->data[Q->front];

	return true;
}

int main() {
	return 0;
}