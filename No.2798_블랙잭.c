#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
���ٹ�
N ���� ī��(����)�� �־������� �ش� ������ �߿���
3���� ���� M���� �۰ų� ���� �ִ밪�� ����Ѵ�.
N(3 <= N <= 100), M(10 <= M <= 300000)

�Է� : N(ī���� ��), M(Max ��)
��� : M�� ���� �����ų� ���� �ִ����� ��

���Ʈ���� �˰���(���� Ž��) -> ��� ����� ���� Ž���Ѵ�.
*/
int main() {
	int cardsNum, maxNum;
	scanf("%d %d", &cardsNum, &maxNum);
	int* cardsArray = (int*)malloc(sizeof(int) * cardsNum);
	for (int i = 0; i < cardsNum; i++) scanf("%d", &cardsArray[i]);
	int blackJackCombination = 0;
	for(int i = 0; i < cardsNum - 2; i++)
		for(int j = i + 1; j < cardsNum - 1; j++)
			for (int k = j + 1; k < cardsNum; k++) {
				int tempCombination = cardsArray[i] + cardsArray[j] + cardsArray[k];
				if (tempCombination <= maxNum && tempCombination > blackJackCombination)
					blackJackCombination = tempCombination;
			}
	printf("%d", blackJackCombination);

	return 0;
}