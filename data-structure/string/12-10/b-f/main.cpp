#include<stdio.h>

#define MaxSize 10

typedef struct SqString {
	char data[MaxSize];
	int length;
};

void createSqString(SqString& s, char str[]) {
	int i = 0;

	while (str[i] != '\0')
	{
		s.data[i] = str[i];
		i++;
	}

	s.length = i;
}

int BF(SqString s, SqString t) {
	int i = 0, j = 0;

	while (i < s.length && j < t.length)
	{
		if (s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (j >= t.length)
	{
		return i - t.length;
	}

	return -1;
}

int main() {
	char str1[] = "abcde";

	char str2[] = "cde";

	char str3[] = "cdefg";

	SqString s1, s2, s3;

	createSqString(s1, str1);

	createSqString(s2, str2);

	createSqString(s3, str3);

	int locate;

	//2
	locate = BF(s1, s2);

	//-1
	locate = BF(s1, s3);

	return 0;
}