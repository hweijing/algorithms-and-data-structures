/*
	1	typedef 的作用是起别名。
		第一个参数是结构体的参数，第二个参数是结构体指针的参数。
*/

#include <stdio.h>

typedef struct student{
	char name[14];

	char sex;

	int age;
}stu, * pstu;

int main() {
	// 结构体在使用的时候才会有大小。只声明未使用的话没有大小。
	stu s = { "zhangsan",'m',18 };

	pstu p = &s;

	printf("%s %c %d\n", p->name, p->sex, p->age);

	return 0;
}