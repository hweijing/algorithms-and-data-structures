/*
	1	����ʹ�������ж��β��� const ����ʱ����������������Դ�һ���ַ���������
*/
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include <stdio.h>

void main() {
	char a[10] = { 'h' };

	// ��� 1��
	printf("%d", strlen(a));

	// strcpy ��ı�ԭ���顣
	strcpy(a, "ello");

	// ��� 1ello��strlen ��ı�ԭ���顣
	puts(a);

	int b = strcmp("how", "hello");

	// ��� 1���ַ����Ƚ�ʱ�Ƚϵ���ÿ����ĸ��Ӧ�� ASCII �룬���ǳ��ȡ�
	printf("%d", b);

	// strcat ��ı�ԭ���顣
	strcat(a, "234");

	// ��� 1ello234��
	puts(a);
}