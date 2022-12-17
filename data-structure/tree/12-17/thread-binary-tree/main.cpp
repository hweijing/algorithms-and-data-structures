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

//�ɶ����������ű�ʾ������δ�������Ķ�����
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

//��������������������һ�������Һ���ָ�벻�ᱻ������������һ���������ӻᱻ�������������һ����� rchild = NULL���� rtag = 0����һ������ lchild = NULL��ltag = 1
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

//���������������������������������һ������ rchild = NULL���� rtag = 0����ʱӦ�ð� rtag ��Ϊ 1��ʹ���һ������ָ��������
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