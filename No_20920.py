import sys, operator

wordNum, wordLen = map(int, sys.stdin.readline().split())
strDict = dict()

for _ in range(wordNum):
    word = sys.stdin.readline().rstrip()
    if len(word) < wordLen: continue
    if word in strDict: strDict[word] += 1
    else: strDict[word] = 1
# 딕셔너리를 선언하여, 문자열을 key로 문자열의 등장 횟수를 val으로 지정함.
'''
문자열 정렬 조건
자주 나오는 단어일수록 앞에 배치한다.
해당 단어의 길이가 길수록 앞에 배치한다.
알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
'''
sortedStrDict = dict(sorted(strDict.items(),
                            key = lambda item: (-item[1], -len(item[0]), item[0])))
# key = lambda item: (-item[1], -len(item[0]), item[0])))
# 자주 나오는 단어일수록 앞에 배치한다, 해당 단어의 길이가 길수록 앞에 배치한다, 
# 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다 

for key in sortedStrDict.keys(): print(key)