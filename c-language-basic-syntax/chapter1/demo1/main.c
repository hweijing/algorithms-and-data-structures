/*
	1	源程序 demo1.c 经过编译变成目标文件 demo1.obj，demo1.obj 文件中均是 0 / 1 类型的机器码，
		即 CPU 能够识别的指令，该文件本身并不能执行。demo1.obj 经过链接后生成 demo1.exe 可执行文件。
*/

// 引用头文件。
#include <stdio.h>
#include <stdlib.h>

void main() {
	printf("Hello World");

	// 本地点击 demo1.exe 文件后出现暂停效果。
	system("pause");
}