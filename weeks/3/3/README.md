# 구름이의 여행

![Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)

3주차 세 번째 문제 [구름이의 여행][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1672666/3%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EA%B5%AC%EB%A6%84%EC%9D%B4%EC%9D%98-%EC%97%AC%ED%96%89



## 문제 요약

섬과 다리가 주어진다.

시작 섬에서 출발해 주어진 거리 안에 목적지 섬에 도착할 수 있는지 알아내야 한다.



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
