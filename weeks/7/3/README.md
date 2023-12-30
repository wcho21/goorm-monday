# 구름이의 여행 2

![Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)

7주차 세 번째 문제 [구름이의 여행 2][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1684544/7%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EA%B5%AC%EB%A6%84%EC%9D%B4%EC%9D%98-%EC%97%AC%ED%96%89-2



## 문제 요약

섬과 다리가 주어진다.

시작 섬에서 출발했을 때 되돌아올 수 있는 경로가 있다면 그 길이를 구해야 한다.



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
