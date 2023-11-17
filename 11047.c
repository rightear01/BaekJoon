#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main() {
    int coinNum, totalPrice, sumCoin = 0, count = 0, idx;
    scanf("%d %d", &coinNum, &totalPrice); idx = coinNum - 1;
    int* coinArr = (int*)malloc(sizeof(int) * coinNum);
    for (int i = 0; i < coinNum; i++) { scanf("%d", &coinArr[i]); }

    while (totalPrice != sumCoin) {
        if (totalPrice - coinArr[idx] >= 0 && totalPrice >= sumCoin + coinArr[idx]) {
            sumCoin += coinArr[idx];
            count++;
            idx = coinNum - 1;
        }
        else { idx--; }
    }
    printf("%d", count);
}