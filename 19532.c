#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
접근법
연립방정식을 푸는 문제이다.
ax + by = c
dx + ey = f
각 칸에는 -999 ~ 999 사이의 수를 입력할 수 있다.
*/

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	int y = (c * d - a * f) / (b * d - a * e);
	int x = (c * e - b * f) / (a * e - b * d);

	printf("%d %d\n", x, y);
	return 0;
}