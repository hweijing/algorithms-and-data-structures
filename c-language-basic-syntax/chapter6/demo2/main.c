#include <stdio.h>

// ��ݹ�ʵ�� n �Ľ׳ˡ�
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