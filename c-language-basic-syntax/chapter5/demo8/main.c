/*
	1	基本类型变量和数组类型变量都是存放在栈空间中，而栈空间的大小在编译时是确定的。
		如果使用的空间大小不确定，那就要使用堆空间。
	2	程序是放在磁盘上的有序的指令集和。
		程序启动起来时才叫进程，程序运行时需要内存。
	3	栈是操作系统提供的数据结构，计算机会在底层对栈提供支持，分配专门的寄存器存放栈的地址，
		压栈操作、出栈操作都有专门的指令执行，所以栈的效率比较高。
	4	堆是 C/C++ 函数库提供的数据结构，它的机制很复杂，
		例如为了分配一块内存，库函数会按照一定的算法在堆中搜索可用的足够大小的空间，如果没有足够大小的空间，
		那么就有可能调用系统功能去增加程序数据段的内存空间，这样就有机会分到足够大小的内存，
		堆的效率比栈要低。
	5	栈由系统自动管理，堆的申请和释放需要自行管理。
	6	malloc 代表在堆中申请空间，单位是字节。
	7	free 代表释放空间，free 的时候不允许指针偏移，必须和 malloc 返回值一致。
		free 后需要把 malloc 返回的指针变量置为 NULL，否则该指针变量称为野指针——指向了一块不可自行管理的内存空间。
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char* print_stack() {
	char c[] = "print_stack";

	// 输出 print_stack。
	puts(c);

	return c;
}

char* print_malloc() {
	// 不进行强制类型转换的话会有警告。
	char* c = (char*)malloc(20);

	strcpy(c, "print_malloc");

	// 输出 print_malloc。
	puts(c);

	return c;
}

void main() {
	char* p;

	p = print_stack();

	// 输出不符合预期。
	// 因为 print_stack 函数中的变量都在栈中，而栈中的变量会随着函数的执行结束而释放，所以当回到 main 函数中时，c 的值已经不存在了。
	puts(p);

	p = print_malloc();

	// 输出 print_malloc。
	puts(p);

	// 对 p 在堆中的值清零。
	free(p);

	// 置为空后，*p 就无法读取内存了。
	p = NULL;
}