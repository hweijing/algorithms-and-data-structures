/*
	1	判断浮点数是否相等，两数相减后的值若大于 -0.0001 并且小于 0.0001，则证明两个浮点数相等。
	2	i++ 是先运算 i 再进行自增 1，++i 是先自增 1 再进行表达式运算。
	3	sizeof 是一个表达式，返回变量的字节长度。
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main() {
	// 倒序输出整型数。
	int i;

	scanf("%d", &i);

	while (i != 0)
	{
		printf("%d", i % 10);
		i = i / 10;
	}
}