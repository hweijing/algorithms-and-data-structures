/*
	1	#include ����ͷ�ļ�������������һЩ������������ import��
		printf��scanf�ȵȺ������� <stdio.h> ����ļ��С�
	2	�����ַ�
			%d һ��ʮ��������
			%f һ��������
			%c һ����һ���ַ�
	3	��׼���뻺����Ϊ�յ�ʱ��scanf �Ż����������� \n �ڱ�׼���뻺������ʱ���Ͳ��������һ�� scanf ������
	4	scanf �ڶ�ȡ���͡������͡��ַ���ʱ������ɾ����Щ�ַ���Ȼ����������
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main() {
	int i;

	char c;

	scanf("%d", &i);

	printf("%d", i);

	// ����������
	scanf("%c", &c);

	printf("%c", c);
}