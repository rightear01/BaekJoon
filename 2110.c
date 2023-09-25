#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
��ǥ�� �������� �������� ������ �������� ���� ������ ���� �Ÿ��� �ִ밡 �Ǵ� ������ ���ϸ� �Ǵ� �����̴�.
������ ������ �Ÿ� �� �ִ��� �ƴ�, �ִ��� �Ÿ��� ���Ͽ��� ���� �� �߿��� �ּڰ��� ���ϴ� ���̴�.

������ ������ �Ÿ��� �ִ밡 �Ǳ� ���ؼ��� ��ǥ�� �߿� ���� ó�� ������ ��ǥ���� �׻� �����⸦ ��ġ���ִ� ���� �Ǵٰ� �����Ѵ�.
���� �����⸦ ����Ʈ�� �ְ� �ȴٸ�, ���� �ִ� �� ���� ���� �ʴ� ���� �ִ� �Ÿ��� ������ �Ǵ� ���� �߻��� �� �ִ�.

���Ŀ� �ش� �Ÿ��� ���ϴ� ����� �̺�Ž���� Ž���ؾ� �� �ٿ������ ��ü ��ǥ�� �ּҿ� ������ ������ �ִ� �Ÿ��� �־�
�ش� �Ÿ��� �����ϴ� ������� �����Ѵ�.
*/

int* coordinateArr;
int optBtweenDistance, houseNum, routerNum;
int compare(const void* first, const void* second) { return *(int*)first - *(int*)second; }

// �ʱ갪 = 1, �ִ�� ���� �� �ִ� �Ÿ�
void optimalRouterDis(int* coordinateArr, int begin, int end) { 
    while (begin <= end) {
        int middleDis = (begin + end) / 2; 
        int routerCnt = 1, tempDis = 0, startRouter = coordinateArr[0];

        for (int i = 1; i < houseNum; i++) {
            tempDis = coordinateArr[i] - startRouter; // ����� ������ �Ÿ��� ��� �� ���������� ��Ҵ� middle ���� ��
            if (middleDis <= tempDis) {
                ++routerCnt;
                startRouter = coordinateArr[i];
            }
        }
     
        if (routerCnt >= routerNum) { // ������ ������� �������� ũ�ų� ����? ==> ������ ���� ������� ������ ���ҽ�Ŵ
            optBtweenDistance = middleDis;
            begin = middleDis + 1;
        }
        else { end = middleDis - 1; }   // ������ ������� �������� �۴�? ==> ������ ���� ������� ������ ������Ŵ
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