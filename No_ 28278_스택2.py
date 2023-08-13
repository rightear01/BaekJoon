import sys
'''정수를 저장하는 스택을 구현한 다음, 
입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 
   없다면 -1을 대신 출력한다.
3: 스택에 들어있는 정수의 개수를 출력한다.
4: 스택이 비어있으면 1, 아니면 0을 출력한다.
5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 
   -1을 대신 출력한다.'''

class Stack:
    def __init__(self):
        self.top = -1
        self.myStack = list()
    
    def push(self,num):
        self.top += 1
        self.myStack.append(num)
    
    def pop(self):
        if self.top == -1: print(f'-1')
        else:
            print(f'{self.myStack.pop()}')
            self.top -= 1
    
    def count(self):
        print(f'{self.top + 1}')

    def isEmpty(self):
        if self.top == -1: return 1
        else: return 0

    def get_top(self):
        if self.isEmpty() == 1: print(f'-1')
        else: print(f'{self.myStack[self.top]}')
    
vStack = Stack()
testCase = int(sys.stdin.readline().rstrip())
for _ in range(testCase):
    command = sys.stdin.readline().rstrip()
    if command[0] == '1':
       inputNum = int(command.split()[1])
       vStack.push(inputNum)

    elif command[0] == '2': vStack.pop()
    elif command[0] == '3': vStack.count()
    elif command[0] == '4': print(f'{vStack.isEmpty()}')
    else: vStack.get_top()
    
