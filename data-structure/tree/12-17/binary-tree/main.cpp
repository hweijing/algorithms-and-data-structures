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
}

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

typedef struct CirQueue {
	BTNode* data[MaxSize];
	int front;
	int rear;
};

void initCirQueue(CirQueue*& q) {
	q = (CirQueue*)malloc(sizeof(CirQueue));

	q->front = q->rear = 0;
}

void destoryCirQueue(CirQueue*& q) {
	free(q);
}

bool isEmptyCirQueue(CirQueue* q) {
	return q->front == q->rear;
}

bool enCirQueue(CirQueue*& q, BTNode* e) {
	if ((q->rear + 1) % MaxSize == q->front)
	{
		return false;
	}

	q->rear = (q->rear + 1) % MaxSize;

	q->data[q->rear] = e;

	return true;
}

bool deCirQueue(CirQueue*& q, BTNode*& e) {
	if (q->front == q->rear)
	{
		return false;
	}

	q->front = (q->front + 1) % MaxSize;

	e = q->data[q->front];

	return true;
}

void destoryBTree(BTNode*& b) {
	if (b != NULL)
	{
		destoryBTree(b->lchild);

		destoryBTree(b->rchild);

		free(b);
	}
}

BTNode* findNode(BTNode* b, char e) {
	if (b == NULL)
	{
		return NULL;
	}

	if (b->data == e)
	{
		return b;
	}

	BTNode* p = findNode(b->lchild, e);

	if (p != NULL)
	{
		return p;
	}

	return findNode(b->rchild, e);
}

BTNode* lchildNode(BTNode* b) {
	return b->lchild;
}

BTNode* rchildNode(BTNode* b) {
	return b->rchild;
}

int heightBTree(BTNode* b) {
	if (b == NULL)
	{
		return 0;
	}

	int lchildh = heightBTree(b->lchild);

	int rchildh = heightBTree(b->rchild);

	return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
}

void dispBTree(BTNode* b) {
	if (b != NULL)
	{
		printf("%c", b->data);

		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");

			dispBTree(b->lchild);

			if (b->rchild != NULL)
			{
				printf(",");
			}

			dispBTree(b->rchild);

			printf(")");
		}
	}
}

int nodeNumber(BTNode* b) {
	if (b == NULL)
	{
		return 0;
	}

	return nodeNumber(b->lchild) + nodeNumber(b->rchild) + 1;
}

void dispLeaf(BTNode* b) {
	if (b == NULL)
	{
		return;
	}

	if (b->lchild == NULL && b->rchild == NULL)
	{
		printf("&c", b->data);
	}

	dispLeaf(b->lchild);

	dispLeaf(b->rchild);
}

int level(BTNode* b, char e, int h) {
	int n;

	if (b == NULL)
	{
		return 0;
	}

	if (b->data == e)
	{
		return h;
	}

	n = level(b->lchild, e, h + 1);

	if (n != 0)
	{
		return n;
	}

	return level(b->rchild, e, h + 1);
}

void lNodeNumber(BTNode* b, int h, int k, int& n) {
	if (b == NULL)
	{
		return;
	}

	if (h == k)
	{
		n++;
	}

	if (h < k)
	{
		lNodeNumber(b->lchild, h + 1, k, n);

		lNodeNumber(b->rchild, h + 1, k, n);
	}
}

bool like(BTNode* b1, BTNode* b2) {
	if (b1 == NULL && b2 == NULL)
	{
		return true;
	}

	if (b1 == NULL || b2 == NULL)
	{
		return false;
	}

	bool like1 = like(b1->lchild, b2->lchild);

	bool like2 = like(b1->rchild, b2->rchild);

	return like1 && like2;
}

void levelOrder(BTNode* b) {
	CirQueue* q;

	BTNode* p;

	initCirQueue(q);

	enCirQueue(q, b);

	while (!isEmptyCirQueue(q))
	{
		deCirQueue(q, p);

		printf("%c", p->data);

		if (b->lchild != NULL)
		{
			enCirQueue(q, p->lchild);
		}

		if (b->rchild != NULL)
		{
			enCirQueue(q, p->rchild);
		}
	}

	destoryCirQueue(q);
}

//借助中序递归遍历算法实现在中序序列中找到指定结点的前驱
BTNode* bpre = NULL;

void inOrder(BTNode* b, BTNode* p, BTNode*& ppre) {
	if (b != NULL)
	{
		inOrder(b->lchild, p, ppre);

		if (b == p)
		{
			ppre = bpre;
		}
		else
		{
			bpre = b;
		}

		inOrder(b->rchild, p, ppre);
	}
}

int main() {
	BTNode* b;

	char str[] = "A(B(,C),D(E,F))";

	createBTree(b, str);

	BTNode* p = findNode(b, 'E'); //p 就是值为 e 的目标结点，返回它的前驱结点

	BTNode* q = NULL;

	inOrder(b, p, q);

	return 0;
}