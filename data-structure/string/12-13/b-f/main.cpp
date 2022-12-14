#include <stdio.h>

#define MaxSize 10

typedef struct SqString {
	char data[MaxSize];
	int length;
};

int BF(SqString s, SqString t) {
	int i = 0, j = 0;

	while (i < s.length && j < t.length)
	{
		if (s.data[i] = t.data[j])
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
	return 0;
}