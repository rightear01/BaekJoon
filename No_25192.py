import sys

testCase = int(sys.stdin.readline())
chatHist = set()
cntBear = 0

for i in range(testCase):
    nickName = sys.stdin.readline().rstrip()
    if nickName == "ENTER":
        cntBear += len(chatHist)
        chatHist.clear()
    else: chatHist.add(nickName)
cntBear += len(chatHist)

print(cntBear)