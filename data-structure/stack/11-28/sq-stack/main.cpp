#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef int ElemType;

typedef struct SqStack {
	ElemType data[MaxSize];
	int top;
};

void initSqStack(SqStack*& S) {
	S = (SqStack*)malloc(sizeof(SqStack));

	S->top = -1;
}

void destorySqStack(SqStack*& S) {
	free(S);
}

bool isEmptySqStack(SqStack* S) {
	return S->top == -1;
}

bool pushSqStack(SqStack*& S, ElemType e) {
	if (S->top == MaxSize - 1)
	{
		return false;
	}

	S->top++;

	S->data[S->top] = e;

	return true;
}

bool popSqStack(SqStack*& S, ElemType& e) {
	if (S->top == -1)
	{
		return false;
	}

	e = S->data[S->top];

	S->top--;

	return true;
}

bool getTopSqStack(SqStack* S, ElemType& e) {
	if (S->top == -1)
	{
		return false;
	}

	e = S->data[S->top];

	return true;
}

int main() {
	ElemType a[] = { 1,2,3 };

	SqStack* S;

	initSqStack(S);

	for (int i = 0; i < 3; i++)
	{
		pushSqStack(S, a[i]);
	}

	ElemType e;

	popSqStack(S, e);

	return 0;
}