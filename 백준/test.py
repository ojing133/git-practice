K = int(input())
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
