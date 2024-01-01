import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

SAND = 1
WATER = 0
MAX_SIDE_LEN = 101

dxs = [-1, 1, 0, 0]
dys = [0, 0, -1, 1]
grid = [None] * MAX_SIDE_LEN

gridHeight, gridWidth = map(int, readline().split())

for y in range(gridHeight):
    grid[y] = list(map(int, readline().strip().split()))

# 좌표에 속하는 섬에 대해, visited 배열에 방문을 기록하는 함수
# 섬 구역은 DFS로 탐색
def visitIsland(y, x, gridHeight, gridWidth, visited):
    if visited[y][x]:
        return
    visited[y][x] = True

    for dy, dx in zip(dys, dxs):
        ny = y + dy
        nx = x + dx

        if ny < 0 or nx < 0 or ny >= gridHeight or nx >= gridWidth:
            continue
        if grid[ny][nx] == WATER:
            continue

        visitIsland(ny, nx, gridHeight, gridWidth, visited)

# 섬의 개수를 두 개까지 세는 함수
def countIslandsUptoTwo(gridHeight, gridWidth):
    visited = [[False] * (gridWidth+1) for _ in range(gridHeight+1)]

    # 새로 방문하는 섬을 두 개까지 세고 리턴
    count = 0
    for y in range(gridHeight):
        for x in range(gridWidth):
            if visited[y][x]:
                continue
            if grid[y][x] == WATER:
                continue

            visitIsland(y, x, gridHeight, gridWidth, visited)
            count += 1

            if count >= 2:
                return count

    return count

minutes = 0
while True:
    # 섬의 개수를 세고, 결과를 내야할 때 루프를 멈춤
    islands = countIslandsUptoTwo(gridHeight, gridWidth)
    if islands == 0:
        print(-1)
        break
    if islands >= 2:
        print(minutes)
        break

    # grid를 다음 상태로 업데이트하고 분을 증가
    # 이전 상태를 복사한 뒤, 이로부터 다음 상태를 grid에 덮어 씀
    gridCopy = [grid[y][:] for y in range(gridHeight)]
    for y in range(gridHeight):
        for x in range(gridWidth):
            if gridCopy[y][x] == SAND:
                continue

            for dy, dx in zip(dys, dxs):
                ny = y + dy
                nx = x + dx

                if ny < 0 or nx < 0 or ny >= gridHeight or nx >= gridWidth:
                    continue
                grid[ny][nx] = WATER

    minutes += 1
