#include <stdio.h>
#include <malloc.h>

#define MaxSize 5

typedef int ElemType;

/*
	���ζ���˳��ӵ�����
		1	˳��Ӻͻ��ζӵ� front ����ʾ��ͷԪ�ص�ǰһ��Ԫ���� data �е��±�
		2	˳��ӳ�ʼ��ʱ front Ϊ -1����ʱ data[-1] �������κ�ֵ���� -1 ������Զ������������ĳ��Ԫ�ص��±꣬��һ�ν���ʱ����ͷԪ�ص��±�Ϊ 0��
			���ζӳ�ʼ��ʱ front Ϊ 0����ʱ data[0] û���κ�ֵ���� 0 ��ʾ�����е�һ��Ԫ�ص��±꣬��һ�ν���ʱ����ͷԪ�ص��±�Ϊ 1
		3	��Ϊ front ��ʾ��ͷԪ�ص�ǰһ��Ԫ���� data �е��±꣬�� data[front] ��Զ�����ʾ������ĳ��Ԫ�ص�ֵ��
			���Ե����ζӶ���ʱ��data ��Ԫ�صĸ������� MaxSize - 1������˳��Ӷ���ʱ��data �е�Ԫ�صĸ������� MaxSize
		4	˳��Ӻͻ��ζ�����Ҫ�������Ƕ������жϣ�
			˳����ж����Ͷӿյ��ж��������غϣ�������ɶ��е�ÿ���ڴ涼��һ���Եģ���ȫ����Ӻ���ȫ�����ӣ���ʱ����֡��������������
			���ζӱ�˳��Ӹ��Ͻ������ζ��ж������ж�������ӿյ��ж����������غϣ�
			q->front == q->rear ��ʾ�ӿգ���˳��ӵĶӿ�����һ����(q->rear + 1)%MaxSize == q->front ��ʾ��������˳��ӵĶ���������һ��
*/

/*
	˳��ջ��˳��Ӻͻ��ζ��ڲ�Ϊ��ʱ������
		˳��ջ��ջ��Ԫ�ص��±� top ��Զ >= data �е�һ��Ԫ�ص��±꣬�� top ��Զ >= 0
		˳����ж�βԪ�ص��±� rear ��Զ > ��ͷԪ�ص�ǰһ��Ԫ�ص��±� front���� rear ��Զ > front
		���ζ��ж�βԪ�ص��±� rear ��һ�� > ��ͷԪ�ص�ǰһ��Ԫ�ص��±� front��Ҳ���� < front
*/

typedef struct CirQueue {
	ElemType data[MaxSize];
	int front;
	int rear;
}CirQueue;

//��ʼ�����ζ�
void initCirQueue(CirQueue*& Q) {
	Q = (CirQueue*)malloc(sizeof(CirQueue));

	Q->front = Q->rear = 0;
}

//���ٻ��ζ�
void destoryCirQueue(CirQueue*& Q) {
	free(Q);
}

//�пջ��ζ�
bool isEmptyCirQueue(CirQueue* Q) {
	return Q->front == Q->rear;
}

//����
bool enCirQueue(CirQueue*& Q, ElemType e) {
	/*
		���һ��Ԫ�ص��±� + 1 ���ٶ� MaxSize ȡ�࣬�����ڶ�ͷԪ�ص�ǰһ��Ԫ�ص��±꣬��֤������
		�� MaxSize = 5��������ʱ���һ��Ԫ�ص��±�Ϊ 4��(4 + 1) % 5 = 0��0 Ϊ��ͷԪ�ص�ǰһ��Ԫ�ص��±�

	*/
	if ((Q->rear + 1) % MaxSize == Q->front) //
	{
		return false;
	}

	Q->rear = (Q->rear + 1) % MaxSize;

	Q->data[Q->rear] = e;

	return true;
}

//����
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