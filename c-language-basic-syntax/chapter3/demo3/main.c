#include <stdio.h>

// �� 1 �� 100 ֮�����������ĺͣ����ʹ��� 2000 ʱ�鿴��ʱ��Ϊ���١�
void main() {
	int i, total = 0;

	for (i = 1; i <= 100; i++)
	{
		if (total > 2000)
		{
			break;
		}
		total = total + i;
	}

	printf("%d %d", total, i);
}