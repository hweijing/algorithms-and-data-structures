#include <stdio.h>

struct student {
	char name[14];

	char sex;

	int age;
};

void main() {
	struct student s1 = { "zhangsan",'m',20 };

	struct student* p = &s1;

	// *p.name ���������Ϊ . �����ȼ��� * �ߣ�Ӧ�ü������š�
	printf("%s %c %d\n", (*p).name, (*p).sex, (*p).age);

	// ָ���Աѡ���������һ��һ����
	printf("%s %c %d\n", p->name, p->sex, p->age);
}