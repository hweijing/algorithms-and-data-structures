#include <stdio.h>

// ����һ���ṹ�������
// һ�����ȫ����ʹ�ã��ֲ�����ֻ���ں�����ʹ�á�
struct student {
	char name[14];

	char sex;

	int age;
};

void main() {
	struct student s1 = { "zhangsan",'m',20 };

	// ��� zhangsan m 20��
	printf("%s %c %d\n", s1.name, s1.sex, s1.age);

	// �ṹ������Ķ��巽ʽ��
	struct student sArr[3] = {
		"zhangsan",'m',20,
		"lisi",'w',18,
		"wangwu",'m',22
	};

	// ��� lisi w 18��
	printf("%s %c %d\n", sArr[1].name, sArr[1].sex, sArr[1].age);
}