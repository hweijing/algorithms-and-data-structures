/*
	1	typedef ���������������
		��һ�������ǽṹ��Ĳ������ڶ��������ǽṹ��ָ��Ĳ�����
*/

#include <stdio.h>

typedef struct student{
	char name[14];

	char sex;

	int age;
}stu, * pstu;

int main() {
	// �ṹ����ʹ�õ�ʱ��Ż��д�С��ֻ����δʹ�õĻ�û�д�С��
	stu s = { "zhangsan",'m',18 };

	pstu p = &s;

	printf("%s %c %d\n", p->name, p->sex, p->age);

	return 0;
}