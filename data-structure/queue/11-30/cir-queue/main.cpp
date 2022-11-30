#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef int ElemType;

/*
	环形队与顺序队的区别：
		1	顺序队和环形队的 front 都表示队头元素的前一个元素在 data 中的下标
		2	顺序队初始化时 front 为 -1，此时 data[-1] 不代表任何值，且 -1 不是永远不会是数组中某个元素的下标，第一次进队时，队头元素的下标为 0；
			环形队初始化时 front 为 0，此时 data[0] 没有任何值，但 0 表示数组中第一个元素的下标，第一次进队时，队头元素的下标为 1
		3	因为 front 表示队头元素的前一个元素在 data 中的下标，即 data[front] 永远不会表示数组中某个元素的值，
			所以当环形队队满时，data 中元素的个数等于 MaxSize - 1，而当顺序队队满时，data 中的元素的个数等于 MaxSize
		4	顺序队和环形队最重要的区别是队满的判断：
			顺序队中队满和队空的判断条件有重合，所以造成队中的每块内存都是一次性的，当全部入队后又全部出队，此时会出现“假溢出”的现象；
			环形队比顺序队更严谨，环形队中队满的判断条件与队空的判断条件不会重合，
			q->front == q->rear 表示队空，与顺序队的队空条件一样，(q->rear + 1)%MaxSize == q->front 表示队满，与顺序队的队满条件不一样
*/

/*
	顺序栈、顺序队和环形队在不为空时的区别：
		顺序栈中栈顶元素的下标 top 永远 >= data 中第一个元素的下标，即 top 永远 >= 0
		顺序队中队尾元素的下标 rear 永远 > 队头元素的前一个元素的下标 front，即 rear 永远 > front
		环形队中队尾元素的下标 rear 不一定 > 队头元素的前一个元素的下标 front，也可能 < front
*/

typedef struct CirQueue {
	ElemType data[MaxSize];
	int front;
	int rear;
}CirQueue;

//初始化环形队
void initCirQueue(CirQueue*& Q) {
	Q = (CirQueue*)malloc(sizeof(CirQueue));

	Q->front = Q->rear = 0;
}

//销毁环形队
void destoryCirQueue(CirQueue*& Q) {
	free(Q);
}

//判空环形队
bool isEmptyCirQueue(CirQueue* Q) {
	return Q->front == Q->rear;
}

//进队
bool enCirQueue(CirQueue*& Q, ElemType e) {
	/*
		最后一个元素的下标 + 1 后再对 MaxSize 取余，若等于队头元素的前一个元素的下标，则证明队满
		例 MaxSize = 5，当队满时最后一个元素的下标为 4，(4 + 1) % 5 = 0，0 为队头元素的前一个元素的下标

	*/
	if ((Q->rear + 1) % MaxSize == Q->front) //
	{
		return false;
	}

	Q->rear = (Q->rear + 1) % MaxSize;

	Q->data[Q->rear] = e;

	return true;
}

//出队
bool deCirQueue(CirQueue*& Q, ElemType& e) {
	if (Q->front == Q->rear)
	{
		return false;
	}

	Q->front = (Q->front + 1) % MaxSize;

	e = Q->data[Q->front];

	return true;
}

void dispCirQueue(CirQueue *Q) {
	for (int i = Q->front + 1; i < Q->front + MaxSize; i++)
	{
		printf("%d\n", Q->data[i % MaxSize]);
	}

	printf("===================\n");
}

int main() {
	ElemType a[] = { 1,2,3,4 };

	ElemType b[] = { 5,6 };

	CirQueue* Q;

	initCirQueue(Q);

	//1 2 3 4
	for (int i = 0; i < 4; i++)
	{
		enCirQueue(Q, a[i]);
	}

	//1 2 3 4
	dispCirQueue(Q);

	ElemType e;

	//3 4
	for (int j = 0; j < 2; j++)
	{
		deCirQueue(Q, e);
	}

	//3 4
	dispCirQueue(Q);

	//3 4 5 6
	for (int k = 0; k < 2; k++)
	{
		enCirQueue(Q, b[k]);
	}

	//3 4 5 6
	dispCirQueue(Q);

	return 0;
}