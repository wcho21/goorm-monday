import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

SIDE = int(1e3+1)

grid = [[0] * SIDE for _ in range(SIDE)]

numSpecies, threshold = map(int, readline().split())

# 각 종마다 영역의 꼭지점에 서식 영역 인코딩
for _ in range(numSpecies):
    x1, y1, x2, y2 = map(int, readline().split())
    grid[y1][x1] += 1
    grid[y1][x2] -= 1
    grid[y2][x1] -= 1
    grid[y2][x2] += 1

# 행에 대한 프리픽스 섬
for y in range(0, SIDE):
    for x in range(1, SIDE):
        grid[y][x] += grid[y][x-1]

# 열에 대한 프리픽스 섬
for x in range(0, SIDE):
    for y in range(1, SIDE):
        grid[y][x] += grid[y-1][x]

# 종이 threshold 만큼 있는 칸의 개수 세기
count = 0
for y in range(SIDE):
    for x in range(SIDE):
        if grid[y][x] == threshold:
            count += 1

print(count)
