#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next; //next 可以理解为是一个对象，next 中包含 data 和 next，该结构体为递归型结构体
}LinkNode;

//头插法
void createLinkListF(LinkNode*& L, ElemType a[], int n) { //n 是 a 的长度
	LinkNode* s;

	L = (LinkNode*)malloc(sizeof(LinkNode)); //创建头结点，L 是头结点的外指针，头结点的内指针是首结点的外指针

	L->next = NULL; //默认没有首结点，所以头结点的内指针是 NULL

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode)); //第一次循环时创建首结点，s 是首结点的外指针
		s->data = a[i];
		s->next = L->next; //第一次循环时只有一个首结点，所以首结点的内指针与头结点的内指针一样都是 NULL，因为不知道是否还要创建下一个结点，所以每次循环创建的结点的内指针都是 NULL
		L->next = s; //把首结点的外指针赋给头结点的内指针，形成链表
	}

	//L 在链表中被当作一个孤立的指针变量，L 作为头结点的外指针（头指针），不会成为该链表中任何一个结点的内指针，而头结点的内指针是首结点的外指针，只有头结点不存放数据
	//头插法的逻辑是除首结点外，每一个结点都插入到上一个结点的前面，若把头结点的方向当成前，该链表的插入顺序是倒序，例如 1 2 3 4 5 在链表中的前后顺序是 5 4 3 2 1
}

//尾插法
void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;

	L = (LinkNode*)malloc(sizeof(LinkNode));

	r = L; //头结点对应的两个头指针，一个头指针 L，一个 r 指针

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s; //把新增结点的外指针赋给上一结点的内指针，r 指针和上一结点的外指针同时指向上一结点，因为在当前循环中拿不到上一结点的外指针，所以增加 r 指针用来存放上一结点的外指针
		r = s; //移动 r 指针到新增结点的外指针
	}

	r->next = NULL; //形成链表后，r 指针和最后一个结点的外指针都指向最后一个结点，所以把最后一个结点的内指针置为 NULL

	//尾插法的逻辑是新增一个 r 指针作为游走指针，每新增一个结点后，该结点的外指针和 r 指针会同时指向该结点，该链表的插入顺序是顺序，例如 1 2 3 4 5 在链表中的前后顺序是 1 2 3 4 5
}

int main() {
	ElemType a[] = { 1,2,3,4,5 };

	LinkNode* L;

	//createLinkListF(L, a, 5);

	createLinkListR(L, a, 5);

	return 0;
}