import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
from collections import defaultdict, deque

numIslands, numBridges, startIsland = map(int, readline().split())

bridges = defaultdict(list)
for _ in range(numBridges):
    source, dest = map(int, readline().split())

    bridges[source].append(dest)

visited = [False] * (numIslands+1)
visited[startIsland] = True

def walk():
    bfsQueue = deque()
    bfsQueue.append((startIsland, 0)) # 섬, 거리

    while len(bfsQueue) > 0:
        island, distance = bfsQueue.popleft()

        # 방문하지 않은 다음 섬은 큐에 대기
        for nextIsland in bridges[island]:
            if nextIsland == startIsland: # 사이클 발견 시
                return distance+1
            if visited[nextIsland]:
                continue

            visited[nextIsland] = True
            bfsQueue.append((nextIsland, distance+1))

    return -1

print(walk())
