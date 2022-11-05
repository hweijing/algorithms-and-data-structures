#include <stdio.h>

// 求 1 到 100 之间奇数的和。
void main() {
	int total = 0;

	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			// 提前结束本轮循环。
			continue;
		}
		total = total + i;
	}

	printf("%d", total);
}