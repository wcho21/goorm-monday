import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

EMPTY = -1
MAX_STICK_LENGTH = int(1e6+1)

lengthCounts = [0] * MAX_STICK_LENGTH

numSticks = int(readline())

for length in map(int, readline().split()):
    lengthCounts[length] += 1

areaSum = 0
aside = EMPTY

for length, numSticks in reversed(list(enumerate(lengthCounts))):
    # 두 개 미만이면 볼 필요 없음
    if numSticks < 2:
        continue

    # 옆에 둔 막대기가 있으면 먼저 직사각형 만들기
    if aside != EMPTY:
        rectangleArea = length * aside
        areaSum += rectangleArea

        aside = EMPTY
        numSticks -= 2

    # 정사각형 만들기
    if numSticks >= 4:
        numSquares = numSticks // 4
        squareArea = length * length
        areaSum += squareArea * numSquares

        numSticks -= numSquares * 4

    # 남는 막대기 옆에 두기
    if numSticks >= 2:
        numSticks -= 2

        aside = length

print(areaSum)
