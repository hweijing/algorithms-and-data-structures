#include <stdio.h>

void main() {
	int i = 5;

	float j = i / 2;

	// (float) ǿ������ת���������
	float k = (float)i / 2;

	// C �����ڳ���������ʽ�л������������������������
	// ��� 2.000000��
	printf("%f\n", j);

	// ��� 2.500000��
	printf("%f", k);
}