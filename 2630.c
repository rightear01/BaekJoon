#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cPaper[128][128];
int blue = 0, white = 0;

void divide(int width, int height, int mid);

int main() {
	int rowNum;
	scanf("%d", &rowNum);

	// # ���� ���� #
	// 2���� �迭�� ������ 0 �Ͼ�� 1�Ķ����� �Է�
	// ���ϴ� ���� ����� �߷��� �Ķ��� ���̿� �Ͼ�� ������ �����̴�.

	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < rowNum; j++) {
			scanf("%d", &cPaper[i][j]);
		}
	}

	divide(0, 0, rowNum);
	printf("%d\n%d", white, blue);

	return 0;
}

void divide(int width, int height, int length) {
	int  validation = 0;
	if (length < 0) { return; }

	//---------------------- Full Search ----------------------//
	for (int i = height; i < height + length; i++) {							// Row
		for (int j = width; j < width + length; j++) {						// Column
			if (cPaper[i][j] == 1) { validation++; }								// Blue Check
		}
	}
	//----------------------------------------------------------//

	if (validation == length * length) {							// All Blue Case
		blue++;
		return;
	}
	else if (validation == 0) {										// All White Case
		white++;
		return;
	}
	else {																	// Validation failure Case --> divide
		int mid = length / 2;
		//	Quarter
		divide(width, height, mid);
		divide(width + mid, height, mid);
		divide(width, height + mid, mid);
		divide(width + mid, height + mid, mid);
	}

	return;
}