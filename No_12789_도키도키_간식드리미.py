import sys

standingNum = int(sys.stdin.readline())      # 몇명이 대기하고 있는가
rightStack = list(map(int, sys.stdin.readline().split())) # 우측 통로
downStack = list()                                        # 밑쪽 통로
minNumber = sorted(rightStack)[0]                         # 번호의 최소
'''
Ex)
IDX 0   1   2   3   4 
VAL 5   4   1   3   2 
'''
while rightStack:
    if rightStack[0] != minNumber:          # 줄에서 가장 작은 번호가 아니라면
        downStack.append(rightStack.pop(0)) # 스택의 팝 연산을 리스트에서 구현
    else:                                   # 가장 작은 번호라면
        rightStack.pop(0)
        minNumber += 1

while downStack:
    if downStack[-1] == minNumber:
        downStack.pop(-1)
        minNumber += 1
    else : break

print('Nice' if not downStack else 'Sad')
# 모든 연산 수행 후에 downStack에 값이 남아있다면, 밑의 통로에 내림차순 번호로 정렬되어 있지 않다는 의미.