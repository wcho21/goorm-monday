import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

SIDE = int(1e3+1)

grid = [[0] * SIDE for _ in range(SIDE)]

numSpecies, threshold = map(int, readline().split())

for _ in range(numSpecies):
    x1, y1, x2, y2 = map(int, readline().split())
    grid[y1][x1] += 1
    grid[y1][x2] -= 1
    grid[y2][x1] -= 1
    grid[y2][x2] += 1

for y in range(0, SIDE):
    for x in range(1, SIDE):
        grid[y][x] += grid[y][x-1]

for x in range(0, SIDE):
    for y in range(1, SIDE):
        grid[y][x] += grid[y-1][x]

count = 0
for y in range(SIDE):
    for x in range(SIDE):
        if grid[y][x] == threshold:
            count += 1

print(count)
