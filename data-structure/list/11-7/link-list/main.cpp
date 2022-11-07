#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//��ʼ��������
void initLinkList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;
}

void destroyLinkList(LinkNode*& L) {
	LinkNode* pre = L, *p = L->next; //pre ��ͷָ�룬p ���׽�����ָ��

	while (p != NULL) //�� p Ϊ���һ��������ָ��ʱ��p ��ֵΪ NULL����ʱ pre ָ�����һ�����
	{
		free(pre); //��һ��ѭ��ʱ����ͷָ�룬���ú� pre ��ָ���κν��
		pre = p; //ʹ pre ָ�� p ָ��Ľ��
		p = pre->next; //�� p ָ���һ���
	}

	free(pre);
}

//ͷ�巨
void createLinkListF(LinkNode*& L, ElemType a[], int n) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;

	LinkNode* s;

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//β�巨
void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* r, * s;

	r = L;

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}

	r->next = NULL;
}

int main() {
	ElemType a[] = { 1,2 };

	LinkNode* L;

	//createLinkListF(L, a, 2);

	createLinkListR(L, a, 2);

	LinkNode* s = L->next;

	destroyLinkList(L);

	return 0;
}