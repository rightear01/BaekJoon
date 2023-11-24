#define _CRT_SECURE_NO_WARNINGS
#define HEAPSIZE 100000
#include <stdio.h>
#include <stdlib.h>

int maxHeap[HEAPSIZE];
int heapIdx = 0;

void swap(int* numA, int* numB) {
	int temp = *numA;
	*numA = *numB;
	*numB = temp;
}

void push(int data) {
	int idx = ++heapIdx;

	while ((idx != 1) && (data > maxHeap[idx / 2])) {
		maxHeap[idx] = maxHeap[idx / 2];
		idx /= 2;
	}
	maxHeap[idx] = data;
}

int pop() {
	if (heapIdx == 0)
		return 0;
	int value = maxHeap[1];
	maxHeap[1] = maxHeap[heapIdx--];
	int parent = 1;
	int child;

	while (1) {
		child = parent * 2;
		if (child + 1 <= heapIdx && maxHeap[child] < maxHeap[child + 1])
			child++;

		if (child > heapIdx || maxHeap[child] < maxHeap[parent])
			break;

		swap(&maxHeap[parent], &maxHeap[child]);
		parent = child;
	}

	return value;

}

int main() {
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int commandOrNum; scanf("%d", &commandOrNum);
		if (commandOrNum == 0) { printf("%d\n", pop()); }
		else {
			push(commandOrNum);
		}
	}
}