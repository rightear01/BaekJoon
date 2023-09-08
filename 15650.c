#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

///**********************///
///*      DFS �˰���        *///
///**********************///
/// DFS �˰����� Depth-First Search ���̿켱 Ž��(������ �̿��� ���� Ž��)����
/// �׷����� Ʈ���� ���� �ڷ� �������� ���Ǵ� �˰��� �� �ϳ���,
/// ���� ���(Ȥ�� ��Ʈ ���)���� ����Ͽ� ���� ���(Val ����)�� �̵��ϴ�
/// ������ ��������� �����ϸ鼭 Ž���� �����ϴ� �˰����̴�.
/// ���� �ڷᱸ���� Stack �Ǵ� ��� �Լ��� ���� ������ �ȴ�.
/// 

int boundary, depth; // ���� ����, ���� 
int dfsArr[8];

void DepthFirstSerach(int target, int last) {
	if (target == depth) {
		// ���ȣ���� ���Ͽ�, ���Ŀ� num�� �Ѱ輱 ���� �����Ѵٸ�.
		for (int i = 0; i < depth; i++) printf("%d ", dfsArr[i] + 1);
		// 0 ~ M(����) ���� ���
		printf("\n");
	}
	else {
		for (int i = last; i < boundary; i++) {
			dfsArr[target] = i;
			DepthFirstSerach(target + 1, i + 1);
		}
	}
}

int main() {
	scanf("%d %d", &boundary, &depth);
	DepthFirstSerach(0, 0);
	return 0;
}