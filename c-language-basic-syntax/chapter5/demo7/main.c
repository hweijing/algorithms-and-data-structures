#include <stdio.h>

// d 是指针变量，c 是数组变量。
// d 在这里接到是 c 的值，也就是数组变量的值，相当于执行了 char* d = c，可以推出 d = &c[0]，*d = c[0] = d[0]。
// 改变 *d 的值相当于改变 c[0] 的值。
void change(char* d) {
	int i = 0;

	while (d[i])
	{
		d[i] = d[i] - 32;

		i++;
	}
}

void main() {
	char c[10] = "hello";

	change(c);

	puts(c);
}