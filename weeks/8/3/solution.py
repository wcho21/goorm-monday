import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline
from collections import defaultdict

EMPTY = -1
MAX_STICK_LENGTH = int(1e6+1)

lengthCounts = [0] * MAX_STICK_LENGTH

numSticks = int(readline())

for length in map(int, readline().split()):
    lengthCounts[length] += 1

areaSum = 0
aside = EMPTY

for length, numSticks in reversed(list(enumerate(lengthCounts))):
    if numSticks < 2:
        continue

    if aside != EMPTY:
        rectangleArea = length * aside
        areaSum += rectangleArea

        aside = EMPTY
        numSticks -= 2

    if numSticks >= 4:
        numSquares = numSticks // 4
        squareArea = length * length
        areaSum += squareArea * numSquares

        numSticks -= numSquares * 4

    if numSticks >= 2:
        numSticks -= 2

        aside = length

print(areaSum)
