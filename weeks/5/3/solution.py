import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
from itertools import permutations

MAX_NUMBER = int(1e16)

numCards = int(readline())
cards = list(map(int, readline().split()))

# 주어진 카드로 숫자를 만드는 함수
def makeNumber(cards):
    number = cards[0]

    for i in range(1, numCards):
        prevOnes = cards[i-1] % 10
        nextTens = cards[i] // 10

        # 이전 일이 자리와 다음 십의 자리가 겹칠 때, 그대로 겹쳐서 만들기
        if prevOnes == nextTens:
            nextOnes = cards[i] % 10
            number = (number * 10) + nextOnes
            continue

        # 겹치지 않고 만들기
        number = (number * 100) + cards[i]

    return number

# 모든 퍼뮤테이션에 중에 최소값을 구함
minNumber = MAX_NUMBER
for permutation in permutations(cards):
    minNumber = min(minNumber, makeNumber(permutation))

print(minNumber)
