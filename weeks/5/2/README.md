# 모래섬

![Difficulty Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)

5주차 두 번째 문제 [모래섬][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1681205/5%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EB%AA%A8%EB%9E%98%EC%84%AC



## 문제

바닷가에 놀러 간 구름이는 모래사장에서 모래를 쌓아서 모래섬을 만들었다.
구름이는 자신이 만든 모래섬 사이에 다리를 세우고 싶어한다.
다리를 그냥 만들 수도 있지만, 구름이는 서로 떨어진 섬과 섬을 이어줄 때 다리가 의미가 있다고 생각했다.
그래서 구름이는 모래사장에 물을 부어서 모래섬을 여러 개의 섬으로 나누고자 한다.

모래사장은 세로의 길이가 $N$, 가로의 길이가 $M$인 직사각형 모양의 땅이다.
모래사장을 $1 \times 1$ 크기로 나누었을 때, 가장 왼쪽 위부터 $i$번째 줄의 $j$번째 칸의 상태를 $S_{i, j}$라고 표현할 수 있다.
각 칸의 상태는 $0$ 또는 $1$ 중 하나이다.

- $S_{i, j}$의 값이 $0$ 이라면, 그 칸은 물에 가라앉은 칸임을 의미한다.
- $S_{i, j}$의 값이 $1$ 이라면, 그 칸은 모래가 쌓여있는 칸임을 의미한다.

매 분마다 모래가 쌓여있는 칸 중, 다음 조건에 해당하는 칸이 동시에 물에 가라앉게 된다.

- 상하좌우로 인접한 칸 중, 물에 가라앉은 칸이 존재한다.

이때 하나의 모래섬은 다음 내용을 만족한다.
모래가 쌓여있는 칸 중, 상하좌우로 인접해있는 칸끼리는 이동할 수 있다.
단, 물에 가라앉은 칸이나 모래사장의 바깥으로는 이동할 수 없다.
그리고 어떤 칸에서 다른 칸으로 이동할 수 있는 경로가 존재한다면, 두 칸은 같은 모래섬에 속해있다.

구름이는 모래섬의 개수가 두 개 이상이 될 때, 다리를 건설하려고 한다.
구름이가 물을 부은 뒤 최소 몇 분 후에 다리를 건설 할 수 있는지 출력하시오.
단, 두 개 이상의 모래섬으로 나누어지지 않는 경우에는 `-1`을 출력하시오.

### 입력

첫째 줄에 모래사장의 크기를 의미하는 $N, M$ 이 공백을 두고 주어진다.

다음 $N$개의 줄에는 모래사장의 상태가 주어진다.
$i$번째 줄에는 $S_{i, 1}, \dots, S_{i, M}$이 공백을 두고 주어진다.

- $3 \leq N, M \leq 100$
- $0 \leq S_{i, j} \leq 1$
- 물에 가라앉은 칸이 최소 한 칸은 존재한다.
    따라서 충분한 시간이 지났을 때 모래사장의 모든 칸이 물에 잠기게 된다.
- 처음에 모래섬의 개수는 하나이다.
    따라서 $0$분이 지났을 때 다리를 건설할 수 있는 경우는 주어지지 않는다.
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

구름이가 물을 부은 뒤 최소 몇 분 후에 다리를 건설 할 수 있는지 출력하시오.
단, 두 개 이상의 모래섬으로 나누어지지 않는 경우에는 `-1`을 출력하시오.



## 발상

모래사장의 섬이 몇 개인지 구한다.
섬은 DFS로 탐색할 수 있다.
이 때 두 개 이상이면 그보다 더 세는 의미가 없으므로 두 개까지만 센다.

이제 세 가지 경우가 있다.

- 섬이 없다면, 전부 물에 가라앉은 것이다. 즉 두 개 이상의 모래섬으로 나눌 수 없는 것이다.
- 섬이 두 개 이상이라면, 이 때의 시간을 답으로 낸다.
- 섬이 하나만 있다면, 분을 하나 증가 시키고 다음 상태를 구하고 이 모든 과정을 반복한다.



## 코드 설명

섬을 방문하는 함수와 섬의 개수를 세는 함수를 별도로 만들어 쓴다.
그리고 매번 방문할 수 있는 섬이 몇 개인지 센다.
0개 이거나 2개 이상이면 결과를 낸다.

```python
# grid: 모래사장을 나타내는 이차원 배열
# gridHeight, gridWidth: 각각 모래사장의 세로와 가로
# dxs, dys: 각각 [-1, 1, 0, 0], [0, 0, -1, 1]

SAND = 1
WATER = 0

# 좌표에 속하는 섬에 대해, visited 배열에 방문을 기록하는 함수
# 섬 구역은 DFS로 탐색
def visitIsland(y, x, gridHeight, gridWidth, visited):
    if visited[y][x]:
        return
    visited[y][x] = True

    for dy, dx in zip(dys, dxs):
        ny = y + dy
        nx = x + dx

        if ny < 0 or nx < 0 or ny >= gridHeight or nx >= gridWidth:
            continue
        if grid[ny][nx] == WATER:
            continue

        visitIsland(ny, nx, gridHeight, gridWidth, visited)

# 섬의 개수를 두 개까지 세는 함수
def countIslandsUptoTwo(gridHeight, gridWidth):
    visited = [[False] * (gridWidth+1) for _ in range(gridHeight+1)]

    # 새로 방문하는 섬을 두 개까지 세고 리턴
    count = 0
    for y in range(gridHeight):
        for x in range(gridWidth):
            if visited[y][x]:
                continue
            if grid[y][x] == WATER:
                continue

            visitIsland(y, x, gridHeight, gridWidth, visited)
            count += 1

            if count >= 2:
                return count

    return count

minutes = 0
while True:
    # 섬의 개수를 세고, 결과를 내야할 때 루프를 멈춤
    islands = countIslandsUptoTwo(gridHeight, gridWidth)
    if islands == 0:
        print(-1)
        break
    if islands >= 2:
        print(minutes)
        break

    # grid를 다음 상태로 업데이트하고 분을 증가
    # 이전 상태를 복사한 뒤, 이로부터 다음 상태를 grid에 덮어 씀
    gridCopy = [grid[y][:] for y in range(gridHeight)]
    for y in range(gridHeight):
        for x in range(gridWidth):
            if gridCopy[y][x] == SAND:
                continue

            for dy, dx in zip(dys, dxs):
                ny = y + dy
                nx = x + dx

                if ny < 0 or nx < 0 or ny >= gridHeight or nx >= gridWidth:
                    continue
                grid[ny][nx] = WATER

    minutes += 1
```



## 복잡도

모래사장의 가로와 세로를 각각 $W$, $H$ 이라고 하자.


### 시간

`while` 문이 가장 많이 반복하는 최악의 경우는, 구석 한 칸에만 물이 있고 전부 물이 찰 때까지 반복할 때이다.
이 경우 가로와 세로 중에 긴 것만큼 반복한다.

각 반복마다, 섬의 개수를 셀 때 모래사장의 모든 좌표를 확인하므로 $O(WH)$ 만큼 시간을 소요한다.

섬의 개수를 셀 때마다, 섬을 방문한다.
섬의 방문은 전체적으로 볼 때 모래사장의 각 좌표를 $O(1)$ 번 방문한다.
즉 $O(WH)$ 만큼 시간을 소요한다.
따라서 섬의 개수를 세는 것은 $O(WH) + O(WH) = O(WH)$ 만큼 소요한다.

따라서 $O((W+H)(WH)) = O(W^2 + H^2)$.



### 공간

모래사장을 나타내는 이차원 배열로 인해 $O(WH)$.
