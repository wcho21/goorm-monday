# 구름나라 청소하기

![Difficulty Hard](https://img.shields.io/badge/Difficulty-Hard-red)

8주차 네 번째 문제 [구름나라 청소하기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1686054/8%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-4-%EA%B5%AC%EB%A6%84%EB%82%98%EB%9D%BC-%EC%B2%AD%EC%86%8C%ED%95%98%EA%B8%B0



## 문제 요약

**도시**는 트리로, 즉 사이클이 없는 양방향 그래프로 표현되어 있다.

그리고 각 **도시**에는 **쓰레기**의 개수가 주어져있다. (**쓰레기** $\geq 0$)

각 **도시**를 최대 한 번만 돌아다니며 수거할 수 있는 최대 **쓰레기** 개수를 구해야 한다.



## 발상

Bottom-up [DP][dp]로 해결한다.
즉 다음 테이블을 만든다.

[dp]: https://en.wikipedia.org/wiki/Dynamic_programming

```
dp[city][capacity] = trash
```
즉 도시 `city`와 쓰레기 봉투 용량 `capacity` 마다, 수거할 수 있는 최대 쓰레기 개수 `trash`를 계산한다.

테이블 작성을 위한 베이스 케이스는 그래프의 터미널 노드에 해당한다.
어떤 도시가 터미널 노드에 해당하는지는 [DFS][dfs]로 탐색하며 알아낸다.

[dfs]: https://en.wikipedia.org/wiki/Depth-first_search

### 베이스 케이스

쓰레기를 수거할 때를 계산하여 테이블을 채운다.
즉 `capacity`가 5이고, 이 도시의 쓰레기가 4이라면, 테이블은 이렇게 된다.

```
capacity 0 1 2 3 4 5
trash    0 0 0 0 4 4
```

### 재귀 케이스

베이스 케이스가 아니라면, 이 도시 다음으로 방문할 도시가 있는 것이다.

먼저, 다음으로 방문할 모든 도시에 대해 테이블을 계산한다.
그리고 그 모든 도시에 대해 `trash`의 최댓값만 가져온다.
그러면 다음으로 방문할 모든 도시에 대해 문제를 푼 것이다.

예를 들어, 도시 1이 터미널 노드인 도시 2, 3과 연결되어 있고, 베이스 케이스가 이렇다고 하자.
```
[city 2 (trash = 4)]
capacity 0 1 2 3 4 5
trash    0 0 0 0 4 4

[city 3 (trash = 2)]
capacity 0 1 2 3 4 5
trash    0 0 2 2 2 2
```

그러면 최댓값만 가져온다는 것은 다음과 같다.
```
[city 1]
capacity 0 1 2 3 4 5
trash    0 0 2 2 4 4
```

이를 바탕으로, 이 도시에서 쓰레기를 수거하는 경우와 수거하지 않는 경우를 계산해 테이블을 완성한다.
그리고 리턴하면 이 도시에 대해 해결한 것이다.

예를 들어, 이 도시가 1번 도시이고, 쓰레기 개수가 1이라고 하자.
이 도시의 쓰레기를 수거하지 않는다면, 방금 가져왔던 최댓값과 똑같다.
```
[city 1 (trash = 1)]
capacity 0 1 2 3 4 5
trash    0 0 2 2 4 4
```

이 도시의 쓰레기를 수거하는 경우는, 위 경우로부터 바로 계산한다.
즉, 쓰레기 봉투 용량 `k`로 이 도시의 쓰레기 `n`을 수거하는 것은, 곧 쓰레기 봉투 용량 `k-n`으로 다음 모든 도시의 쓰레기를 수거한 뒤에 이 도시의 쓰레기를 수거하는 것이다.
따라서 위 테이블을 오른쪽으로 `n`칸을 민 다음, `trash`에 `n`을 더한다.
```
[city 1 (trash = 1)]
capacity 0 1 2 3 4 5
trash      1 1 3 3 5 5
```

그리고 위 두 테이블로부터 최댓값만 가져온다.
그러면 이 도시의 쓰레기를 수거하는 경우와 그렇지 않은 경우 중에 최대 쓰레기만 계산하는 것이다.
```
[city 1 (trash = 1)]
capacity 0 1 2 3 4 5
trash    0 1 2 3 4 5
```

이 단계는 재귀적이기 때문에 모든 도시에 대해 이처럼 해결할 수 있다.

이로부터 최종적인 답은 `dp[city][capacity]`이 된다.
즉 여기서는 도시 1의 `capacity == 5`인 경우의 답 5가 된다.



## 코드 설명

베이스 케이스는 재귀 케이스에서 다음 도시가 없는 경우와 똑같다.
따라서 두 케이스 전부 `collectTrash()` 함수로 테이블을 계산한다.

```python
# visited: DFS 탐색을 위한 방문 여부 배열
# neighborCities: 다음 도시들 배열 (그래프 표현)
# trashes: 도시의 쓰레기 개수 배열
# dp: DP 테이블, 각 도시와 쓰레기 봉투 용량에 대해 최대로 수거한 쓰레기

def collectTrash(city):
    visited[city] = True

    # 다음 도시에 대해 dp 테이블 완성 (베이스 케이스에서는 실행되지 않음)
    for neighbor in neighborCities[city]:
        if visited[neighbor]:
            continue

        collectTrash(neighbor)

        # 최댓값을 테이블에 반영
        for i in range(1, capacity+1):
            dp[city][i] = max(dp[city][i], dp[neighbor][i])

    visited[city] = False

    # 이 도시의 쓰레기를 수거한 경우와 아닌 경우 중에 최댓값 반영
    cityTrash = trashes[city]
    for i in reversed(range(cityTrash, capacity+1)):
        notCollected = dp[city][i]
        collected = dp[city][i-cityTrash] + cityTrash
        dp[city][i] = max(notCollected, collected)

# 1번 도시에서 시작
collectTrash(1)

# 답 출력
print(dp[1][capacity])
```



## 복잡도

DP 테이블을 각 도시를 행으로 하고 각 쓰레기 용량을 열로 하는 테이블로 생각하자.
즉 $N$ 개의 도시와 $M$ 의 쓰레기 용량에 대해, $NM$ 개의 칸이 있다.



### 시간

각 도시 행이 몇 번 접근되는지 살펴보자.
도시가 터미널 노드라면, 그 도시 행은 `collectTrash()` 함수의 하단 `for` 문에서 3번 접근된다.
그리고 이 결과를 필요로 하는 도시 한 곳에서 한 번 더 접근된다.
따라서 네 번 접근된다.

도시가 터미널 노드가 아니면, 그 도시 행은 `collectTrash()` 함수의 상단 `for` 문에서 그 다음 도시의 개수만큼 접근된다.
그리고 터미널 노드의 경우처럼, 네 번 더 접근된다.

그런데 여기서 '그 다음 도시'의 방문은 전체적으로 보면, 처음 시작 도시를 제외하고 각 도시마다 한번씩 일어난다.
따라서 각 도시 행마다 기껏해야 다섯번의 접근이 일어난다고 볼 수 있다.

여기서 행의 접근이란 그 행의 모든 열을 접근하는 것을 말하므로, 각 행마다 $O(M)$의 접근이 일어난다.
행은 $N$개 이므로, 복잡도는 $O(NM)$이다.

#### 노트

DFS 탐색에 걸리는 시간은 일반적으로, 노드가 $V$ 개, 에지가 $E$ 있는 그래프에서 $O(V+E)$ 만큼 필요하다.
그런데 트리는 사이클이 없는 그래프, 즉 노드가 $V$ 개, 에지가 $V-1$ 개 있는 그래프이다.
따라서 트리의 탐색은 시간이 $O(V)$ 만큼 소요된다는 점을 참고하자.



### 공간

DP 테이블로 인하여 $O(NM)$.
