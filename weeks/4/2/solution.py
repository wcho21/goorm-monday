import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

SIDE_LEN = 42

grid = [[1] * SIDE_LEN for _ in range(SIDE_LEN)]
nextGrid = [[1] * SIDE_LEN for _ in range(SIDE_LEN)]

side = int(readline())

for y in range(1, side+1):
    trees = list(map(int, readline().split()))
    for x, tree in enumerate(trees, start=1):
        grid[y][x] = tree

def isAllTurned(side):
    for y in range(1, side+1):
        for x in range(1, side+1):
            if grid[y][x] > 0:
                return False
    return True

# 다음 상태로 업데이트
def turn(side):
    for y in range(1, side+1):
        for x in range(1, side+1):
            # 물들 나무가 없으면 스킵
            if grid[y][x] == 0:
                nextGrid[y][x] = 0
                continue

            # 주변에 전부 물든 칸의 개수만큼 현재 칸을 물들게 함
            turnedNeighbors = 0
            if grid[y+1][x] == 0:
                turnedNeighbors += 1
            if grid[y-1][x] == 0:
                turnedNeighbors += 1
            if grid[y][x+1] == 0:
                turnedNeighbors += 1
            if grid[y][x-1] == 0:
                turnedNeighbors += 1

            nextGrid[y][x] = max(0, grid[y][x] - turnedNeighbors)

    # 다음 상태를 현재 상태로 업데이트
    for y in range(1, side+1):
        for x in range(1, side+1):
            grid[y][x] = nextGrid[y][x]

# 전부 물들 때 까지 걸리는 날을 세기
days = 0
while not isAllTurned(side):
    turn(side)

    days += 1
print(days)
