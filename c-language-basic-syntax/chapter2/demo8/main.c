#include <stdio.h>

void main() {
	int i = 5;

	float j = i / 2;

	// (float) 强制类型转换运算符。
	float k = (float)i / 2;

	// C 语言在除法运算表达式中会根据两个数的类型做除法。
	// 输出 2.000000。
	printf("%f\n", j);

	// 输出 2.500000。
	printf("%f", k);
}