#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000001
#include <stdio.h>
/*
접근법
해당 문제에서 의미하는 바는 이렇다.
범위내의 짝수가 주어지면( 1 < n <= 1000000 )
 해당 수를 두 소수의 합으로 나타내는 것이다.
 필자는 먼저 에라토스테네스의 체를 이용하여
 해당 범위내의 모든 소수를 배열로 표현하였고
 계산상 편의를 위하여 소수 2가 중복되어 표현되는 4는
 바로 출력하게 두었으며, 3부터 2씩 증가하며 배열을 검사하는데
 검사 방법은 해당 소수를 입력받은 값에서 빼주고 그 값 또한 소수인지
 검사하는 방법으로 계산하였다. 둘 다 소수이면 조건에 만족하기 때문.
*/
int EratosArr[SIZE];
void Eratos();

int main() {
	Eratos();

	int testCase, num;
	scanf("%d", &testCase);

	while (testCase--) {
		scanf("%d", &num);
		if (num == 4) {
			printf("%d\n", 1);
			continue;
		}
		int ctr = 0;
		for (int i = 3; i <= num / 2; i += 2) {
			if (!EratosArr[i] && !EratosArr[num - i]) ctr++;
			// 해당 소수와 입력값에서 뺀 값 또한 소수이면
			// 조건이 만족하기에 카운트한다.
		}
		printf("%d\n", ctr);
	}
	return 0;
}

void Eratos() {
	for (int i = 2; i * i < SIZE; i++) {
		if (!EratosArr[i])
			for (int j = i * i; j < SIZE; j += i)
				EratosArr[j] = 1;
	}
}