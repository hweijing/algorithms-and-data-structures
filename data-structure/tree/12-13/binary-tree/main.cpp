#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
};

typedef struct SqStack {
	struct BTNode* data[MaxSize];
	int top;
};

void initSqStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));

	s->top = -1;
};

void destorySqStack(SqStack*& s) {
	free(s);
}

bool pushSqStack(SqStack*& s, BTNode* e) {
	if (s->top == MaxSize - 1)
	{
		return false;
	}

	s->top++;

	s->data[s->top] = e;

	return true;
}

bool popSqStack(SqStack*& s) {
	if (s->top == -1)
	{
		return false;
	}

	s->top--;

	return true;
}

void createBTree(BTNode*& b, char str[]) {
	SqStack* s;

	BTNode* p = NULL;

	int k = 0, i = 0;

	char ch = str[i];

	b = NULL;

	initSqStack(s);

	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			k = 1;

			pushSqStack(s, p);

			break;
		case ')':
			popSqStack(s);

			break;
		case ',':
			k = 2;

			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));

			p->data = ch;

			p->lchild = p->rchild = NULL;

			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:
					s->data[s->top]->lchild = p;

					break;
				case 2:
					s->data[s->top]->rchild = p;

					break;
				}
			}
		}

		i++;

		ch = str[i];
	}

	destorySqStack(s);
}

int main() {
	char str[] = "A(B(D,E),C(F))";

	BTNode* b;

	createBTree(b, str);

	return 0;
}
