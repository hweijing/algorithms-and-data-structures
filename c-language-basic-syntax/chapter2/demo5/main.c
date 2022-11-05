/*
	1	用单引号括起来的一个字符是字符型常量，且只能包含一个字符。
	2	一个字符变量占用 1 字节。
*/

#include <stdio.h>

void main() {
	char a = 'a';

	// 输入a。
	printf("%c\n", a);

	// 输入97。
	printf("%d\n", a);
}