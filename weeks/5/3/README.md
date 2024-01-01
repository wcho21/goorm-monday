# 수 이어 붙이기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

5주차 세 번째 문제 [수 이어 붙이기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1681208/5%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EC%88%98-%EC%9D%B4%EC%96%B4-%EB%B6%99%EC%9D%B4%EA%B8%B0



## 문제

구름이는 $10$ 이상 $99$ 이하의 서로 다른 수 $A_i$가 적힌 카드를 $N$개 가지고 있다.
구름이는 카드의 순서를 임의로 정한 다음, 카드에 적힌 수들을 순서대로 이어 붙여서 하나의 큰 수를 만드는 놀이를 하고자 한다.
예를 들어서 $12$가 적힌 카드와 $34$가 적힌 카드를 순서대로 이어 붙이면 $1234$를 만들 수 있다.

물론 저대로는 너무 시시하기에, 구름이는 앞에 있는 카드의 일의 자리 숫자와 뒤에 있는 카드의 십의 자리 숫자가 같다면 숫자 하나를 겹쳐서 이어 붙일 수 있다는 규칙을 추가했다.
예를 들어서 $38$이 적힌 카드와 $84$가 적힌 카드를 이어 붙일 때, $38$의 일의 자리 숫자와 $84$의 십의 자리 숫자가 동일하므로 두 수를 $384$와 같이 겹쳐서 이어 붙일 수 있다.
물론 $3884$와 같이 겹쳐서 이어 붙이지 않는 것도 가능하다.

구름이가 놀이에서 만들 수 있는 수 중, 가장 작은 수를 찾아 출력하시오.
단, 놀이를 할 때는 항상 모든 카드를 다 사용해야 함에 유의한다.

### 입력

첫째 줄에는 구름이가 가지고 있는 카드의 개수 $N$이 주어진다.
둘째 줄에는 각 카드에 적혀 있는 수 $A_1, \dots, A_N$이 공백을 두고 주어진다.

- $1 \leq N \leq 8$
- $10 \leq A_i \leq 99$
- 모든 $A_i$는 서로 다른 수이다.
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

구름이가 놀이에서 만들 수 있는 수 중 가장 작은 수를 출력한다.



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
