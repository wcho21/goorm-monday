import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

MOD = int(1e8+7)
MAX_NUM_COLORS = int(1e5+1)

dp = [0] * MAX_NUM_COLORS
dp[2] = 1

numColors = int(readline())

for i in range(3, numColors+1):
    dp[i] = ((2*i - 1) * dp[i-1] + dp[i-2]) % MOD

print(dp[numColors])
