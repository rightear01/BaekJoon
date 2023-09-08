#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

///**********************///
///*      DFS 알고리즘        *///
///**********************///
/// DFS 알고리즘은 Depth-First Search 깊이우선 탐색(스택을 이용한 완전 탐색)으로
/// 그래프나 트리와 같은 자료 구조에서 사용되는 알고리즘 중 하나로,
/// 시작 노드(혹은 루트 노드)에서 출발하여 다음 노드(Val 작은)로 이동하는
/// 과정을 재귀적으로 진행하면서 탐색을 수행하는 알고리즘이다.
/// 보통 자료구조의 Stack 또는 재귀 함수를 통해 구현이 된다.
/// 

int boundary, depth; // 수의 범위, 깊이 
int dfsArr[8];

void DepthFirstSerach(int target, int last) {
	if (target == depth) {
		// 재귀호출을 통하여, 이후에 num이 한계선 까지 도달한다면.
		for (int i = 0; i < depth; i++) printf("%d ", dfsArr[i] + 1);
		// 0 ~ M(깊이) 까지 출력
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