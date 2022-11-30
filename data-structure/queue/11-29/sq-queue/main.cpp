#include <stdio.h>
#include <malloc.h>

#define MaxSize 3

typedef int ElemType;

/*
	顺序栈和顺序队的区别：
	顺序栈中的每块内存可以重复使用，先进栈再出栈再进栈时，第一个和第二个进栈的元素占用的是同一块内存；
	顺序队中的每块内存是一次性的，例如长度为 3 的顺序队，当队满时开始出队，全出完后该队列的物理存储上是空队，但逻辑存储上是队满，此时不能再进队
*/

typedef struct SqQueue {
	ElemType data[MaxSize];
	int front; //表示队头元素的前一个元素在 data 中的下标
	int rear; //表示队尾元素在 data 中的下标
};

//初始化顺序队
void initSqQueue(SqQueue*& Q) {
	Q = (SqQueue*)malloc(sizeof(SqQueue));

	Q->front = Q->rear = -1;
}

//销毁顺序队
void destorySqQueue(SqQueue*& Q) {
	free(Q);
}

//判空顺序队
bool isEmptySqQueue(SqQueue* Q) {
	return Q->front == Q->rear;
}

//进队
bool enQueue(SqQueue*& Q, ElemType e) {
	if (Q->rear == MaxSize - 1) //队满的判断条件
	{
		return false;
	}

	Q->rear++;

	Q->data[Q->rear] = e;

	return true;
}

//出队
bool deQueue(SqQueue*& Q, ElemType& e) {
	if (Q->front == Q->rear) //队空的判断条件，或该队占用的所有内存都被污染过（队中的内存都是一次性的）
	{
		return false;
	}

	Q->front++; //让 front 表示出队元素在 data 中的下标，同时也表示新的队头元素的前一个元素在 data 中的下标

	e = Q->data[Q->front];

	return true;
}

int main() {
	ElemType a[] = { 3,2,1 };

	SqQueue* Q;

	initSqQueue(Q);

	for (int i = 0; i < 3; i++)
	{
		enQueue(Q, a[i]);
	}

	ElemType e;

	for (int j = 0; j < 3; j++)
	{
		deQueue(Q, e);
	}

	//此时虽然该队列为空，但该队列的内存已经全部用完，队列中的内存是一次性的，不能再进队
	enQueue(Q, 4);

	return 0;
}