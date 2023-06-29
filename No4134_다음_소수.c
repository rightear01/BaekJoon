#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isPrime(unsigned int num) {
	if (num < 2) return 0;   // 0�� 1�� �Ҽ��� �ƴ�
	if (num == 2) return 1;  // 2�� �Ҽ�
	if (num % 2 == 0) return 0;  // ¦���� �Ҽ��� �ƴ�
	//  i * i <= num --> num�� ������ ������ ���ǵ��� ������ ����
	// i += 2 --> ¦���� 2�� �����ϸ� �Ҽ��� �� �� �����Ƿ�, Ȧ���� ����ϱ� ����.
	for (unsigned int i = 3; i * i  <= num; i += 2) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	unsigned int* decimalArray = (unsigned int*)malloc(sizeof(unsigned int) * testCase);
	for (int i = 0; i < testCase; i++) { scanf("%u", &decimalArray[i]); }
	for (int i = 0; i < testCase; i++) {
		for (unsigned int j = decimalArray[i]; ; j++) {
			if (isPrime(j)) { printf("%u\n", j); break; }
			else continue;
		}
	}
	return 0;
}