#include <stdio.h>

// �� 1 �� 100 ֮�����������ĺ͡�
void main() {
	int total = 0;

	// �� while ѭ��ʵ�֡�
	/*
	int i = 1;

	while (i <= 100)
	{
		total = total + i;
		i++;
	}
	*/

	// �� for ѭ��ʵ�֡�
	for (int i = 1; i <= 100; i++)
	{
		total = total + i;
	}

	printf("%d", total);
}