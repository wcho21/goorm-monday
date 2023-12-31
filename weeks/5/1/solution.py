import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

ANT = 1
APHID = 2

ants = []
aphids = []

def getManhattanDistance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

side, reachableDistance = map(int, readline().split())

# 개미와 진딧물 좌표를 읽어서 배열에 담음
for y in range(side):
    reads = map(int, readline().split())

    for x, read in enumerate(reads):
        if read == ANT:
            ants.append((y, x))
            continue
        if read == APHID:
            aphids.append((y, x))
            continue

# 각 개미마다 진딧물에 닿을 수 있는지 세기
numFeedable = 0
for antY, antX in ants:
    for aphidY, aphidX in aphids:
        # 닿을 수 있는 진딧물이 하나라도 있다면 다음 개미로 스킵
        distance = getManhattanDistance(antX, antY, aphidX, aphidY)
        if distance <= reachableDistance:
            numFeedable += 1
            break
print(numFeedable)
