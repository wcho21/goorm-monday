# 구름이의 여행 2

![Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)

7주차 세 번째 문제 [구름이의 여행 2][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1684544/7%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EA%B5%AC%EB%A6%84%EC%9D%B4%EC%9D%98-%EC%97%AC%ED%96%89-2



## 문제

구름이가 사는 구름 나라는 $N$개의 섬으로 이루어져 있다.
각 섬에는 $1$부터 $N$까지의 번호가 붙어 있고, 구름 나라는 사람들이 섬과 섬 사이를 편하게 이동할 수 있도록 다리를 $M$개 설치했다.
설치된 다리들은 아래 특징들을 만족한다.

- 모든 다리는 단방향으로만 이동할 수 있다.
- 서로 다른 두 섬을 잇는 다리는 최대 하나이다.
- 다리가 잇는 두 섬은 항상 다른 섬이다.

구름이는 현재 $K$번 섬에 있고, 다른 섬들을 둘러본 뒤 다시 $K$번 섬으로 돌아오려고 한다.
그렇지만 오래 돌아다니는 것은 피곤한 일이기 때문에, 구름이는 최소한의 다리만 거치는 경로를 택할 것이다.
구름이를 도와 최소 몇 개의 다리를 거쳐서 원래 구름이가 있던 섬으로 돌아올 수 있을지 알아보자.
다시 돌아올 수 있는 경로가 없는 경우에는 `-1`을 출력한다.

단, 구름이는 $K$번 섬 이외에 최소 하나 이상의 다른 섬을 방문해야 한다.

### 입력

첫째 줄에 섬의 개수 $N$과 다리의 개수 $M$, 그리고 구름이가 있는 섬의 번호 $K$가 공백을 두고 주어진다.

다음 $M$개의 줄에는 다리의 시작 섬과 도착 섬을 의미하는 $a, b$가 공백을 두고 주어진다.

- $2 \leq N \leq 10 \thinspace 000$
- $1 \leq M \leq 50 \thinspace 000$
- $1 \leq K \leq N$
- $1 \leq a, b \leq N$; $a \neq b$
- 서로 다른 두 다리의 시작 섬과 도착 섬이 같은 경우는 없다.
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

$K$번 섬에서 출발한 구름이가 최소 몇 개의 다리를 거쳐서 다시 $K$번 섬으로 도착할 수 있는지 출력하시오.
만약 구름이가 다시 돌아올 수 없다면 `-1`을 출력하시오.



## 발상

단순히 [BFS][bfs]로 각 섬까지의 최소 거리를 계산해나간다.
만약 시작점을 다시 방문했다면, 그 최소 거리로 곧 되돌아오는 경로의 길이를 알 수 있다.

[bfs]: https://en.wikipedia.org/wiki/Breadth-first_search



## 코드 설명

큐를 이용해 BFS로 섬을 방문한다.
큐에는 방문할 섬과 거리가 들어간다.
각 섬을 처음 방문할 때마다 곧 최소 거리로 탐색한 것이 된다.

만약 처음 섬으로 되돌아왔다면, 사이클의 길이를 결과로 낸다.
사이클이 없다면, 문제에서 요구한 대로 `-1`을 결과로 낸다.

```python
# visited: 섬 방문 여부를 기록하는 배열
# bridges: 각 섬에 연결된 다른 섬이 담긴 배열

def walk():
    bfsQueue = deque()
    bfsQueue.append((startIsland, 0)) # 섬, 거리

    while len(bfsQueue) > 0:
        island, distance = bfsQueue.popleft()

        # 방문하지 않은 다음 섬은 큐에 대기
        for nextIsland in bridges[island]:
            if nextIsland == startIsland: # 사이클 발견 시
                return distance+1
            if visited[nextIsland]:
                continue

            visited[nextIsland] = True
            bfsQueue.append((nextIsland, distance+1))

    return -1

print(walk())
```



## 복잡도

섬이 $N$ 개, 다리가 $M$ 개 있다고 하자.



### 시간

BFS로 인해 $O(N+M)$.



### 공간

인접 리스트를 이용한 그래프 표현으로 인해 $O(N+M)$.
