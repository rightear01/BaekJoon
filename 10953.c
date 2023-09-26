#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int testCase,numA, numB;
	// scanf()의 더블쿼테이션 안에 구분자를 설정하여 해당 문자를 무시할 수 있다.
	scanf(" %d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d, %d", &numA, &numB);
		printf("%d\n", numA + numB);
	}
	return 0;
}