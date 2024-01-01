import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
from collections import deque

MAX_NUM_TANKS = int(1e3+1)
NULL_NODE = 0

numTanks = int(readline())

channels = [[] for _ in range(MAX_NUM_TANKS)]
for _ in range(numTanks):
    tank1, tank2 = map(int, readline().split())
    channels[tank1].append(tank2);
    channels[tank2].append(tank1);

cycleDetected = False
visited = [False] * (numTanks+1)
path = []

def walk(tank, prevTank):
    global cycleDetected
    if cycleDetected:
        return

    if visited[tank]:
        return
    visited[tank] = True

    # 경로 기억
    path.append(tank)

    for nextTank in channels[tank]:
        if nextTank == prevTank:
            continue

        # 탱크를 또 만나면 사이클이므로 탐색 중지
        if visited[nextTank]:
            path.append(nextTank)
            cycleDetected = True
            return

        # 사이클이 없었다면 다음 탱크 탐색
        walk(nextTank, tank)

        # 사이클을 만났다면 탐색 중지
        if cycleDetected:
            return

    # 사이클이 없는 부분은 경로에서 버림
    path.pop()

walk(1, NULL_NODE)

# 사이클 부분만 정렬해 답으로 구함
cycleNode = path[-1];
cyclePath = path[path.index(cycleNode):-1]
cyclePath.sort()
print(len(cyclePath))
print(" ".join(map(str, cyclePath)))
