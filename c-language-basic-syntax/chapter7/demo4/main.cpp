/*
	1	C++ ��ȡ��ַ�� & ��Ϊ���á�
*/

#include <stdio.h>

#include <stdlib.h>

// C++ �д��������޸�ԭ������ֵ��
// &b ��һ����ַ������b ��һ�����ͱ�����ʵ�ʵ��õ�ʱ����Ҫ��һ�����ͱ�����
void change(int& b) {
	b++;
}

// *&t ��һ������ָ�������t ��һ��ָ�������ʵ�ʵ��õ�ʱ����Ҫ��һ��ָ�������
void change_address(int*& t) {
	t[0] = 5;
}

void main() {
	int a = 10;

	change(a);

	// ��� 11��
	printf("%d\n", a);

	// malloc Ĭ�Ϸ���ֵ�������� void *�������ֹ�������ǿ������ת����
	int* p = (int *)malloc(20);

	// p ��һ��ָ�������
	change_address(p);

	// ��� 5��
	printf("%d\n", p[0]);
}