import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

NONE = 0
LEFT = 1
MID = 2
RIGHT = 3
SIDES = 4

NUM_PATTERNS = 5
MAX_NUM_ROWS = int(1e5+1)
MOD = int(1e8+7)

numRows = int(readline())

rows = [[0] * NUM_PATTERNS for _ in range(MAX_NUM_ROWS)]

# 첫 줄은 각 패턴의 경우의 수가 한 가지
rows[0] = [1] * NUM_PATTERNS

# 다음 행 계산
for i in range(1, numRows+1):
    rows[i][NONE] += rows[i-1][NONE]
    rows[i][NONE] += rows[i-1][LEFT]
    rows[i][NONE] += rows[i-1][MID]
    rows[i][NONE] += rows[i-1][RIGHT]
    rows[i][NONE] += rows[i-1][SIDES]
    rows[i][NONE] %= MOD

    rows[i][LEFT] += rows[i-1][NONE]
    rows[i][LEFT] += rows[i-1][MID]
    rows[i][LEFT] += rows[i-1][RIGHT]
    rows[i][LEFT] %= MOD

    rows[i][MID] += rows[i-1][NONE]
    rows[i][MID] += rows[i-1][LEFT]
    rows[i][MID] += rows[i-1][RIGHT]
    rows[i][MID] += rows[i-1][SIDES]
    rows[i][MID] %= MOD

    rows[i][RIGHT] += rows[i-1][NONE]
    rows[i][RIGHT] += rows[i-1][LEFT]
    rows[i][RIGHT] += rows[i-1][MID]
    rows[i][RIGHT] %= MOD

    rows[i][SIDES] += rows[i-1][NONE]
    rows[i][SIDES] += rows[i-1][MID]
    rows[i][SIDES] %= MOD

# 마지막 행의 경우의 수 합
lastRow = 0
lastRow += rows[numRows-1][NONE]
lastRow += rows[numRows-1][LEFT]
lastRow += rows[numRows-1][MID]
lastRow += rows[numRows-1][RIGHT]
lastRow += rows[numRows-1][SIDES]
lastRow %= MOD
print(lastRow)
