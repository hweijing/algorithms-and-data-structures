#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main() {
	int year;

	scanf("%d", &year);

	if (year >= 100 && year % 100 == 0) {
		if (year % 400 == 0) {
			printf("闰年");
		} else {
			printf("平年");
		}
	} else {
		if (year % 4 == 0) {
			printf("闰年");
		} else {
			printf("平年");
		}
	}
}