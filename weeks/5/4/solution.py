import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

MAX_NUM_MARBLES = 201
MAX_ROUNDS = 1002
MOD = int(1e8+7)

cache = [[0] * MAX_ROUNDS for _ in range(MAX_NUM_MARBLES)]
cached = [[False] * MAX_ROUNDS for _ in range(MAX_NUM_MARBLES)]

goormMarbles, opponentMarbles, lastRound = map(int, readline().split())

def getNumWays(goormMarbles, opponentMarbles, rounds):
    # 한 쪽이 떨어지면 한 가지 경우로 셈
    if goormMarbles == 0 or opponentMarbles == 0:
        return 1
    # 라운드가 끝나면 없는 경우로 셈
    if rounds > lastRound:
        return 0

    # 다음 라운드의 모든 경우의 수를 합하여 리턴
    ways = 0
    ways += getNumWaysCached(goormMarbles, opponentMarbles, rounds+1) # 무승부
    ways += getNumWaysCached(goormMarbles-1, opponentMarbles+1, rounds+1) # 패배
    ways += getNumWaysCached(goormMarbles+1, opponentMarbles-1, rounds+1) # 승리
    ways %= MOD

    return ways

# 캐시가 없으면 만들고 결과를 리턴하는 함수
def getNumWaysCached(goormMarbles, opponentMarbles, rounds):
    if not cached[goormMarbles][rounds]:
        cache[goormMarbles][rounds] = getNumWays(goormMarbles, opponentMarbles, rounds)
        cached[goormMarbles][rounds] = True

    return cache[goormMarbles][rounds]

print(getNumWays(goormMarbles, opponentMarbles, 1))
