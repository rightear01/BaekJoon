# No11050
# nCk = n! / k!(n-k)!
import sys

N, K = map(int, sys.stdin.readline().split())

result = 1
for _ in range(K):
    result *= N
    N -= 1

div = 1
for num in range(2, K + 1):
    div *= num

print(result // div)
# // : 연산자는 나누기 연산을 수행하고 그 결과를 소수점 이하를 버리고 정수 부분만을 반환함.