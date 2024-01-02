# 카드 교환하기

![Difficulty Hard](https://img.shields.io/badge/Difficulty-Hard-red)

예시 두 번째 문제 [카드 교환하기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1664807/%EC%98%88%EC%8B%9C-%EB%AC%B8%EC%A0%9C-2-%EC%B9%B4%EB%93%9C-%EA%B5%90%ED%99%98%ED%95%98%EA%B8%B0



## 문제

$1$부터 $N$까지의 번호를 가진 $N$명의 사람이 있다.
각 사람들은 $1$부터 $N$ 사이의 임의의 수 $C_i$가 쓰여있는 카드를 한 장씩 가지고 있다.

사람들 간에는 총 $M$쌍의 친구 관계가 있다.
모든 친구 관계는 양방향이라서, $a$번 사람과 $b$번 사람이 친구라면 $b$번 사람과 $a$번 사람도 친구이다.
서로 친구 관계에 있는 두 사람끼리는 서로 들고 있는 카드를 원하는 만큼 교환할 수 있다.

모든 사람들은 각자가 들고 있는 카드에 적힌 수가 자신의 번호와 최대한 비슷하기를 원한다.
어떤 한 사람의 불만족도를 그 사람이 들고 있는 카드에 적힌 수와 그 사람의 번호와의 차이로 정의하고, 전체 불만족도는 모든 사람의 불만족도의 합으로 정의한다.

카드 교환이 적절하게 이루어졌을 때, 가능한 전체 불만족도의 최솟값을 구하라.

### 입력

첫째 줄에는 사람의 수 $N$과 친구 관계의 수 $M$이 공백을 두고 주어진다.

둘째 줄에는 $C_1, \dots, C_N$이 공백을 두고 주어진다.
$C_i$는 $i$번 사람이 처음에 들고 있는 카드에 적힌 수를 의미한다.

다음 $M$개의 줄에는 $a, b$가 공백을 두고 주어진다.
이는 번 사람과 번 사람이 친구임을 의미한다.
모든 친구 관계는 양방향이고, 같은 친구 관계가 중복으로 주어지지 않는다.

- $1 \leq N \leq 200 \thinspace 000$
- $0 \leq M \leq 500 \thinspace 000$
- $1 \leq C_i \leq N$
- $1 \leq a \leq b \leq N$
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

가능한 전체 불만족도의 최솟값을 출력한다.



## 발상

친구 관계로 연결된 사람들을 그룹이라고 부르자.
그러면 친구 간에는 얼마든지 카드를 교환할 수 있으므로, 그룹의 각 사람들이 가진 카드는 재배열하여도 상관이 없다.

한편, 사람들이 번호에 대해 오름차순으로, 즉 $a_1 < a_2 < \dots < a_n$ 으로 정렬되어 있다고 하자.
이제 각 사람이 가진 카드 $b_i$가 있다고 하자.
그러면 그 카드 역시 오름차순으로 정렬했을 때, 번호와 카드의 차이의 합이 최소가 된다.
(이는 [별도 문서][proof]에서 증명한다.)

[proof]: ./PROOF.md


## 코드 설명

친구 관계로 연결된 사람들, 즉 그룹은 [DFS][dfs]로 찾을 수 있다.
각 그룹에 대해 사람들의 번호와 카드를 모으고, 번호과 카드를 각각 정렬한 후, 차이의 절대값을 합한다.
이것이 이 그룹에 대한 불만족도이며, 모두 합하면 답이 된다.

[dfs]: https://en.wikipedia.org/wiki/Depth-first_search

```python
# DFS로 그룹 사람들의 번호와 카드를 모으는 함수
def collectGroup(person):
    groupCards.append(cards[person])
    groupPeople.append(person)

    for nextPerson in friends[person]:
        if visited[nextPerson]:
            continue
        visited[nextPerson] = True

        collectGroup(nextPerson)

unhappiness = 0

for person in range(1, numPeople+1):
    if visited[person]:
        continue
    visited[person] = True

    # 각 그룹마다 번호와 카드를 모아서 정렬
    groupCards = []
    groupPeople = []

    collectGroup(person)
    groupCards.sort()
    groupPeople.sort()

    # 불만족도를 계산하여 더함
    for i in range(len(groupCards)):
        unhappiness += abs(groupCards[i] - groupPeople[i])

print(unhappiness)
```

### 파이썬에서의 재귀와 콜 스택 제한 완화

위 코드대로 파이썬에서 DFS를 구현하면 런타임 에러가 나타난다.
이는 파이썬에서 미리 설정된 재귀와 콜 스택 제한 때문이다.

이 두 가지 제한을 다음과 같이 완화한다.

첫 번째로 재귀 제한이다.
`sys` 모듈에서 완화할 수 있다.
```python
import sys
sys.setrecursionlimit(1000000)
```

두 번째로 콜스택 제한이다.
`resource` 모듈에서 완화활 수 있다.
```python
from resource import setrlimit, RLIMIT_STACK
setrlimit(RLIMIT_STACK, (-1, -1))
```

한편, 두 번째 `resource` 모듈은 플랫폼 의존적이다.
Unix 계열의 OS 에서 사용할 수 있다.
그리고 `setrlimit()`으로 완화하려는 시도가, 즉 내부적으로 쓰는 시스템 콜이 실패할 수 있다.
(더 알아보고 싶다면 [해당 모듈 문서][py-resource]를 참고.)

[py-resource]: https://docs.python.org/3/library/resource.html



## 복잡도

사람이 $N$ 명, 친구 관계가 $M$ 개 있다고 하자.



### 시간

각 DFS는 각 그룹마다 실행된다.
그룹에 $N'$ 명의 사람들과 $M'$ 개의 친구 관계가 있다면, DFS는 $O(N'+M')$ 만큼 소요한다.
모두 합하면 $O(N+M)$.



### 공간

사람들의 친구 관계가 인접 리스트를 이용한 그래프로 표현된다.
이로 인해 $O(N+M)$.
