#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ���ַ�����ʽ���һ���ַ�����
void main() {
	int i = 0;

	char c[10];

	// scanf ͨ�� %s ��ȡ�ַ���ʱ��������ո�ʱ�ͻ�ƥ���������Ϊ�ո��ֵΪ 00���ַ������� 00 �����ƥ�䡣
	scanf("%s", &c);

	while (c[i] != 0)
	{
		printf("%c", c[i] - 32);
		i++;
	}
}