#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* ���ٹ�
* �� ���� �־����� ��, ���� 3���� �� � �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
						ù ��° ���ڰ� �� ��° ������ ����̴�.
						ù ��° ���ڰ� �� ��° ������ ����̴�.
						ù ��° ���ڰ� �� ��° ������ ����� ��� ��� �ƴϴ�.
						�� �׽�Ʈ ���̽����� ù ��° ���ڰ� �� ��° ������ ������ factor��,
						������ multiple��, �� �� �ƴ϶�� neither�� ����Ѵ�.
						������ �ٿ��� 0�� 2�� �־�����. �� ���� ���� ���� ����.(break)
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