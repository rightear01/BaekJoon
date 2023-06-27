#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
�ش� ������ �־��� �� �м��� ���ϰ� �ش� ����� ���м��� ǥ���� �� �ְ� �ϴ� ���̴�.

���ڴ� �ϴ� �и𳢸� ���� ���� �и� ����� ����ϰ� ����� ���ڿ� �и��� �ִ� �������
��Ŭ���� ȣ������ �̿��Ͽ� ���� �� ���ڿ� �и� ����� ���м��� ���ϴ� ������� ������ Ǯ���Ͽ���.
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