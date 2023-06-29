#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
이미 심어져 있는 가로수들의 거리가 일정하게 나무를 심기 위해서는
현재 심어져있는 나무들의 좌표들 사이가 일정해야 한다. 따라서
사이의 최대 공약수를 구해 일정한 간격으로 나무가 배치될 수 있도록 한다.

또한 처음과 마지막 나무 사이의 거리를 최대 공약수로 나누어 주고 +1(마지막 나무)을 
해준다면, 해당 최대 공약수를 배율로 삼아 새로 배치되는 나무수를 포함한 전체 나무의 수를 구할 수 있다.
이후 전체 나무의 수에서 미리 배정받은 나무의 수를 빼주면 답이 나오게 된다.
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