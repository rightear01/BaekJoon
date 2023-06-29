#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isPrime(unsigned int num) {
	if (num < 2) return 0;   // 0과 1은 소수가 아님
	if (num == 2) return 1;  // 2는 소수
	if (num % 2 == 0) return 0;  // 짝수는 소수가 아님
	//  i * i <= num --> num의 제곱근 까지만 계산되도록 조건을 세움
	// i += 2 --> 짝수는 2를 제외하면 소수가 될 수 없으므로, 홀수만 계산하기 위함.
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