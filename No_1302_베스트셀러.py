import sys

sellNum = int(sys.stdin.readline())
bookList = {}

for _ in range(sellNum):
    bookName = input()
    if bookName in bookList:
        bookList[bookName] += 1
    else:
        bookList[bookName] = 1

maxSeller = max(bookList.values())
bookList2 = sorted(bookList.items(), key=lambda x: (-x[1], x[0]))
# 정렬기준 1. -x[1] = 판매부수의 내림차순
# 정렬기준 2. x[0] = 책 제목의 사전상 오름차순

print(bookList2[0][0])