#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
�̹� �ɾ��� �ִ� ���μ����� �Ÿ��� �����ϰ� ������ �ɱ� ���ؼ���
���� �ɾ����ִ� �������� ��ǥ�� ���̰� �����ؾ� �Ѵ�. ����
������ �ִ� ������� ���� ������ �������� ������ ��ġ�� �� �ֵ��� �Ѵ�.

���� ó���� ������ ���� ������ �Ÿ��� �ִ� ������� ������ �ְ� +1(������ ����)�� 
���شٸ�, �ش� �ִ� ������� ������ ��� ���� ��ġ�Ǵ� �������� ������ ��ü ������ ���� ���� �� �ִ�.
���� ��ü ������ ������ �̸� �������� ������ ���� ���ָ� ���� ������ �ȴ�.
*/
int GCD(int a, int b);

int main() {
	int preTree, gcd, result, totalTreesNum = 0;
	scanf("%d", &preTree);
	int* treeArray = (int*)malloc(sizeof(int) * preTree);
	int* distanceArray = (int*)malloc(sizeof(int) * (preTree - 1));
	for (int i = 0; i < preTree; i++) { scanf("%d", &treeArray[i]); }
	for (int i = 0; i < preTree - 1; i++) { distanceArray[i] = treeArray[i + 1] - treeArray[i]; }
	gcd = GCD(distanceArray[1], distanceArray[0]);
	for (int i = 2; i < preTree - 1; i++) { gcd = GCD(distanceArray[i], gcd); }
	totalTreesNum = ((treeArray[preTree - 1] - treeArray[0]) / gcd) + 1;
	printf("%d", totalTreesNum - preTree);
	
	return 0;
}

int GCD(int a, int b) {
	int r = 0;
	while (1) {
		r = a % b;
		if (r == 0) break;
		a = b;
		b = r;
	}
	return b;
}