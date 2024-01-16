"""
문제
어떤수 N이 1이 아닌 제곱수로 나누어지지 않을 때, 이 수를 제곱ㄴㄴ수라고 한다. 제곱수는 4, 9, 16, 25와 같은 것이고, 제곱ㄴㄴ수는 1, 2, 3, 5, 6, 7, 10, 11, 13, ...과 같은 수이다.

K가 주어졌을 때, K번째 제곱ㄴㄴ수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 K가 주어진다.

출력
첫째 줄에 K번째 제곱ㄴㄴ수를 출력한다.

1. 제곱수의 리스트를 통해 어떤수 n을 검사하며 반복 > n이 검사되지 않을 경우 리스트에 추가 > 리스트 크기 따라 정지
2. 
"""

K = int(input())

num = 0
n = 1
squelist = []



"""
     4     9             16              25                  36
1 2 3 5 6 7 10 11 13 14 15 17 19 21 22 23 26 29 30 31 33 34 35 37
1 2 3 4 5 6 7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
  2 3 4 5 6


n = 1
flag = False
notsqulist = []
squelist = []

while len(notsqulist) != K:
    if n!=1: squelist.append((n)**2)
    flag = True
    for i in squelist:
        if i>n: break
        if n%i == 0:
            flag = False
            break
    if flag: notsqulist.append(n)
    n = n+1

print(notsqulist.pop())
"""