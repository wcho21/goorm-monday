import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
from collections import deque

MAX_NUM_ISLANDS = int(1e3+1)

numIslands, numBridges, distanceLimit = map(int, readline().split())

bridges = [[] for _ in range(MAX_NUM_ISLANDS)]
for _ in range(numBridges):
    island1, island2 = map(int, readline().split())
    bridges[island1].append(island2)
    bridges[island2].append(island1)

destIsland = numIslands

visited = [False] * numIslands
visited[1] = True

def walk():
    bfsQueue = deque()
    bfsQueue.append((1, 0))

    while len(bfsQueue) > 0:
        island, distance = bfsQueue.popleft()

        # 주어진 거리를 넘기면 스킵
        if distance >= distanceLimit:
            continue

        # 방문한 적 없는 다음 섬들을 큐에 대기
        for nextIsland in bridges[island]:
            # 목적지 섬에 도착하면 가능하다고 리턴
            if nextIsland == destIsland:
                return "YES"

            if visited[nextIsland]:
                continue
            visited[nextIsland] = True

            bfsQueue.append((nextIsland, distance+1))

    # 목적지 섬에 도달할 수 없으면 불가능하다고 리턴
    return "NO"

print(walk())
