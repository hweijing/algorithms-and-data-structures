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

	L = (LinkNode*)malloc(sizeof(LinkNode)); //创建头节点，L 是头节点的外指针，头节点的内指针是首节点的外指针

	L->next = NULL; //默认没有首节点，所以头节点的内指针是 NULL

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode)); //第一次循环时创建首节点，s 是首节点的外指针
		s->data = a[i];
		s->next = L->next; //第一次循环时只有一个首节点，所以首节点的内指针与头节点的内指针一样都是 NULL，因为不知道是否还要创建下一个节点，所以每次循环创建的节点的内指针都是 NULL
		L->next = s; //把首节点的外指针赋给头节点的内指针，形成链表
	}

	//L 在链表中被当作一个孤立的指针变量，L 作为头节点的外指针（头指针），不会成为该链表中任何一个节点的内指针，而头节点的内指针是首节点的外指针，只有头节点不存放数据
	//头插法的逻辑是除首节点外，每一个节点都插入到上一个节点的前面，若把头节点的方向当成前，该链表的插入顺序是倒序，例如 1 2 3 4 5 在链表中的前后顺序是 5 4 3 2 1
}

//尾插法
void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;

	L = (LinkNode*)malloc(sizeof(LinkNode));

	r = L; //头节点对应的两个头指针，一个头指针 L，一个 r 指针

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s; //把新增节点的外指针赋给上一节点的内指针，r 指针和上一节点的外指针同时指向上一节点，因为在当前循环中拿不到上一节点的外指针，所以增加 r 指针用来存放上一结点的外指针
		r = s; //移动 r 指针到新增节点的外指针
	}

	r->next = NULL; //形成链表后，r 指针和最后一个节点的外指针都指向最后一个节点，所以把最后一个节点的内指针置为 NULL

	//尾插法的逻辑是新增一个 r 指针作为游走指针，每新增一个节点后，该节点的外指针和 r 指针会同时指向该节点，该链表的插入顺序是顺序，例如 1 2 3 4 5 在链表中的前后顺序是 1 2 3 4 5
}

int main() {
	ElemType a[] = { 1,2,3,4,5 };

	LinkNode* L;

	//createLinkListF(L, a, 5);

	createLinkListR(L, a, 5);

	return 0;
}