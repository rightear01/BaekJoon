#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int treesNum;
long long optCutHeight, wannaHeight, temp = 0;

int compare(const void* first, const void* second) {
    long long x = *(long long*)first;
    long long y = *(long long*)second;
    if (x > y) return 1;
    else return 0;
}

long long calcurateOpt(long long* treesArr, long long begin, long long end) {
    if (begin > end) { return; }
    long long middle = (begin + end) / 2;
    // �迭�� ��ü�� �߾Ӱ����� ����
    temp = 0;
    for (int i = 0; i < treesNum; i++) {
        if (treesArr[i] > middle) { temp += treesArr[i] - middle; }
        // ��ü �迭���� �߾Ӱ����� ū ������ ����Ͽ� middle�� ������ �������� ���.
    }

    if (temp >= wannaHeight) { 
        // temp���� wannaHeight���� ũ�ų� ���ٴ� �ǹ̴� middle�� ������ ���ܱ� ���̶�� ��.
        optCutHeight = middle; 
        return calcurateOpt(treesArr, middle + 1, end);
        // �� ���� ���� ã�ƺ���.(���� ����)
    }
    else { return calcurateOpt(treesArr, begin, middle - 1); }
    // ���� �� ���� �������� ã�� ����.(���)
}

int main() {
    scanf("%d %lld", &treesNum, &wannaHeight);
    long long* treeArr = (long long*)malloc(sizeof(long long) * treesNum);
    for (int i = 0; i < treesNum; i++) { scanf("%lld", &treeArr[i]); }
    qsort(treeArr, treesNum, sizeof(long long), compare);
    calcurateOpt(treeArr, 0, treeArr[treesNum - 1]);
    // Ž���� �����ϴ� ���� ����� ���� ������ ������ �̿��Ͽ�, 0 ~ �ش� �迭�� �ִ����� ����
    printf("%lld", optCutHeight);
    free(treeArr);
}