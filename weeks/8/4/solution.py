import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

MAX_NUM_CITIES = int(1e3+1)
MAX_CAPACITY = int(1e4+1)

visited = [False] * MAX_NUM_CITIES
neighborCities = [[] for _ in range(MAX_NUM_CITIES)]
dp = [[0] * MAX_CAPACITY for _ in range(MAX_NUM_CITIES)]

# read input
numCities, capacity = map(int, readline().split())

for _ in range(numCities-1):
    city1, city2 = map(int, readline().split())
    neighborCities[city1].append(city2)
    neighborCities[city2].append(city1)

trashes = [0] + list(map(int, readline().split()))

# solve
def collectTrash(city):
    visited[city] = True

    for neighbor in neighborCities[city]:
        if visited[neighbor]:
            continue

        collectTrash(neighbor)

        for i in range(1, capacity+1):
            dp[city][i] = max(dp[city][i], dp[neighbor][i])

    visited[city] = False

    cityTrash = trashes[city]

    for i in reversed(range(cityTrash, capacity+1)):
        notCollected = dp[city][i]
        collected = dp[city][i-cityTrash] + cityTrash

        dp[city][i] = max(notCollected, collected)

collectTrash(1)
print(dp[1][capacity])
