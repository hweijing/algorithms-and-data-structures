#include <stdio.h>

// 求递归实现 n 的阶乘。
int recursive(int n) {
	int i = 0;
	if (n == 1)
	{
		i = 1;
		return i;
	}
	i = n * recursive(n - 1);
	return i;
}

void main() {
	int n = 3;

	int i = recursive(n);

	printf("%d", i);
}