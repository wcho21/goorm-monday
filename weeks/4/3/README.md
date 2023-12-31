# 거리두기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

4주차 세 번째 문제 [거리두기][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1679180/4%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EA%B1%B0%EB%A6%AC%EB%91%90%EA%B8%B0



## 문제 요약

테이블이 여러 줄 주어진다.
각 줄은 세 칸이 일렬로 붙어있다.

사람들이 앞뒤와 양옆으로 적어도 한 칸이상 떨어지도록, 앉을 수 있는 자리에 스티커를 붙이려고 한다.
(스티커를 붙이지 않은 줄이 있을 수도 있다.)

줄의 개수가 주어질 때, 스티커를 붙일 수 있는 경우의 수를 구해야 한다.



## 발상

한 줄에 스티커를 붙일 수 있는 패턴은 다섯 가지이다.
즉, 스티커를 붙인 칸을 `O`, 안 붙인 칸을 `X` 라고 했을 때 이렇게 있다.

```
XXX OXX XOX XXO OXO
```

일단 윗 줄까지 완성했다고 하자.
그러면 윗 줄 패턴이 무엇이었느냐에 따라, 그 아래 다음 줄에 고를 수 있는 패턴이 정해진다.

```
upper: XXX OXX XOX XXO OXO
lower: XXX

upper: XXX XOX XXO
lower: OXX

upper: XXX OXX XXO OXO
lower: XOX

upper: XXX OXX XOX
lower: XXO

upper: XXX XOX
lower: OXO
```

예를 들어, 다음 줄이 `OXO` 일 수 있는 경우의 수는, 윗 줄이 `XXX` 이거나 `XOX` 인 경우의 수를 합하면 된다.
이런 식으로 각 줄마다 모든 패턴에 대해 경우의 수를 구한다.
모든 줄을 완성하고 나면, 마지막 줄이 가질 수 있는 모든 패턴에 대해 경우의 수를 합한다.
이것이 답이 된다.



## 코드 설명

테이블의 각 행마다 다섯 가지 패턴을 위한 배열을 만든다.
즉 이차원 배열이 된다.

첫 번째 행은 각 패턴마다 한 가지 경우밖에 없으므로, 그렇게 초기화 한다.
이제 다음 행마다 이전 행이 될 수 있는 모든 패턴에 대해 경우의 수를 합한다.
전부 구하고 나면 마지막 행의 모든 패턴에 대해 경우의 수를 합한다.

```python
# NUM_PATTERNS: 패턴의 개수, 즉 5

NONE = 0
LEFT = 1
MID = 2
RIGHT = 3
SIDES = 4

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
```



## 복잡도

테이블의 행이 $N$ 개 있다고 하자.



### 시간

`for` 문이 각 행마다 반복하므로 $O(N)$.



### 공간

테이블 행을 담은 배열로 인해 $O(N)$.
