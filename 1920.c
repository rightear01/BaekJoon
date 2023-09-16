#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
/*기본적인 이진탐색을 이용하여 풀이하는 문제이다.*/

int compare(const void* first, const void* second) {
	int x = *(int*)first; int y = *(int*)second;
	if (x > y) return 1;
	else return 0;
}

int binarySearch(int* array, int begin, int end, int key) {
	int middle = (begin + end) / 2;
	if (key == array[middle]) return 1;
	else if (key < array[middle] && (middle - 1 >= begin))
		binarySearch(array, begin, middle - 1, key);
	else if (key > array[middle] && (middle + 1 <= end))
		binarySearch(array, middle + 1, end, key);
	else return 0;
}

int main() {
	int eleNum1, eleNum2;
	scanf(" %d", &eleNum1);
	int* sArray = (int*)malloc(sizeof(int) * eleNum1);
	for (int i = 0; i < eleNum1; i++) { scanf(" %d", &sArray[i]); }
	qsort(sArray, eleNum1, sizeof(int), compare);

	scanf(" %d", &eleNum2);
	int* cArray = (int*)malloc(sizeof(int) * eleNum2);
	for (int i = 0; i < eleNum2; i++) { scanf(" %d", &cArray[i]); }

	for (int i = 0; i < eleNum2; i++) {
		if (binarySearch(sArray, 0, eleNum1 - 1, cArray[i]) == 1) { printf("1\n"); }
		else { printf("0\n"); }
	}
	return 0;
}