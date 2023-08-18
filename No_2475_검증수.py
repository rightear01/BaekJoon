import sys

verNum = 0
for n in map(int, sys.stdin.readline().split()):
    verNum += n**2
    print(f'list >> {n}')

print(verNum % 10)