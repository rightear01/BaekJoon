#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
* ParametricSearch
파라메트릭 서치는 이분 탐색과 매우 유사하다.
하지만 파라메트릭 서치와 이분 타색의 차이점이 있는데
파라메트릭 서치는 '최적화 문제를 결정 문제로 바꾸어 푸는 것이다.'
파라매트릭 서치로 인해 정답 후보가 나타나면, 연속적으로 정답 후보가
나타난다.
*/

int compare(const void* first, const void* second) {
    int x = *(int*)first;
    int y = *(int*)second;
    if (x > y) return 1;
    else return 0;
}

int main() {
    int lanCableNum, wannaGet;
    short int lanNumCnt = 0;
    unsigned long optCutLen;

    scanf("%d %d", &lanCableNum, &wannaGet);
    int* lanCableArr = (int*)malloc(sizeof(int) * lanCableNum);
    for (int i = 0; i < lanCableNum; i++) scanf("%d", &lanCableArr[i]);
    qsort(lanCableArr, lanCableNum, sizeof(int), compare);
    unsigned int begin = 0;
    unsigned int end = lanCableArr[lanCableNum - 1];

    while (begin <= end) {
        unsigned long middle = (begin + end) / 2;
        int tempLanNum = 0;
        for (int i = 0; i < lanCableNum; i++) {
            tempLanNum += lanCableArr[i] / middle;
        }
        if (tempLanNum >= wannaGet) {
            optCutLen = middle;
            begin = middle + 1;
        }
        else { end = middle - 1; }
    }

    printf("%lu", optCutLen);
    free(lanCableArr);
    
    return 0;
}