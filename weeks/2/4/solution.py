import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

MAX_SIDE_LEN = 20+2 # +2 due to margin

bombValues = [[0] * MAX_SIDE_LEN for _ in range(MAX_SIDE_LEN)]

side, numDrops = map(int, readline().split())

# 각 폭탄 좌표에 대해 인접한 칸을 포함하여 폭탄값 증가
for i in range(numDrops):
    y, x = map(int, readline().split())

    bombValues[y][x] += 1
    bombValues[y-1][x] += 1
    bombValues[y+1][x] += 1
    bombValues[y][x-1] += 1
    bombValues[y][x+1] += 1

# 모든 폭탄 값 합하기
bombValueSum = 0
for y in range(1, side+1):
    bombValueSum += sum(bombValues[y][1:side+1])

print(bombValueSum)
