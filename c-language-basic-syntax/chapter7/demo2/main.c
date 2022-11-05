#include <stdio.h>

struct student {
	char name[14];

	char sex;

	int age;
};

void main() {
	struct student s1 = { "zhangsan",'m',20 };

	struct student* p = &s1;

	// *p.name 编译出错，因为 . 的优先级比 * 高，应该加上括号。
	printf("%s %c %d\n", (*p).name, (*p).sex, (*p).age);

	// 指针成员选择，语义和上一句一样。
	printf("%s %c %d\n", p->name, p->sex, p->age);
}