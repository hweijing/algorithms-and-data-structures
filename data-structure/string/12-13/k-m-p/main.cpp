#include <stdio.h>

#define MaxSize 10

typedef struct SqString {
	char data[MaxSize];
	int length;
};

void getNext(SqString t, int next[]) {
	int j = 0, k = -1;

	next[j] = k;

	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(SqString s, SqString t) {
	int next[MaxSize], i = 0, j = 0;

	getNext(t, next);

	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
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