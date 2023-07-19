#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* array, int begin, int end, int key) {
	int middle = (begin + end) / 2;
	if (key == array[middle]) return 1;
	else if (key < array[middle] && (middle - 1 >= begin))
		binarySearch(array, begin, middle - 1, key);
	else if (key > array[middle] && (middle + 1 <= end))
		binarySearch(array, middle + 1, end, key);
	else return 0;
}

int compare(const void* first, const void* second) {
	return *(int*)first - *(int*)second;
}

int main() {
	int elements1, elements2;
	scanf("%d", &elements1);
	int* sArray = (int*)malloc(sizeof(int) * elements1); // 상근
	for (int i = 0; i < elements1; i++) { scanf(" %d", &sArray[i]); }
	qsort(sArray, elements1, sizeof(int), compare);

	scanf("%d", &elements2);
	int* cArray = (int*)malloc(sizeof(int) * elements2); // 비교군

	for (int i = 0; i < elements2; i++) { scanf(" %d", &cArray[i]); }
	for (int i = 0; i < elements2; i++) {
		if (binarySearch(sArray, 0, elements1 - 1, cArray[i])) printf("1 ");
		else printf("0 ");
	}


	return 0;
}