#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
해당 문제는 주어진 두 분수를 합하고 해당 결과가 기약분수로 표현될 수 있게 하는 것이다.

필자는 일단 분모끼리 곱해 공통 분모를 만들어 계산하고 결과의 분자와 분모의 최대 공약수를
유클리드 호제법을 이용하여 구한 뒤 분자와 분모를 약분해 기약분수를 구하는 방식으로 문제를 풀이하였다.
*/
typedef struct {
	int molecule;
	int denominator;
}Fountain;

int GCD(int a, int b);

int main() {
	Fountain group[3];
	int gcd = 0;
	for (int i = 0; i < 2; i++) { scanf("%d %d", &group[i].molecule, &group[i].denominator); }
	group[2].denominator = group[0].denominator * group[1].denominator;
	group[2].molecule = (group[0].molecule * group[1].denominator) + (group[1].molecule * group[0].denominator);
	int max_num = (group[2].molecule < group[2].denominator) ? group[2].denominator : group[2].molecule;
	if (max_num == group[2].molecule) { gcd = GCD(group[2].molecule, group[2].denominator); }
	else { gcd = GCD(group[2].denominator, group[2].molecule); }
	group[2].denominator /=  gcd; group[2].molecule /= gcd;
	printf("%d %d", group[2].molecule, group[2].denominator);

	return 0;
}

int GCD(int a, int b) {
	int r = 0;
	while (1) {
		r = a % b;
		if (r == 0) break;
		a = b;
		b = r;
	}
	return b;
}