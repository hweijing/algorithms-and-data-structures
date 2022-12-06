#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef struct SqString {
	char data[MaxSize];
	int length;
};

void strAssign(SqString& s, char str[]) {
	int i = 0;

	while (str[i] != '\0')
	{
		s.data[i] = str[i];
		i++;
	}

	s.length = i;
}

void strCopy(SqString& s, SqString t) { //�� t ���Ƹ� s
	for (int i = 0; i < t.length; i++)
	{
		s.data[i] = t.data[i];
	}

	s.length = t.length;
}

//�жϴ���ȣ����������ĳ���һ�����Ҹ���λ�ö�Ӧ���ַ�Ҳһ��ʱ������ true�����򷵻� false
bool strEqual(SqString s, SqString t) {
	if (s.length != t.length)
	{
		return false;
	}

	for (int i = 0; i < s.length; i++)
	{
		if (s.data[i] != t.data[i])
		{
			return false;
		}
	}

	return true;
}

int strLength(SqString s) {
	return s.length;
}

//���Ӵ�
SqString concat(SqString s, SqString t) {
	SqString str;

	int i;

	for (i = 0; i < s.length; i++) //�Ȱ� s �е�����Ԫ�ط��� str
	{
		str.data[i] = s.data[i];
	}

	for (i = 0; i < t.length; i++) //�ٰ� t �е�����Ԫ�ط��� str
	{
		str.data[s.length + i] = t.data[i];
	}

	str.length = s.length + t.length;

	return str;
}

//���ִ����� s �е� i ���ַ���ʼ���������� j ���ַ���ɵ��Ӵ�������������ȷʱ�����ؿմ�
SqString subStr(SqString s, int i, int j) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || j < 0 || i + j - 1 > s.length) //��� j = 0���������� 0 ���ַ���ɵ��ִ�������մ�
	{
		return str;
	}

	for (int k = i - 1; k < i + j - 1; k++) //�� s �дӵ� i ���ַ����� i + j - 1 ���ַ����� str
	{
		str.data[k - i + 1] = s.data[k];
	}

	str.length = j;

	return str;
}

//�� t ���뵽 s �ĵ� i ��λ���ϣ����ز����Ľ����������������ȷ�����ؿմ�
SqString insStr(SqString s, int i, SqString t) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length + 1)
	{
		return str;
	}

	int j;

	for (j = 0; j < i - 1; j++) //�Ȱ� s �дӵ� 1 ���ַ����� i - 1 ���ַ����� str
	{
		str.data[j] = s.data[j];
	}

	for (j = 0; j < t.length; i++) //�ٰ� t �е������ַ����� str
	{
		str.data[i + j - 1] = t.data[j];
	}

	for (j = i - 1; j < s.length; i++) //�ٰ� s �дӵ� i ���ַ������һ���ַ����� str 
	{
		str.data[t.length + j] = s.data[j];
	}

	str.length = s.length + t.length;

	return str;
}

//�� s ��ɾ���ӵ� i ���ַ���ʼ������ j �����ַ����Ӵ��������µĴ�������������ȷʱ�����ؿմ�
SqString delStr(SqString s, int i, int j) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; i++) //�Ȱ� s �дӵ� 1 ���ַ����� i - 1 ���ַ����� str
	{
		str.data[k] = s.data[k];
	}

	for (k = i + j - 1; k < s.length; k++) //�ٰ� s �дӵ� i + j ���ַ������һ���ַ����� str
	{
		str.data[k - j] = s.data[k];
	}

	str.length = s.length - j;

	return str;
}


//�Ӵ����滻���� s �дӵ� i ���ַ���ʼ������ j ���ַ����ɵ��Ӵ��滻Ϊ t������������ȷ�����ؿմ�
SqString repStr(SqString s, int i, int j, SqString t) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++) //�Ȱ� s �дӵ� 1 ���ַ����� i - 1 ���ַ����� str
	{
		str.data[k] = s.data[k];
	}

	for (k = 0; k < t.length; k++) //�ٰ� t �е������ַ����� str
	{
		str.data[i + k - 1] = t.data[k];
	}

	for (k = i + j - 1; k < s.length; k++) //�ٰ� s �дӵ� i + j ���ַ������һ���ַ����� str
	{
		str.data[t.length + k - j] = s.data[k];
	}

	str.length = s.length - j + t.length;

	return str;
}

//�����
void dispStr(SqString s) {
	if (s.length > 0)
	{
		for (int i = 0; i < s.length; i++)
		{
			printf("%c\n", s.data[i]);
		}
	}
}

int main() {
	char str1[] = "ijk";

	char str2[] = "ijkl";

	SqString s1;

	SqString s2;

	SqString s3;

	strAssign(s1, str1); //S ��һ���ַ����� data �� һ������ length ��ɣ�S.data �в����� \0

	strCopy(s2, s1);

	strAssign(s3, str2);

	bool boolean;

	//true
	boolean = strEqual(s1, s2);

	//false
	boolean = strEqual(s1, s3);

	//ijkijkl
	SqString s4 = concat(s1, s3);

	//jki
	SqString s5 = subStr(s4, 2, 0);

	return 0;
}