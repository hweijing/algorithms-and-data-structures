#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqStack {
	ElemType data[MaxSize];
	int top; //ջ��Ԫ���� data �����е��±꣬û��Ԫ��ʱĬ��Ϊ -1
}SqStack;

//��ʼ��˳��ջ
void initStack(SqStack*& S) {
	S = (SqStack*)malloc(sizeof(SqStack));

	S->top = -1;
}

//����˳��ջ
void destoryStack(SqStack*& S) {
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

	S->data[S->top] = e;

	S->top++;

	return true;
}

int main() {
	return 0;
}