# 퍼져나가는 소문

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

7주차 두 번째 문제 [퍼져나가는 소문][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1684542/7%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%ED%8D%BC%EC%A0%B8%EB%82%98%EA%B0%80%EB%8A%94-%EC%86%8C%EB%AC%B8



## 문제 요약

사람들과 친구 관계가 주어진다.

1번 사람과 친구 관계로 연결된 모든 사람들을 세야 한다. (이때 1번 사람 본인도 포함한다.)
즉 1번 사람과 직접적으로 친구가 아니더라도, 건너건너 친구인 사람들을 전부 세야한다.



## 발상

단순히 [DFS][dfs]로 친구 관계에 있는 사람들을 마크한다.
이후 마크된 사람이 몇 명인지 센다.

[dfs]: https://en.wikipedia.org/wiki/Depth-first_search



## 코드 설명

1번 사람부터 DFS로 방문한다.
방문 여부는 배열로 만든다.
더 방문할 사람이 없으면, 몇 명을 방문했는지 출력한다.
이것이 답이 된다.

```python
# relationships: 사람마다 친구 관계를 담은 배열
# visited: 방문 여부를 담은 배열

# DFS로 방문한 사람을 visited로 기억
def visitGroup(person):
    if visited[person]:
        return
    visited[person] = True

    for nextPerson in relationships[person]:
        visitGroup(nextPerson)

# 1번 사람부터 방문
visitGroup(1)

# 방문한 사람의 수
visitedCounts = len(list(filter(lambda _: _ == True, visited)))
print(visitedCounts)
```



## 복잡도

사람이 $N$ 명, 친구 관계가 $M$ 개 있다고 하자.



### 시간

DFS 탐색으로 인해 $O(N+M)$.



### 공간

인접 리스트를 이용한 그래프 표현으로 인해 $O(N+M)$.



## 노트: 그래프의 응용 방법과 다른 문제들 정리

DFS의 기본적인 응용 방법은 이렇게 있다.

- **연결성 확인**

    모든 노드가 연결되어 있는지 확인할 수 있다.
    즉 DFS가 모든 노드를 방문했는지 알아낼 수 있다.

    이 문제는 몇 개의 노드를 방문했는지 알아냄으로써 해결할 수 있다.

- **사이클 존재 여부 확인**

    같은 노드를 두 번 방문하는 경로가 있는지 확인할 수 있다.
    즉 DFS가 같은 노드를 두 번 방문하는지 알아낼 수 있다.

    3주차 네 번째 문제인 '순환하는 수로'를 이 방법으로 해결할 수 있다.

    한편, 사이클은 BFS 로도 탐색할 수 있다.
    BFS는 특히 최소 거리를 알아내는데 사용할 수 있으므로, 사이클의 길이도 알아낼 수 있다.

    7주차 세 번째 문제인 '구름이의 여행 2'를 이 방법으로 해결할 수 있다.
