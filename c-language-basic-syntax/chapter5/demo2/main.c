/*
	1	ָ���ʹ�ó���ͨ��ֻ����������������ƫ�ơ�
	2	ÿ���������Լ������ĺ���ջ�ռ䣬Ҳ�������Լ��������ڴ档
		�����ڶ���ı�����Ϊ�ֲ��������ֲ������洢�ں����Ķ����ڴ��С�
	3	C ���Եĺ���ִ����Ϻ��ڴ�ͻ��ͷš�
	4	C ���Ժ������ö���ֵ���ݣ��൱�ڰ�ʵ�ε�ֵ�����β��ˣ����Բ���ı�ʵ�ε�ֵ��
		����ָ����Դ�һ����ַ���൱�ڰ�ʵ�εĵ�ַ�����β��ˣ������Ϳ��Ըı�ʵ�ε�ֵ�ˡ�
*/

#include <stdio.h>

void change(int* j) {
	*j = 777;
}

void main() {
	int i = 1;

	printf("�ı�ǰ��ֵ��%d\n", i);

	change(&i);

	printf("�ı���ֵ��%d\n", i);
}