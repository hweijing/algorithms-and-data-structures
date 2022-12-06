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

void strCopy(SqString& s, SqString t) { //将 t 复制给 s
	for (int i = 0; i < t.length; i++)
	{
		s.data[i] = t.data[i];
	}

	s.length = t.length;
}

//判断串相等，当两个串的长度一样并且各个位置对应的字符也一样时，返回 true，否则返回 false
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

//连接串
SqString concat(SqString s, SqString t) {
	SqString str;

	int i;

	for (i = 0; i < s.length; i++) //先把 s 中的所有元素放入 str
	{
		str.data[i] = s.data[i];
	}

	for (i = 0; i < t.length; i++) //再把 t 中的所有元素放入 str
	{
		str.data[s.length + i] = t.data[i];
	}

	str.length = s.length + t.length;

	return str;
}

//求字串，从 s 中第 i 个字符开始，由连续的 j 个字符组成的子串，当参数不正确时，返回空串
SqString subStr(SqString s, int i, int j) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || j < 0 || i + j - 1 > s.length) //如果 j = 0，允许连续 0 个字符组成的字串，允许空串
	{
		return str;
	}

	for (int k = i - 1; k < i + j - 1; k++) //把 s 中从第 i 个字符到第 i + j - 1 个字符放入 str
	{
		str.data[k - i + 1] = s.data[k];
	}

	str.length = j;

	return str;
}

//将 t 插入到 s 的第 i 个位置上，返回产生的结果串，若参数不正确，返回空串
SqString insStr(SqString s, int i, SqString t) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length + 1)
	{
		return str;
	}

	int j;

	for (j = 0; j < i - 1; j++) //先把 s 中从第 1 个字符到第 i - 1 个字符放入 str
	{
		str.data[j] = s.data[j];
	}

	for (j = 0; j < t.length; i++) //再把 t 中的所有字符放入 str
	{
		str.data[i + j - 1] = t.data[j];
	}

	for (j = i - 1; j < s.length; i++) //再把 s 中从第 i 个字符到最后一个字符放入 str 
	{
		str.data[t.length + j] = s.data[j];
	}

	str.length = s.length + t.length;

	return str;
}

//在 s 中删除从第 i 个字符开始，连续 j 个的字符的子串，返回新的串，当参数不正确时，返回空串
SqString delStr(SqString s, int i, int j) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; i++) //先把 s 中从第 1 个字符到第 i - 1 个字符放入 str
	{
		str.data[k] = s.data[k];
	}

	for (k = i + j - 1; k < s.length; k++) //再把 s 中从第 i + j 个字符到最后一个字符放入 str
	{
		str.data[k - j] = s.data[k];
	}

	str.length = s.length - j;

	return str;
}


//子串的替换，将 s 中从第 i 个字符开始的连续 j 个字符构成的子串替换为 t，若参数不正确，返回空串
SqString repStr(SqString s, int i, int j, SqString t) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++) //先把 s 中从第 1 个字符到第 i - 1 个字符放入 str
	{
		str.data[k] = s.data[k];
	}

	for (k = 0; k < t.length; k++) //再把 t 中的所有字符放入 str
	{
		str.data[i + k - 1] = t.data[k];
	}

	for (k = i + j - 1; k < s.length; k++) //再把 s 中从第 i + j 个字符到最后一个字符放入 str
	{
		str.data[t.length + k - j] = s.data[k];
	}

	str.length = s.length - j + t.length;

	return str;
}

//输出串
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

	strAssign(s1, str1); //S 由一个字符数组 data 和 一个整型 length 组成，S.data 中不包括 \0

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