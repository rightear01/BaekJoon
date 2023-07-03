#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000001
int numArr[SIZE]; // 전역 배열이기 때문에 자동 0으로 초기화 되어있음.

/*
접근법
소수의 범위가 정해져있다. -> 에라토스테네스의 체
범위는 (1 <= N <= M <= 1000000)
출력은 내림차순으로 출력한다.
*/
void Eratos(int start, int end);
int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	numArr[1] = 1;
	// -> 입력으로 들어오는 범위에 1이 있으면 초깃값이 0이기 때문에
	// 출력된다. 따라서 해당 방을 바꾸어 출력을 막는다.
	Eratos(start, end);

	return 0;
}

void Eratos(int start, int end) {
	if (start == end) {
		if (start == 1) return;
		if (end == 2) {
			printf("%d\n", end);
			return;
		}
		if (end % 2 == 0) return;
		for (unsigned int i = 3; i * i <= end; i += 2) {
			if (end % i == 0) return;
		}
		printf("%d\n", end);
		return;
	}

	for (int i = 2; i * i <= end; i++) {
		if (!numArr[i])
			for (int j = i * i; j <= end; j += i)
				numArr[j] = 1;
	}

	for (int i = start; i <= end; i++) {
		if (!numArr[i]) printf("%d\n", i);
	}
}