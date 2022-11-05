#include <stdio.h>

// 求 1 到 100 之间所有整数的和，当和大于 2000 时查看此时和为多少。
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