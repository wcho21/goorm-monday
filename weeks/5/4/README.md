# 구슬 게임

![Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)

5주차 네 번째 문제 [수 이어 붙이기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1681209/5%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-4-%EA%B5%AC%EC%8A%AC-%EA%B2%8C%EC%9E%84


## 문제

구름이는 456억을 걸고 진행되는 구징어 게임에 참가하였다.
똑똑하고 재치도 좋은 구름이는 모든 게임에서 잘 살아남아 드디어 마지막 게임인 구슬 게임까지 왔다.
구슬 게임의 규칙은 아래와 같다.

- 구슬 게임은 두 명에서 진행하는 게임이다.
- 구름이는 처음에 $N$개의 구슬을 가지고 있고, 상대방은 $M$개의 구슬을 가지고 있다.
- 게임은 $K$번의 가위바위보를 통해 진행한다.
    각 가위바위보의 결과에 따라 승리한 사람이 패배한 사람에게서 구슬 하나를 가져온다.
    무승부일 경우에는 누구도 구슬을 가져가지 못한다.
- 두 명 중 한 명이 모든 구슬을 잃거나, $K$번의 가위바위보를 모두 진행했을 때 게임이 끝난다.

구름이와 상대방의 구슬의 개수가 주어졌을 때, 둘 중 한 명이 모든 구슬을 잃어서 게임이 끝나게 되는 경우의 수를 계산해보자.
게임이 끝났을 때 구름이와 상대방이 들고 있는 구슬의 개수가 같더라도, 그렇게 되기까지의 가위바위보 결과 순서가 다르다면 다른 경우의 수로 본다.

### 입력

첫째 줄에 $N, M, K$가 공백을 두고 주어진다.

- $1 \leq N, M \leq 100$
- $1 \leq K \leq 1 \thinspace 000$
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

둘 중 한 명이 구슬을 모두 잃어서 게임이 끝나는 경우의 수를 $100 \thinspace 000 \thinspace 007$로 나눈 나머지를 출력한다.



## 발상

단순히 재귀적으로 다음 판의 경우의 수를 구한다.

즉 이번 라운드에서 승리와 패배, 무승부를 했을 때의 경우의 수를 구해 합한다.
재귀의 베이스 케이스는 한 쪽의 구슬이 떨어졌을 때나 라운드가 전부 끝났을 때이다.

한편 재방문하는 케이스가 있으므로 결과를 캐시해둔다.
즉 Top-down [DP][dp]로 해결한다.

[dp]: https://en.wikipedia.org/wiki/Dynamic_programming



## 코드 설명

경우의 수를 구하는 함수와, 캐시해둔 결과가 있으면 그것을 가져오는 함수를 만든다.
이를 이용해 결과를 구한다.

```python
# goormMarbles: 주인공이 가진 구슬의 개수
# opponentMarbles: 상대가 가진 구슬의 개수
# cache: 캐시한 결과
# cached: 캐시 여부
# lastRound: 마지막 라운드 수

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
```



## 복잡도

두 명의 구슬이 총 $N$ 개, 라운드 수를 $M$ 이라고 하자.



### 시간

한 명은 많으면 모든 구슬, 즉 $N$ 개를 가질 수 있다.
각 개수에 대해 각 라운드의 결과를 캐시할 수 있으므로 $O(MN)$.



### 공간

캐시를 위한 이차원 배열로 인해 $O(MN)$.
