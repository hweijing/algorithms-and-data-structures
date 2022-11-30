#include <stdio.h>
#include <malloc.h>

#define MaxSize 3

typedef int ElemType;

/*
	˳��ջ��˳��ӵ�����
	˳��ջ�е�ÿ���ڴ�����ظ�ʹ�ã��Ƚ�ջ�ٳ�ջ�ٽ�ջʱ����һ���͵ڶ�����ջ��Ԫ��ռ�õ���ͬһ���ڴ棻
	˳����е�ÿ���ڴ���һ���Եģ����糤��Ϊ 3 ��˳��ӣ�������ʱ��ʼ���ӣ�ȫ�����ö��е�����洢���ǿնӣ����߼��洢���Ƕ�������ʱ�����ٽ���
*/

typedef struct SqQueue {
	ElemType data[MaxSize];
	int front; //��ʾ��ͷԪ�ص�ǰһ��Ԫ���� data �е��±�
	int rear; //��ʾ��βԪ���� data �е��±�
};

//��ʼ��˳���
void initSqQueue(SqQueue*& Q) {
	Q = (SqQueue*)malloc(sizeof(SqQueue));

	Q->front = Q->rear = -1;
}

//����˳���
void destorySqQueue(SqQueue*& Q) {
	free(Q);
}

//�п�˳���
bool isEmptySqQueue(SqQueue* Q) {
	return Q->front == Q->rear;
}

//����
bool enQueue(SqQueue*& Q, ElemType e) {
	if (Q->rear == MaxSize - 1) //�������ж�����
	{
		return false;
	}

	Q->rear++;

	Q->data[Q->rear] = e;

	return true;
}

//����
bool deQueue(SqQueue*& Q, ElemType& e) {
	if (Q->front == Q->rear) //�ӿյ��ж���������ö�ռ�õ������ڴ涼����Ⱦ�������е��ڴ涼��һ���Եģ�
	{
		return false;
	}

	Q->front++; //�� front ��ʾ����Ԫ���� data �е��±꣬ͬʱҲ��ʾ�µĶ�ͷԪ�ص�ǰһ��Ԫ���� data �е��±�

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

	//��ʱ��Ȼ�ö���Ϊ�գ����ö��е��ڴ��Ѿ�ȫ�����꣬�����е��ڴ���һ���Եģ������ٽ���
	enQueue(Q, 4);

	return 0;
}