#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000001
int numArr[SIZE]; // ���� �迭�̱� ������ �ڵ� 0���� �ʱ�ȭ �Ǿ�����.

/*
���ٹ�
�Ҽ��� ������ �������ִ�. -> �����佺�׳׽��� ü
������ (1 <= N <= M <= 1000000)
����� ������������ ����Ѵ�.
*/
void Eratos(int start, int end);
int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	numArr[1] = 1;
	// -> �Է����� ������ ������ 1�� ������ �ʱ갪�� 0�̱� ������
	// ��µȴ�. ���� �ش� ���� �ٲپ� ����� ���´�.
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