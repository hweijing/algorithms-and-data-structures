/*
	1	变量在声明未赋值的情况下默认值是 -858993460，其对应地址是随机的。
	2	英特尔 CPU 是 X86 架构，X86 架构都是小端存储，低位在前，高位在后。
	3	0x 开头的数字表示十六进制，0 开头的数字表示八进制。
	4	整型为 4 个字节。
*/

#include <stdio.h>

void main() {
	int i = 123;
}