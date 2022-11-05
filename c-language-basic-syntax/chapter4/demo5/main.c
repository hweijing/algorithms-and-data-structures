/*
	1	字符数组的数组名里存的就是字符数组的起始地址。
	2	puts 只能输出字符串。
*/

#include <stdio.h>

void main() {
	// a 的地址编号与 a[0] 的地址编号一样。
	char a[10];

	gets(a);

	puts(a);
}