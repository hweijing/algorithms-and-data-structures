#include <stdio.h>

// d ��ָ�������c �����������
// d ������ӵ��� c ��ֵ��Ҳ�������������ֵ���൱��ִ���� char* d = c�������Ƴ� d = &c[0]��*d = c[0] = d[0]��
// �ı� *d ��ֵ�൱�ڸı� c[0] ��ֵ��
void change(char* d) {
	int i = 0;

	while (d[i])
	{
		d[i] = d[i] - 32;

		i++;
	}
}

void main() {
	char c[10] = "hello";

	change(c);

	puts(c);
}