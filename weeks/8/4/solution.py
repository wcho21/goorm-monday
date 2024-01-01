import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

MAX_NUM_CITIES = int(1e3+1)
MAX_CAPACITY = int(1e4+1)

visited = [False] * MAX_NUM_CITIES
neighborCities = [[] for _ in range(MAX_NUM_CITIES)]
dp = [[0] * MAX_CAPACITY for _ in range(MAX_NUM_CITIES)]

# 입력 처리
numCities, capacity = map(int, readline().split())

for _ in range(numCities-1):
    city1, city2 = map(int, readline().split())
    neighborCities[city1].append(city2)
    neighborCities[city2].append(city1)

trashes = [0] + list(map(int, readline().split()))

def collectTrash(city):
    visited[city] = True

    # 다음 도시에 대해 dp 테이블 완성
    for neighbor in neighborCities[city]:
        if visited[neighbor]:
            continue

        collectTrash(neighbor)

        # 최댓값을 테이블에 반영
        for i in range(1, capacity+1):
            dp[city][i] = max(dp[city][i], dp[neighbor][i])

    visited[city] = False

    cityTrash = trashes[city]

    # 이 도시의 쓰레기를 수거한 경우와 아닌 경우 중에 최댓값 반영
    for i in reversed(range(cityTrash, capacity+1)):
        notCollected = dp[city][i]
        collected = dp[city][i-cityTrash] + cityTrash

        dp[city][i] = max(notCollected, collected)

# 1번 도시에서 시작
collectTrash(1)

print(dp[1][capacity])
