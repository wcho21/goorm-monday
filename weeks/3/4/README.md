# 순환하는 수로

![Difficulty Hard](https://img.shields.io/badge/Difficulty-Hard-green)

3주차 네 번째 문제 [순환하는 수로][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1672667/3%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-4-%EC%88%9C%ED%99%98%ED%95%98%EB%8A%94-%EC%88%98%EB%A1%9C



## 문제 요약

**탱크**와 그 사이를 연결하는 **수로**가 주어진다.

**수로**가 순환하는 부분을 찾아서, 그 부분에 있는 모든 탱크를 그 개수와 함께 알아내야 한다.



## 발상

[DFS][dfs]로 사이클을 알아낸다.
즉 두 번 방문하는 노드를 찾는다.

[dfs]: https://en.wikipedia.org/wiki/Depth-first_search

한편, 사이클에 노드가 몇 개인지, 어떤 노드가 있는지 또한 알아내야 한다.
따라서 탐색하면서 방문한 노드를 스택에 쌓아둔다.
그러면 사이클을 알아낼 때, 즉 똑같은 노드를 두 번 방문할 때, 똑같은 노드가 두 번 스택에 들어간다.
이제 그 두 노드 사이에 있는 노드들이 사이클에 포함된 것들이고, 이것이 답이 된다.



## 코드 설명

DFS로 첫 번째 탱크부터 탐색을 시작한다.
사이클을 발견하기까지 경로를 기억해둔다.
이전 탱크가 아니면서 이미 방문한 탱크를 만나면, 사이클을 만난 것이므로 탐색을 중지한다.
기억해둔 경로에서 사이클 부분만 따로 가져오면 이것이 답이 된다.
그 사이클 부분은 두 번 방문했던 탱크 사이의 경로이다.

```python
# cycleDetected: 사이클 발견 여부
# visited: 탱크 방문 여부를 위한 배열
# channels: 각 탱크마다 다음 탱크를 담은 배열
# path: 사이클을 발견하기까지의 경로에 있는 탱크들

def walk(tank, prevTank):
    global cycleDetected
    if cycleDetected:
        return

    if visited[tank]:
        return
    visited[tank] = True

    # 경로 기억
    path.append(tank)

    for nextTank in channels[tank]:
        if nextTank == prevTank:
            continue

        # 탱크를 또 만나면 사이클이므로 탐색 중지
        if visited[nextTank]:
            path.append(nextTank)
            cycleDetected = True
            return

        # 사이클이 없었다면 다음 탱크 탐색
        walk(nextTank, tank)

        # 사이클을 만났다면 탐색 중지
        if cycleDetected:
            return

    # 사이클이 없는 부분은 경로에서 버림
    path.pop()

walk(1, NULL_NODE)

# 사이클 부분만 정렬해 답으로 구함
cycleNode = path[-1];
cyclePath = path[path.index(cycleNode):-1]
cyclePath.sort()
print(len(cyclePath))
print(" ".join(map(str, cyclePath)))
```


## 복잡도

탱크의 개수를 $N$, 수로의 개수를 $M$ 이라고 하자.



### 시간

DFS로 인해 $O(N+M)$.



### 공간

인접 리스트를 이용한 그래프 표현으로 인해 $O(N+M)$.
