/*
	1	C++ 把取地址符 & 称为引用。
*/

#include <stdio.h>

#include <stdlib.h>

// C++ 中传递引用修改原函数的值。
// &b 是一个地址变量，b 是一个整型变量，实际调用的时候需要传一个整型变量。
void change(int& b) {
	b++;
}

// *&t 是一个二级指针变量，t 是一个指针变量，实际调用的时候需要传一个指针变量。
void change_address(int*& t) {
	t[0] = 5;
}

void main() {
	int a = 10;

	change(a);

	// 输出 11。
	printf("%d\n", a);

	// malloc 默认返回值的类型是 void *，这里防止警告加上强制类型转换。
	int* p = (int *)malloc(20);

	// p 是一个指针变量。
	change_address(p);

	// 输出 5。
	printf("%d\n", p[0]);
}