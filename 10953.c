#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int testCase,numA, numB;
	// scanf()�� ���������̼� �ȿ� �����ڸ� �����Ͽ� �ش� ���ڸ� ������ �� �ִ�.
	scanf(" %d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d, %d", &numA, &numB);
		printf("%d\n", numA + numB);
	}
	return 0;
}