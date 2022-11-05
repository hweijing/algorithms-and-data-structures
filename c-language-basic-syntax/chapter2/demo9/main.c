/*
	1	#include 引入头文件的作用是引入一些函数，类似与 import。
		printf、scanf等等函数均在 <stdio.h> 这个文件中。
	2	控制字符
			%d 一个十进制整数
			%f 一个浮点数
			%c 一个单一的字符
	3	标准输入缓冲区为空的时候，scanf 才会阻塞，例如 \n 在标准输入缓冲区中时，就不会造成下一个 scanf 阻塞。
	4	scanf 在读取整型、浮点型、字符串时会首先删除这些字符，然后再阻塞。
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main() {
	int i;

	char c;

	scanf("%d", &i);

	printf("%d", i);

	// 不会阻塞。
	scanf("%c", &c);

	printf("%c", c);
}