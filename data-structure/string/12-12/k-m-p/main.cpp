#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef struct SqString {
	char data[MaxSize];
	int length;
};

typedef struct LinkNode {
	char data;
	struct LinkNode* next;
};

void createSqString(SqString& s, char str[]) {
	int k;

	for (k = 0; str[k] != '\0'; k++)
	{
		s.data[k] = str[k];
	}

	s.length = k;
}

void createLinkString(LinkNode*& s, char str[]) {
	s = (LinkNode*)malloc(sizeof(LinkNode));

	LinkNode* p, * r;

	r = s;

	for (int k = 0; str[k] != '\0'; k++)
	{
		p = (LinkNode*)malloc(sizeof(LinkNode));
		p->data = str[k];
		r->next = p;
		r = p;
	}

	r->next = NULL;
}

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
	char s1[] = "aabccdee";

	char s2[] = "de";

	SqString str1, str2;

	createSqString(str1, s1);

	createSqString(str2, s2);

	int index = KMP(str1, str2);

	return 0;
}
