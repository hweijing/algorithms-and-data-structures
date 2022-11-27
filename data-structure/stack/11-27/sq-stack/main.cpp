#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef int ElemType;

typedef struct SqStack {
	ElemType data[MaxSize];
	int top;
}SqStack;

//��ʼ��˳��ջ
void initSqStack(SqStack*& S) {
	S = (SqStack*)malloc(sizeof(SqStack));

	S->top = -1;
}

//����ջ
void destroySqStack(SqStack*& S) {
	free(S);
}

//�п�˳��ջ
bool isEmptySqStack(SqStack* S) {
	return S->top == -1;
}

//��ջ
bool pushSqStack(SqStack*& S, ElemType e) {
	if (S->top == MaxSize - 1)
	{
		return false;
	}

	S->top++;

	S->data[S->top] = e;

	return true;
}

//��ջ
bool popSqStack(SqStack*& S, ElemType& e) {
	if (S->top == -1)
	{
		return false;
	}

	e = S->data[S->top];

	S->top--;

	return true;
}

//ȡջ��Ԫ��
bool getTopSqStack(SqStack* S, ElemType& e) {
	if (S->top == -1)
	{
		return false;
	}

	e = S->data[S->top];

	return true;
}

int main() {
	return 0;
}