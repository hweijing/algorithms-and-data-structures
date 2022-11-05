/*
	1	%c 以字符型输出。
	2	每一个项目编译后是一个 .exe 可执行文件。
*/

#include <stdio.h>

void main() {
	char a = 'a';

	a = a - 32;

	printf("%c", a);
}