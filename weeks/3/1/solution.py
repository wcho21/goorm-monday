import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

numPeople = int(readline())

scores = map(int, readline().split())
scoreSum = sum(scores)

print(scoreSum)
