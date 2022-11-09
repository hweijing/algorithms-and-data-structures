#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
};

//��ʼ��������
void initLinkList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));

	L->next = NULL;
}

//���ٵ�����
void destroyLinkList(LinkNode*& L) {
	LinkNode* pre = L, * p = L->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}

	free(pre);
}

//�жϵ������Ƿ�Ϊ�ձ�
bool isEmptyLinkList(LinkNode* L) {
	return L->next == NULL;
}

//������ĳ���
int lengthLinkList(LinkNode* L) {
	int n = 0;

	LinkNode* p = L;

	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}

	return n;
}

//���������
void dispLinkList(LinkNode* L) {
	LinkNode* p = L->next;

	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

//��������ĳ������Ԫ��ֵ
bool getElemLinkList(LinkNode* L, int i, ElemType& e) { //�������λ��
	if (i < 1)
	{
		return false;
	}

	int j = 0; //��¼ p ָ���ƶ��Ĵ���������� n ������ֵ���� p ָ���ͷ��㿪ʼ�ƶ���һ����Ҫ�ƶ� n ��

	LinkNode* p = L;

	while (j < i && p != NULL)
	{
		p = p->next; //�� i �������ĸ���ʱ����ʹ p ָ�������һ��ѭ��ʱָ��һ�������ڵĽ�㣬��ʱ p = NULL��j ��Ȼ��¼��һ��ָ���ƶ������ǻ�������� if �ж�����з��� false
		j++;
	}

	if (p == NULL)
	{
		return false;
	}

	e = p->data;

	return true;
}

//��Ԫ��ֵ����
int getLocateLinkList(LinkNode* L, int& i, ElemType e) {
	LinkNode* p = L->next; //p ָ��ָ���׽��

	int i = 1; //��ʾ����λ��

	while (p != NULL && p->data != e) //�� p ָ��ָ��Ľ�㲻���ڲ��Ҹý���ֵ����������Ԫ��ʱ
	{
		p = p->next;
		i++;
	}

	if (p == NULL)
	{
		return 0; //�Ҳ����� e ��ͬ��Ԫ��ʱ������ 0
	}

	return i;
}

//��������Ԫ��
bool insertLinkList(LinkNode*& L, int i, ElemType e) {
	if (i < 1)
	{
		return false;
	}

	int j = 0;

	LinkNode* p = L, * s;

	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}

	if (p == NULL)
	{
		return false;
	}

	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->data = e;

	s->next = p->next;

	p->next = s;

	return true;
}

//ɾ������Ԫ��
bool deleteLinkList(LinkNode*& L, int i, ElemType& e) {
	if (i < 1)
	{
		return false;
	}

	int j = 0;

	LinkNode* p = L, * q;

	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}

	if (p == NULL)
	{
		return false;
	}

	q = p->next;

	if (q == NULL)
	{
		return false;
	}

	e = q->data;

	p->next = q->next;

	free(q);

	return true;
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

	LinkNode* s, * r = L;

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
	ElemType a[] = { 1,4,7 };

	LinkNode* L;

	//createLinkListF(L, a, 3);

	createLinkListR(L, a, 3);

	lengthLinkList(L);

	dispLinkList(L);

	ElemType data;

	getElemLinkList(L, 5, data);

	return 0;
}