''' 
해당 문제는 파이썬의 set자료형을 사용하면 간단하게 풀 수 있다.
기본적으로 set 자료형은 중복을 허락하지 않기 때문에
입력받은 문자열의 모든 부분 문자엻을 저장하려고 한다면, 중복은
제외하고 저장하게 된다.

이후에 결과는 해당 집합에 들어가있는 원소의 개수를 출력하면 끝이다.
'''

toString = input()
subSet = set() 
for i in range(len(toString)):
    for j in range(i+1, (len(toString)+1)):
        subSet.add(toString[i:j])
print(len(subSet))