import sys
'''첫 번째 줄부터 차례대로 퀴즈에 대한 답을 출력한다. 
퀴즈의 종류가 0일 경우 해당 팀에 속한 멤버의 이름을 사전순으로 한 줄에 한 명씩 출력한다. 
퀴즈의 종류가 1일 경우 해당 멤버가 속한 팀의 이름을 출력한다.'''
groupNum, quizNum = map(int, sys.stdin.readline().split())
nameToTeamDic, teamToNameDic = dict(), dict()

for _ in range(groupNum):
    groupName = sys.stdin.readline().rstrip()
    membersNum = int(sys.stdin.readline().rstrip())
    members = list()
    while(membersNum):
        name = sys.stdin.readline().rstrip()
        nameToTeamDic[name] = groupName
        members.append(name)
        membersNum -= 1
    teamToNameDic[groupName] = members

for _ in range(quizNum):
    quizName = sys.stdin.readline().rstrip()
    zeroORone = int(sys.stdin.readline().rstrip())
    if zeroORone == 1: print(nameToTeamDic.get(quizName)) # 팀이름 출력
    else : print('\n'.join(sorted(teamToNameDic.get(quizName))))  # 속한 멤버 출력


