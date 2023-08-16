import sys

'''
1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
5: 덱에 들어있는 정수의 개수를 출력한다.
6: 덱이 비어있으면 1, 아니면 0을 출력한다.
7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
N이 주어진다. (1 ≤ N ≤ 1,000,000)
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.Llink = None
        self.Rlink = None

class MyDeque:
    def __init__(self):
        self.front = None
        self.rear = None
        self.eleNum = 0

    def isEmpty(self): # 6
        if self.front is None: return 1
        else : return 0
    
    def pushFront(self, data): # 1
        newNode = Node(data)
        if self.isEmpty():
            self.front = self.rear = newNode
            self.eleNum += 1
        else:
            newNode.Rlink = self.front
            self.front.Llink = newNode
            self.front = newNode
            self.eleNum += 1

    def pushRear(self, data): # 2
        newNode = Node(data)
        if self.isEmpty():
            self.front = self.rear = newNode
            self.eleNum += 1
        else:
            newNode.Llink = self.rear
            self.rear.Rlink = newNode
            self.rear = newNode
            self.eleNum += 1

    def popFront(self): # 3
        if self.isEmpty(): return -1

        data = self.front.data
        if self.front == self.rear:
            self.front = self.rear = None
            self.eleNum -= 1
        else:
            self.front = self.front.Rlink
            self.front.Llink = None
            self.eleNum -= 1

        return data
    
    def popRear(self): # 4
        if self.isEmpty(): return -1

        data = self.rear.data
        if self.front == self.rear:
            self.front = self.rear = None
            self.eleNum -= 1
        else:
            self.rear = self.rear.Llink
            self.rear.Rlink = None
            self.eleNum -= 1

        return data
    
    def countElement(self): # 5
        return self.eleNum

    def peekFront(self): # 7
        if self.isEmpty(): return -1
        return self.front.data
    
    def peekRear(self): # 8
        if self.isEmpty(): return -1
        return self.rear.data

if __name__ == "__main__":
    deque = MyDeque()
    testCase = int(sys.stdin.readline().rstrip())
    for _ in range(testCase):
        command = sys.stdin.readline().split()
        if command[0] == '1': deque.pushFront(command[1])
        elif command[0] == '2': deque.pushRear(command[1])
        elif command[0] == '3': print(deque.popFront())
        elif command[0] == '4': print(deque.popRear())
        elif command[0] == '5': print(deque.countElement())
        elif command[0] == '6': print(deque.isEmpty())
        elif command[0] == '7': print(deque.peekFront())
        elif command[0] == '8': print(deque.peekRear())