#include <stdio.h>

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

void destroySqString() {

}

int lengthSqString(SqString s) {
	return s.length;
}

void dispSqString(SqString s) {
	for (int i = 0; i < s.length; i++)
	{
		printf("%c", s.data[i]);
	}
}

void copySqString(SqString& s, SqString t) {
	for (int i = 0; i < t.length; i++)
	{
		s.data[i] = t.data[i];
	}

	s.length = t.length;
}

bool equalSqString(SqString s, SqString t) {
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

SqString concatSqString(SqString s, SqString t) {
	SqString str;

	int k;

	for (k = 0; k < s.length; k++)
	{
		str.data[k] = s.data[k];
	}

	for (k = 0; k < t.length; k++)
	{
		str.data[s.length + k] = t.data[k];
	}

	str.length = s.length + t.length;

	return str;
}

SqString subSqString(SqString s, int i, int j) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || j < 0 || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = i - 1; k < i + j - 1; k++)
	{
		str.data[k - i + 1] = s.data[k];
	}

	str.length = j;

	return str;
}

SqString insSqString(SqString s, int i, SqString t) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length + 1)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}

	for (k = 0; k < t.length; k++)
	{
		str.data[k + i - 1] = t.data[k];
	}

	for (k = i - 1; k < s.length; k++)
	{
		str.data[t.length + k] = s.data[k];
	}

	str.length = s.length + t.length;

	return str;
}

SqString delSqString(SqString s, int i, int j) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || j < 0 || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}

	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[k - j] = s.data[k];
	}

	str.length = s.length - j;

	return str;
}

SqString repSqString(SqString s, int i, int j, SqString t) {
	SqString str;

	str.length = 0;

	if (i < 1 || i > s.length || j < 0 || i + j - 1 > s.length)
	{
		return str;
	}

	int k;

	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}

	for (k = 0; k < t.length; k++)
	{
		str.data[i + k - 1] = t.data[k];
	}

	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[t.length + k - j] = s.data[k];
	}

	str.length = s.length - j + t.length;

	return str;
}

int main() {
	return 0;
}