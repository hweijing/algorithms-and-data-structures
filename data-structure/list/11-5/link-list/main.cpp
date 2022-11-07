#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next; //next �������Ϊ��һ������next �а��� data �� next���ýṹ��Ϊ�ݹ��ͽṹ��
}LinkNode;

//ͷ�巨
void createLinkListF(LinkNode*& L, ElemType a[], int n) { //n �� a �ĳ���
	LinkNode* s;

	L = (LinkNode*)malloc(sizeof(LinkNode)); //����ͷ��㣬L ��ͷ������ָ�룬ͷ������ָ�����׽�����ָ��

	L->next = NULL; //Ĭ��û���׽�㣬����ͷ������ָ���� NULL

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode)); //��һ��ѭ��ʱ�����׽�㣬s ���׽�����ָ��
		s->data = a[i];
		s->next = L->next; //��һ��ѭ��ʱֻ��һ���׽�㣬�����׽�����ָ����ͷ������ָ��һ������ NULL����Ϊ��֪���Ƿ�Ҫ������һ����㣬����ÿ��ѭ�������Ľ�����ָ�붼�� NULL
		L->next = s; //���׽�����ָ�븳��ͷ������ָ�룬�γ�����
	}

	//L �������б�����һ��������ָ�������L ��Ϊͷ������ָ�루ͷָ�룩�������Ϊ���������κ�һ��������ָ�룬��ͷ������ָ�����׽�����ָ�룬ֻ��ͷ��㲻�������
	//ͷ�巨���߼��ǳ��׽���⣬ÿһ����㶼���뵽��һ������ǰ�棬����ͷ���ķ��򵱳�ǰ��������Ĳ���˳���ǵ������� 1 2 3 4 5 �������е�ǰ��˳���� 5 4 3 2 1
}

//β�巨
void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;

	L = (LinkNode*)malloc(sizeof(LinkNode));

	r = L; //ͷ����Ӧ������ͷָ�룬һ��ͷָ�� L��һ�� r ָ��

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s; //������������ָ�븳����һ������ָ�룬r ָ�����һ������ָ��ͬʱָ����һ��㣬��Ϊ�ڵ�ǰѭ�����ò�����һ������ָ�룬�������� r ָ�����������һ������ָ��
		r = s; //�ƶ� r ָ�뵽����������ָ��
	}

	r->next = NULL; //�γ������r ָ������һ��������ָ�붼ָ�����һ����㣬���԰����һ��������ָ����Ϊ NULL

	//β�巨���߼�������һ�� r ָ����Ϊ����ָ�룬ÿ����һ�����󣬸ý�����ָ��� r ָ���ͬʱָ��ý�㣬������Ĳ���˳����˳������ 1 2 3 4 5 �������е�ǰ��˳���� 1 2 3 4 5
}

int main() {
	ElemType a[] = { 1,2,3,4,5 };

	LinkNode* L;

	//createLinkListF(L, a, 5);

	createLinkListR(L, a, 5);

	return 0;
}