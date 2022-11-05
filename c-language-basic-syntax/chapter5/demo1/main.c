/*
	1	间接访问是将变量 i 的地址放到另一个变量中。在 C 语言中，指针变量是一种特殊的变量，用来存放变量地址。
		指针变量的定义格式是“基类型 *指针变量名”。指针变量的初始化是某个变量的地址。
	2	指针变量的大小为 4 字节。
	3	取地址操作符 & 也称引用。
*/

#include <stdio.h>

void main() {
	int a = 22;

	int* a_pointer = &a;

	// 输出 22。
	printf("%d\n", *a_pointer);

	char b = 'b';

	char* b_pointer = &b;

	// 输出 b。
	printf("%c", *b_pointer);
}