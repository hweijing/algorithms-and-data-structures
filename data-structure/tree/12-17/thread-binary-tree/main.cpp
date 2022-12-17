#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef struct TBTNode {
	char data;
	struct TBTNode* lchild;
	struct TBTNode* rchild;
	int ltag;
	int rtag;
};

typedef struct SqStack {
	struct TBTNode* data[MaxSize];
	int top;
};

void initSqStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));

	s->top = -1;
}

void destorySqStack(SqStack*& s) {
	free(s);
}

bool pushSqStack(SqStack*& s, TBTNode* e) {
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

//由二叉树的括号表示法创建未线索化的二叉树
void createUnTBTree(TBTNode*& b, char str[]) {
	SqStack* s;

	TBTNode* p = NULL;

	int i = 0, k = 0;

	char ch = str[i];

	initSqStack(s);

	b = NULL;

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
			p = (TBTNode*)malloc(sizeof(TBTNode));

			p->data = ch;

			p->lchild = p->rchild = NULL;

			p->ltag = p->rtag = 0;

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

//线索化：中序遍历的最后一个结点的右孩子指针不会被线索化，但第一个结点的左孩子会被线索化，即最后一个结点 rchild = NULL，但 rtag = 0，第一个结点的 lchild = NULL，ltag = 1
void thread(TBTNode*& p, TBTNode*& pre) {
	if (p != NULL)
	{
		thread(p->lchild, pre);

		if (p->lchild == NULL)
		{
			p->lchild = pre;

			p->ltag = 1;
		}

		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;

			pre->rtag = 1;
		}

		pre = p;

		thread(p->rchild, pre);
	}
}

//创建完整的线索二叉树：线索化后最后一个结点的 rchild = NULL，但 rtag = 0，此时应该把 rtag 置为 1，使最后一个的右指针线索化
void createTBTree(TBTNode* b) { // 
	TBTNode* pre = NULL;

	if (b != NULL)
	{
		thread(b, pre);

		pre->rtag = 1;
	}
}

int main() {
	TBTNode* b;

	char str[] = "A(B(,C),D(E,F))";

	createUnTBTree(b, str);

	createTBTree(b);

	return 0;
}