#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 以字符的形式输出一个字符串。
void main() {
	int i = 0;

	char c[10];

	// scanf 通过 %s 读取字符串时，当输入空格时就会匹配结束，因为空格的值为 00，字符串碰到 00 会结束匹配。
	scanf("%s", &c);

	while (c[i] != 0)
	{
		printf("%c", c[i] - 32);
		i++;
	}
}