#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
좌표가 정해지고 공유기의 개수가 정해졌을 때에 공유기 사이 거리가 최대가 되는 간격을 구하면 되는 문제이다.
공유기 사이의 거리 중 최댓값이 아닌, 최대의 거리를 구하였을 때에 그 중에서 최솟값을 구하는 것이다.

공유기 사이의 거리가 최대가 되기 위해서는 좌표들 중에 가장 처음 나오는 좌표에는 항상 공유기를 설치해주는 것이 옳다고 생각한다.
끝에 공유기를 디폴트로 주게 된다면, 끝에 주는 것 보다 주지 않는 것이 최대 거리를 가지게 되는 수가 발생할 수 있다.

이후에 해당 거리를 구하는 방식은 이분탐색에 탐색해야 할 바운더리를 전체 좌표의 최소와 공유기 사이의 최대 거리를 주어
해당 거리를 조절하는 방식으로 진행한다.
*/

int* coordinateArr;
int optBtweenDistance, houseNum, routerNum;
int compare(const void* first, const void* second) { return *(int*)first - *(int*)second; }

// 초깃값 = 1, 최대로 가질 수 있는 거리
void optimalRouterDis(int* coordinateArr, int begin, int end) { 
    while (begin <= end) {
        int middleDis = (begin + end) / 2; 
        int routerCnt = 1, tempDis = 0, startRouter = coordinateArr[0];

        for (int i = 1; i < houseNum; i++) {
            tempDis = coordinateArr[i] - startRouter; // 라우터 사이의 거리를 계산 후 기준점으로 잡았던 middle 값과 비교
            if (middleDis <= tempDis) {
                ++routerCnt;
                startRouter = coordinateArr[i];
            }
        }
     
        if (routerCnt >= routerNum) { // 정해진 라우터의 개수보다 크거나 같다? ==> 간격을 넓혀 라우터의 갯수를 감소시킴
            optBtweenDistance = middleDis;
            begin = middleDis + 1;
        }
        else { end = middleDis - 1; }   // 정해진 라우터의 개수보다 작다? ==> 간격을 넓혀 라우터의 갯수를 증가시킴
    }
}

int main() {
    scanf(" %d %d", &houseNum, &routerNum);
    coordinateArr = (int*)malloc(sizeof(int) * houseNum);
    for (int i = 0; i < houseNum; i++) { scanf(" %d", &coordinateArr[i]); }
    qsort(coordinateArr, houseNum, sizeof(int), compare);
    optimalRouterDis(coordinateArr, 1, (coordinateArr[houseNum - 1] - coordinateArr[0]));
    printf("%d", optBtweenDistance);

    return 0;
}