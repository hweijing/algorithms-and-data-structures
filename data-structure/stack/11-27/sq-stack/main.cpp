#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqStack {
	ElemType data[MaxSize];
	int top; //栈顶元素在 data 数组中的下标，没有元素时默认为 -1
}SqStack;

//初始化顺序栈
void initStack(SqStack*& S) {
	S = (SqStack*)malloc(sizeof(SqStack));

	S->top = -1;
}

//销毁顺序栈
void destoryStack(SqStack*& S) {
	free(S);
}

//判空顺序栈
bool isEmptySqStack(SqStack* S) {
	return S->top == -1;
}

//进栈
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