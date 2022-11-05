/*
	1	函数使用详情中对形参有 const 修饰时，代表这个参数可以传一个字符串常量。
*/
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include <stdio.h>

void main() {
	char a[10] = { 'h' };

	// 输出 1。
	printf("%d", strlen(a));

	// strcpy 会改变原数组。
	strcpy(a, "ello");

	// 输出 1ello，strlen 会改变原数组。
	puts(a);

	int b = strcmp("how", "hello");

	// 输出 1，字符串比较时比较的是每个字母对应的 ASCII 码，不是长度。
	printf("%d", b);

	// strcat 会改变原数组。
	strcat(a, "234");

	// 输出 1ello234。
	puts(a);
}