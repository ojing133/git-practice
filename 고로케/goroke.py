import random

def roll(repeat):
    result = 0 # 앞면이 나온 횟수 값 초기화
    for i in range(repeat):
        if not random.randint(0,1): result+=1
    return result

renum = int(input("총 횟수 입력: "))
sum = 0 # 앞면이 나온 횟수를 저장하는 변수

for i in range(renum):
    sum += 1 - random.randint(0,1) # 0을 앞면으로 하라고 하셔서,,, 앞면 나온 횟수 카운트
    print(i+1, "번째 앞면 확률")



"""
i=1 #반복된 횟수
flag=True #반복된 횟수가 목표 횟수와 같은 10의자릿수 값을 가지게 되면 플래그 표시
while i <= renum:
    if i%10==0: #
        sum += roll(10)
        if i+10<renum: i+=10
        else: i+=1
    else:
        sum += roll(1)
        i+=1
    if flag: print(i, "번째 앞면 확률", sum/i)
"""