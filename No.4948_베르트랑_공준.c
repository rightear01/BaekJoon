#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 246913
int numArr[SIZE]; // ���� �迭�̱� ������ �ڵ� 0���� �ʱ�ȭ �Ǿ�����.

// ����Ʈ�� ������ ������ �ڿ��� n�� ���Ͽ�, n���� ũ��, 
// 2n���� �۰ų� ���� �Ҽ��� ��� �ϳ� �����Ѵٴ� ������ ��� �ִ�.
// �ڿ��� n�� �־����� ��, n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ������
// ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
/*
���ٹ�
�Ҽ��� ������ �������ִ�. -> �����佺�׳׽��� ü
������ (1 <= N <= 123456)(��� ������ N + 1 ~ 2N)
�ִ� ������ ���� �ʱ� ������ �������� �����ϰ� �����佺�׳׽��� ü�� �̿��Ͽ�
�Ҽ��� üũ�Ͽ���.
���� �Է¹��� N�� �̿��Ͽ� N + 1���� 2N������ �Ҽ��� ī��Ʈ�Ͽ� ����Ѵ�.
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