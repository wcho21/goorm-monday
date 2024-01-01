import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

strLen = int(readline())
str = readline()

# 최소 개수를 구하기 위해, 문자가 바뀐 횟수를 1에서 더함
curChar = str[0]
numSubStrs = 1

for i in range(1, strLen):
    if str[i] != curChar:
        numSubStrs += 1
        curChar = str[i]

print(numSubStrs)
