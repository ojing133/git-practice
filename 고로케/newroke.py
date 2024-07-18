import random

a = 52 #반복횟수

h = 0 #앞면 횟수
for x in range(a):
    t = x+1 #동전 던진 횟수   
    if random.randint(0,1) == 0: #동전이 앞면일 경우
        h += 1 #앞면 횟수 증가
    print(t, "번째 앞면 확률: ", h/t) #모든 회차에 확률 출력

    #특정 회차(1~9번째, 이후 10씩 증가)에만 print 출력하도록 하기