#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000001
#include <stdio.h>
/*
���ٹ�
�ش� �������� �ǹ��ϴ� �ٴ� �̷���.
�������� ¦���� �־�����( 1 < n <= 1000000 )
 �ش� ���� �� �Ҽ��� ������ ��Ÿ���� ���̴�.
 ���ڴ� ���� �����佺�׳׽��� ü�� �̿��Ͽ�
 �ش� �������� ��� �Ҽ��� �迭�� ǥ���Ͽ���
 ���� ���Ǹ� ���Ͽ� �Ҽ� 2�� �ߺ��Ǿ� ǥ���Ǵ� 4��
 �ٷ� ����ϰ� �ξ�����, 3���� 2�� �����ϸ� �迭�� �˻��ϴµ�
 �˻� ����� �ش� �Ҽ��� �Է¹��� ������ ���ְ� �� �� ���� �Ҽ�����
 �˻��ϴ� ������� ����Ͽ���. �� �� �Ҽ��̸� ���ǿ� �����ϱ� ����.
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
			// �ش� �Ҽ��� �Է°����� �� �� ���� �Ҽ��̸�
			// ������ �����ϱ⿡ ī��Ʈ�Ѵ�.
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