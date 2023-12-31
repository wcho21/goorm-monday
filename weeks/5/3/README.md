# 수 이어 붙이기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

5주차 세 번째 문제 [수 이어 붙이기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1681208/5%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EC%88%98-%EC%9D%B4%EC%96%B4-%EB%B6%99%EC%9D%B4%EA%B8%B0



## 문제 요약

두 자리수가 적힌 카드들이 주어진다.
카드를 모두 사용해 수를 만들 수 있다.
이 때, 이전 카드의 일의 자리와 다음 카드의 십의 자리가 겹치면, 그대로 겹쳐서 세 자리 숫자로 만들 수 있다.

이렇게 카드로 만들 수 있는 가장 작은 수를 구해야 한다.



## 발상

문제에서 주어진 카드가 기껏해야 여덟장이기 때문에, 모든 카드들의 순서에 대해 탐색해도 시간이 충분할 것이다.

즉 카드의 모든 [퍼뮤테이션][permutation]에 대해 숫자를 만들어보고, 그 중에 가장 작은 것을 선택하면 답이 된다.

[permutation]: https://en.wikipedia.org/wiki/Permutation



## 코드 설명

주어진 카드의 모든 퍼뮤테이션에 대해 숫자를 만든다.
그 중에 최소값을 답으로 낸다.

```python
# cards: 주어진 카드를 담은 배열
# numCards: 카드의 개수

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
```



## 복잡도

주어진 카드의 개수를 $N$ 이라고 하자.



### 시간

숫자를 만들 때 각 카드를 읽어야 하므로 $O(N)$ 만큼 시간이 소요된다.

하단 `for` 문은 각 퍼뮤테이션에 대해 숫자를 만들어내고, 퍼뮤테이션의 개수는 $N!$ 이므로, $O(N N!)$.



### 공간

카드를 담는 배열로 인해 $O(N)$.
