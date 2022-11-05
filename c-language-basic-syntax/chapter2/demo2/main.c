/*
	1	一个项目里面可以由多个代码文件，但是只能有一个入口 main。
	2	C 语言未提供输入和输出关键字，其输入和输出是通过标准函数库来实现的。
		C 语言通过 scanf 函数读取键盘输入，键盘输入又被称为标准输入。标准输出 printf，标准输入 scanf。
	3	& 代表取地址符。
*/

// 解决 scanf 编译报错问题。
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main() {
	int a;

	// 一定要在变量前加入 & 符号。
	// %d 表示输入或输出十进制有符号数；%f 表示输入或输出浮点数。
	scanf("%d", &a);

	printf("a=%d\n", a);
}