#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int treesNum, wannaHeight, optCutHeight;
long long temp = 0;

int compare(const void* first, const void* second) {
    int x = *(int*)first;
    int y = *(int*)second;
    if (x > y) return 1;
    else return 0;
}

int calcurateOpt(int* treesArr, int begin, int end) {
    if (begin > end) { return; } // ������ �ߴ��ϴ� �ߴ���.(������ �߰�)
    int middle = (begin + end) / 2;
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
    scanf("%d %d", &treesNum, &wannaHeight);
    int* treeArr = (int*)malloc(sizeof(int) * treesNum);
    for (int i = 0; i < treesNum; i++) { scanf("%d", &treeArr[i]); }
    qsort(treeArr, treesNum, sizeof(int), compare);
    calcurateOpt(treeArr, 0, treeArr[treesNum - 1]);
    // Ž���� �����ϴ� ���� ����� ���� ������ ������ �̿��Ͽ�, 0 ~ �ش� �迭�� �ִ����� ����
    printf("%d", optCutHeight);
    free(treeArr);
}