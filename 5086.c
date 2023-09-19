#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* 접근법
* 두 수가 주어졌을 때, 다음 3가지 중 어떤 관계인지 구하는 프로그램을 작성하시오.
						첫 번째 숫자가 두 번째 숫자의 약수이다.
						첫 번째 숫자가 두 번째 숫자의 배수이다.
						첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다.
						각 테스트 케이스마다 첫 번째 숫자가 두 번째 숫자의 약수라면 factor를,
						배수라면 multiple을, 둘 다 아니라면 neither를 출력한다.
						마지막 줄에는 0이 2개 주어진다. 두 수가 같은 경우는 없다.(break)
*/

int main() {
	int numA, numB;
	while (1) {
		scanf("%d %d", &numA, &numB);
		if (numA == 0 && numB == 0) { break; }
		if (numB % numA == 0) { printf("factor\n"); }
		else if (numA % numB == 0) { printf("multiple\n"); }
		else { printf("neither\n"); }
	}

	return 0;
}