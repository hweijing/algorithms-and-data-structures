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

	s->top == -1;
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

	if (b->data = e)
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

			dispBTree(b->lchild);

			printf(")");
		}
	}
}

void preOrder(BTNode* b) {
	if (b != NULL)
	{
		printf("%c", b->data);
		preOrder(b->lchild);
		preOrder(b->rchild);
	}
}

void inOrder(BTNode* b) {
	if (b != NULL)
	{
		inOrder(b->lchild);
		printf("%c", b->data);
		inOrder(b->rchild);
	}
}

void postOrder(BTNode* b) {
	if (b != NULL)
	{
		postOrder(b->lchild);
		postOrder(b->rchild);
		printf("%c", b->data);
	}
}

//����������ܽ����
int nodeNumberBTree(BTNode* b) {
	if (b == NULL)
	{
		return 0;
	}

	return nodeNumberBTree(b->lchild) + nodeNumberBTree(b->rchild) + 1;
}

//���������������Ҷ�ӽ���ֵ
void leafNode(BTNode* b) {
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			printf("%c", b->data);
		}

		leafNode(b->lchild);

		leafNode(b->rchild);
	}
}

//���������ֵΪ e �Ľ�����ڵĲ��
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

	if (n != NULL)
	{
		return n;
	}

	return level(b->rchild, e, h + 1);
}

//��������е� k ��Ľ�����
void lNodeNumber(BTNode* b, int h, int k, int& n) { //h ��ʾ b ָ��Ľ�����ڵĲ�Σ�Ĭ��Ϊ 1���ݹ����ʱҪ + 1
	if (b == NULL)
	{
		return;
	}

	if (h == k) //�ҵ��� k ��
	{
		n++;
	}

	if (h < k)
	{
		lNodeNumber(b->lchild, h + 1, k, n);

		lNodeNumber(b->rchild, h + 1, k, n);
	}
}

//�ж����ö������Ƿ�����
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

int main() {
	return 0;
}