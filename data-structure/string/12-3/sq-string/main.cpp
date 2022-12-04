#include <stdio.h>

#define MaxSize 5

typedef struct SqString {
	char data[MaxSize];
	int length;
};




int main() {
	char a[] = "12345";

	char b = 'a';

	char c[] = { '1','2' };

	char d[] = { 1,2,3,4,5 };

	return 0;
}