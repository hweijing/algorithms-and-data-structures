/*
	1	�ڴ��в�����ջ�Ͷѣ�����һ�����������ַ�������������ֻ����ַ���������
*/

#include <stdio.h>

void main() {
	// �൱�ڰ��ַ������� "hello" ���ַ��������������ַ��ĵ�ַ��ָ�������ֵ�������� p��
	char* p = "hello";

	char c[10] = "hello";

	c[0] = 'H';

	// �������ַ��������������ݿɶ�����д��
	// p[0] = 'H';

	// �൱�ڰ��ַ������� "world" ���ַ��������������ַ��ĵ�ַ��ָ�������ֵ�������� p��
	p = "world";

	// ������
	// ��Ϊ�����ڱ���ʱ�ͻ���ջ��Ϊ�������ͱ�����������������ַ��
	// �����������ֵ��������ͱ�����ֵ��ͬ�����������ֵ�������е�һ��Ԫ�صĵ�ַ������ֻ���ǵ�ַ��
	// ��Ҫ�ı����������ֵ���൱�ڸı������е�һ��Ԫ�أ��������ͱ������ĵ�ַ���� C ���Թ涨�������ͱ����ĵ�ַ�����޸ġ�
	// c = "world";
}