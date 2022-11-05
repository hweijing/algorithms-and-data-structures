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

	L = (LinkNode*)malloc(sizeof(LinkNode)); //����ͷ�ڵ㣬L ��ͷ�ڵ����ָ�룬ͷ�ڵ����ָ�����׽ڵ����ָ��

	L->next = NULL; //Ĭ��û���׽ڵ㣬����ͷ�ڵ����ָ���� NULL

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode)); //��һ��ѭ��ʱ�����׽ڵ㣬s ���׽ڵ����ָ��
		s->data = a[i];
		s->next = L->next; //��һ��ѭ��ʱֻ��һ���׽ڵ㣬�����׽ڵ����ָ����ͷ�ڵ����ָ��һ������ NULL����Ϊ��֪���Ƿ�Ҫ������һ���ڵ㣬����ÿ��ѭ�������Ľڵ����ָ�붼�� NULL
		L->next = s; //���׽ڵ����ָ�븳��ͷ�ڵ����ָ�룬�γ�����
	}

	//L �������б�����һ��������ָ�������L ��Ϊͷ�ڵ����ָ�루ͷָ�룩�������Ϊ���������κ�һ���ڵ����ָ�룬��ͷ�ڵ����ָ�����׽ڵ����ָ�룬ֻ��ͷ�ڵ㲻�������
	//ͷ�巨���߼��ǳ��׽ڵ��⣬ÿһ���ڵ㶼���뵽��һ���ڵ��ǰ�棬����ͷ�ڵ�ķ��򵱳�ǰ��������Ĳ���˳���ǵ������� 1 2 3 4 5 �������е�ǰ��˳���� 5 4 3 2 1
}

//β�巨
void createLinkListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;

	L = (LinkNode*)malloc(sizeof(LinkNode));

	r = L; //ͷ�ڵ��Ӧ������ͷָ�룬һ��ͷָ�� L��һ�� r ָ��

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s; //�������ڵ����ָ�븳����һ�ڵ����ָ�룬r ָ�����һ�ڵ����ָ��ͬʱָ����һ�ڵ㣬��Ϊ�ڵ�ǰѭ�����ò�����һ�ڵ����ָ�룬�������� r ָ�����������һ������ָ��
		r = s; //�ƶ� r ָ�뵽�����ڵ����ָ��
	}

	r->next = NULL; //�γ������r ָ������һ���ڵ����ָ�붼ָ�����һ���ڵ㣬���԰����һ���ڵ����ָ����Ϊ NULL

	//β�巨���߼�������һ�� r ָ����Ϊ����ָ�룬ÿ����һ���ڵ�󣬸ýڵ����ָ��� r ָ���ͬʱָ��ýڵ㣬������Ĳ���˳����˳������ 1 2 3 4 5 �������е�ǰ��˳���� 1 2 3 4 5
}

int main() {
	ElemType a[] = { 1,2,3,4,5 };

	LinkNode* L;

	//createLinkListF(L, a, 5);

	createLinkListR(L, a, 5);

	return 0;
}