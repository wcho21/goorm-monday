# 구름이의 여행

![Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)

3주차 세 번째 문제 [구름이의 여행][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1672666/3%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EA%B5%AC%EB%A6%84%EC%9D%B4%EC%9D%98-%EC%97%AC%ED%96%89



## 문제

구름이가 사는 구름 나라는 $N$개의 섬으로 이루어져 있다.
각 섬에는 $1$부터 $N$까지의 번호가 붙어 있고, 구름 나라는 사람들이 섬과 섬 사이를 편하게 이동할 수 있도록 다리를 $M$개 설치했다.
설치된 다리들은 아래 특징들을 만족한다.

- 모든 다리는 양방향으로 이동할 수 있다.
- 서로 다른 두 섬을 잇는 다리는 최대 하나이다.
- 다리가 잇는 두 섬은 항상 다른 섬이다.

구름이는 $1$번 섬에서 출발해서 $N$번 섬으로 가려고 하는데, 통과하는 다리의 개수가 $K$개 이하가 되길 원한다.
구름이를 도와 $1$번 섬에서 $N$번 섬까지 $K$개 이하의 다리를 이용해 도착할 수 있는지를 판별해보자.

### 입력

첫째 줄에 섬의 개수 $N$과 다리의 개수 $M$, 그리고 구름이가 건널 다리의 최대 개수 $K$가 공백을 두고 주어진다.
다음 개의 줄에는 다리가 잇는 두 섬의 번호를 의미하는 $u_i, v_i$가 공백을 두고 주어진다.

- $2 \leq N \leq 1 \thinspace 000$
- $1 \leq M \leq 5 \thinspace 000$
- $1 \leq K \leq M$
- $1 \leq u_i, v_i \leq N$; $u_i \neq v_i$
- $i \neq j$ 일 때, $(u_i, v_i) \neq (u_j, v_j)$ 이다.
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

구름이가 $1$번 섬에서 $N$번 섬까지 $K$개 이하의 다리를 사용해서 갈 수 있다면 `YES`, 갈 수 없다면 `NO`를 출력한다.



## 발상

목적지 까지의 최소 거리가 주어진 거리 안에 들어오는 지 알아내면 된다.

즉 단순히 [BFS][bfs]로 최소 거리를 구한다.

[bfs]: https://en.wikipedia.org/wiki/Breadth-first_search



## 코드 설명

각 섬을 방문할 때마다 그 다음 섬의 번호와 최소 거리를 큐에 담아 대기시킨다.

이런 식으로 목적지가 최소 거리 안에 있다면 `YES`, 아니면 `NO`를 결과로 낸다.

```python
# bridges: 각 섬에 대해 다리로 연결된 다음 섬이 담긴 배열
# visited: 각 섬의 방문 여부가 담긴 배열
# distanceLimit: 주어진 거리
# destIsland: 목적지 섬

visited[1] = True

def walk():
    bfsQueue = deque()
    bfsQueue.append((1, 0))

    while len(bfsQueue) > 0:
        island, distance = bfsQueue.popleft()

        # 주어진 거리를 넘기면 스킵
        if distance >= distanceLimit:
            continue

        # 방문한 적 없는 다음 섬들을 큐에 대기
        for nextIsland in bridges[island]:
            # 목적지 섬에 도착하면 가능하다고 리턴
            if nextIsland == destIsland:
                return "YES"

            if visited[nextIsland]:
                continue
            visited[nextIsland] = True

            bfsQueue.append((nextIsland, distance+1))

    # 목적지 섬에 도달할 수 없으면 불가능하다고 리턴
    return "NO"

print(walk())
```



## 복잡도

섬의 개수를 $N$, 다리의 개수를 $M$ 이라고 하자.



### 시간

BFS로 인해 $O(N+M)$.



### 공간

인접 리스트를 이용한 그래프 표현으로 인해 $O(N+M)$.
