#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
들어오는 문자열의 각 원소를 아스키 코드로 구분하여 해당되는 값을 누적해 가중치를 계산하였다.
각 문자로 가는 시간은 문자의 개수로 계산해서 더했다.
*/
int main() {
	int ctr = 0;
	char abcArray[12];
	scanf("%s", abcArray);

	for (int i = 0; i < (int)strlen(abcArray); i++) {
		if ((int)abcArray[i] >= 65 && (int)abcArray[i] <= 67) { ctr += 2; }
		if ((int)abcArray[i] >= 68 && (int)abcArray[i] <= 70) { ctr += 3; }
		if ((int)abcArray[i] >= 71 && (int)abcArray[i] <= 73) { ctr += 4; }
		if ((int)abcArray[i] >= 74 && (int)abcArray[i] <= 76) { ctr += 5; }
		if ((int)abcArray[i] >= 77 && (int)abcArray[i] <= 79) { ctr += 6; }
		if ((int)abcArray[i] >= 80 && (int)abcArray[i] <= 83) { ctr += 7; }
		if ((int)abcArray[i] >= 84 && (int)abcArray[i] <= 86) { ctr += 8; }
		if ((int)abcArray[i] >= 87 && (int)abcArray[i] <= 90) { ctr += 9; }
	}
	ctr += (int)strlen(abcArray);
	printf("%d", ctr);

	return 0;
}