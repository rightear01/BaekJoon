#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
* ParametricSearch
�Ķ��Ʈ�� ��ġ�� �̺� Ž���� �ſ� �����ϴ�.
������ �Ķ��Ʈ�� ��ġ�� �̺� Ÿ���� �������� �ִµ�
�Ķ��Ʈ�� ��ġ�� '����ȭ ������ ���� ������ �ٲپ� Ǫ�� ���̴�.'
�Ķ��Ʈ�� ��ġ�� ���� ���� �ĺ��� ��Ÿ����, ���������� ���� �ĺ���
��Ÿ����.
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