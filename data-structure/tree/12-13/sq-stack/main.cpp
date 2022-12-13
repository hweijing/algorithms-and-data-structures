#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef int ElemType;

typedef struct SqStack {
	ElemType data[MaxSize];
	int top;
};

void initSqStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));

	s->top = -1;
}

void destorySqStack(SqStack*& s) {
	free(s);
}

bool isEmptySqStack(SqStack* s) {
	return s->top == -1;
}

bool pushSqStack(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)
	{
		return false;
	}

	s->top++;

	s->data[s->top] = e;

	return true;
}

bool popSqStack(SqStack*& s, ElemType& e) {
	if (s->top == -1)
	{
		return false;
	}

	e = s->data[s->top];

	s->top--;

	return true;
}

bool getTop(SqStack* s, ElemType& e) {
	if (s->top == -1)
	{
		return false;
	}

	e = s->data[s->top];

	return true;
}

int main() {
	return 0;
}