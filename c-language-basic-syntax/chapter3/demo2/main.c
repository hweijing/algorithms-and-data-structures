#include <stdio.h>

// �� 1 �� 100 ֮�������ĺ͡�
void main() {
	int total = 0;

	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			// ��ǰ��������ѭ����
			continue;
		}
		total = total + i;
	}

	printf("%d", total);
}