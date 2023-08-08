'''상근이는 세계적인 소프트웨어 회사 기글에서 일한다. 이 회사의 가장 큰 특징은 
자유로운 출퇴근 시간이다. 따라서, 직원들은 반드시 9시부터 6시까지 회사에 있지 않아도 된다.
각 직원은 자기가 원할 때 출근할 수 있고, 아무때나 퇴근할 수 있다.
상근이는 모든 사람의 출입카드 시스템의 로그를 가지고 있다. 이 로그는 어떤 사람이 회사에 들어왔는지,
 나갔는지가 기록되어져 있다. 로그가 주어졌을 때, 현재 회사에 있는 모든 
사람을 구하는 프로그램을 작성하시오.'''

'''첫째 줄에 로그에 기록된 출입 기록의 수 n이 주어진다. (2 ≤ n ≤ 106) 다음 n개의 줄에는 출입 기록이
 순서대로 주어지며, 각 사람의 이름이 주어지고 "enter"나 "leave"가 주어진다. "enter"인 경우는 출근,
   "leave"인 경우는 퇴근이다.

회사에는 동명이인이 없으며, 대소문자가 다른 경우에는 다른 이름이다. 사람들의 이름은 알파벳 대소문자로
 구성된 5글자 이하의 문자열이다.'''

import sys

registeredNum = int(sys.stdin.readline())
regList = dict([]) # dict클래스를 사용하여 사원의 이름과 사원의 출입여부 판별

for _ in range(registeredNum):
    name, state = map(str, sys.stdin.readline().split())
    if state == "enter": 
        regList[name] = state # 입장이면 dict에 저장
    elif state == "leave": 
        del regList[name]   # 같은 이름이 들어오더라도 출입여부 수정함.

regList = sorted(regList.keys(), reverse=True) # 사전 순으로 역순을 취하기 위함.

for i in regList:
    print(i) # 출입하여 있는 직원들의 성함만 역순으로 출력