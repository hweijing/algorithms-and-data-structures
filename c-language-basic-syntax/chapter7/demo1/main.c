#include <stdio.h>

// 声明一个结构体变量。
// 一般放在全局中使用，局部变量只能在函数中使用。
struct student {
	char name[14];

	char sex;

	int age;
};

void main() {
	struct student s1 = { "zhangsan",'m',20 };

	// 输出 zhangsan m 20。
	printf("%s %c %d\n", s1.name, s1.sex, s1.age);

	// 结构体数组的定义方式。
	struct student sArr[3] = {
		"zhangsan",'m',20,
		"lisi",'w',18,
		"wangwu",'m',22
	};

	// 输出 lisi w 18。
	printf("%s %c %d\n", sArr[1].name, sArr[1].sex, sArr[1].age);
}