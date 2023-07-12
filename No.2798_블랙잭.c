#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
접근법
N 장의 카드(정수)가 주어졌을때 해당 정수들 중에서
3장의 합이 M보다 작거나 같은 최대값을 출력한다.
N(3 <= N <= 100), M(10 <= M <= 300000)

입력 : N(카드의 수), M(Max 값)
출력 : M과 제일 가깝거나 같은 최대합의 값

브루트포스 알고리즘(완전 탐색) -> 모든 경우의 수를 탐색한다.
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