import sys
'''
처음에 총총이(ChongChong)를 만났던 사람이 무지개 댄스를 추고 있기 때문에
이후에 해당 사람이 다른 사람을 만나도 동일하게 같이 춤을추게 된다.
입력은 두개의 문자열로 들어오고 필자는 집합(set)을 사용하여 총총이를 만났던
사람부터 그 이후에 만났던 사람까지 set에 저장하고 이후에 set에 저장되어있는
문자열을 개수를 실셈하여 문제를 풀이하였다.
'''
dancer = {"ChongChong"}
personNum = int(sys.stdin.readline().rstrip())

for _ in range(personNum):
    susDancer1, susDancer2 = (sys.stdin.readline().rstrip().split())

    if susDancer1 in dancer: dancer.add(susDancer2)
    elif susDancer2 in dancer: dancer.add(susDancer1)

print(len(dancer))