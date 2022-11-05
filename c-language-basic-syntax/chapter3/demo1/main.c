#include <stdio.h>

// 求 1 到 100 之间所有整数的和。
void main() {
	int total = 0;

	// 用 while 循环实现。
	/*
	int i = 1;

	while (i <= 100)
	{
		total = total + i;
		i++;
	}
	*/

	// 用 for 循环实现。
	for (int i = 1; i <= 100; i++)
	{
		total = total + i;
	}

	printf("%d", total);
}