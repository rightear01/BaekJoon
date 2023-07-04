#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 246913
int numArr[SIZE]; // 전역 배열이기 때문에 자동 0으로 초기화 되어있음.

// 베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 
// 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
// 자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를
// 구하는 프로그램을 작성하시오.
/*
접근법
소수의 범위가 정해져있다. -> 에라토스테네스의 체
범위는 (1 <= N <= 123456)(출력 범위는 N + 1 ~ 2N)
최대 갯수가 많지 않기 때문에 정적으로 선언하고 에라토스테네스의 체를 이용하여
소수를 체크하였다.
이후 입력받은 N을 이용하여 N + 1부터 2N까지의 소수를 카운트하여 출력한다.
*/

void Eratos();
void countEratos(int domain);

int main() {
	int remain = 1, start;
	numArr[1] = 1; Eratos();

	while (remain) {
		scanf("%d", &start);
		if (start == 0) break;
		else { countEratos(start); }
	}
	return 0;
}

void Eratos() {
	for (int i = 2; i * i < SIZE ; i++) {
		if (!numArr[i])
			for (int j = i * i; j < SIZE; j += i)
				numArr[j] = 1;
	}
}

void countEratos(int domain) {
	int ctr = 0;
	for (int i = domain + 1; i <= 2 * domain; i++) {
		if (numArr[i] == 0) ctr++;
	}
	printf("%d\n", ctr);
}