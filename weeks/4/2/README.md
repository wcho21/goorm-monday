# 단풍나무

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

4주차 두 번째 문제 [단풍나무][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1679179/4%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EB%8B%A8%ED%92%8D%EB%82%98%EB%AC%B4



## 문제 요약

공원의 **나무**가 격자로 주어진다.
각 칸에는 물들지 않은 단풍 나무의 개수가 주어진다.

각 칸에 물들지 않은 나무가 있다면, 인접한 칸 중에 전부 물든 칸의 개수만큼 다음날 나무들이 물든다.
며칠이 지났을 때 모든 나무가 물드는지 구해야 한다.



## 발상

단순히 각 칸마다 인접한 칸을 확인하며 시뮬레이션을 구현한다.

나무 격자를 수정할 때, 하나의 버퍼만 쓰면 문제가 생길 수 있다.
즉 왼쪽 나무를 업데이트하면, 그 오른쪽 나무의 상태를 업데이트 할때, 가져다 써야할 예전의 왼쪽 나무가 아닌 이미 업데이트된 것을 잘못 가져다 쓸 수 있다.

따라서 버퍼를 두 개 준비하고, 하나는 현재 상태를 담은 뒤, 다른 쪽은 다음 상태를 쓴다.
다 썼으면 다른 쪽 버퍼를 현재 상태 버퍼로 사용한다.



## 코드 설명

현재 나무가 모두 물들었는지 확인한다.
물들지 않은 나무가 있다면, 다음날의 상태를 얻는다.
이를 반복한다.
반복이 끝났을 때 소요된 날이 답이 된다.

격자를 만들 때, 상하좌우로 필요한 길이보다 한 칸씩 더 할당한다.
이렇게 하면 인접한 칸의 나무를 조사할 때, 범위를 벗어나는지 체크할 필요가 사라진다.

```python
# grid: 현재 나무들 상태가 담긴 이차원 배열
# nextGrid: 나무의 다음 상태를 담을 이차원 배열
# side: 공원 한 변의 길이

def isAllTurned(side):
    for y in range(1, side+1):
        for x in range(1, side+1):
            if grid[y][x] > 0:
                return False
    return True

# 다음 상태로 업데이트
def turn(side):
    for y in range(1, side+1):
        for x in range(1, side+1):
            # 물들 나무가 없으면 스킵
            if grid[y][x] == 0:
                nextGrid[y][x] = 0
                continue

            # 주변에 전부 물든 칸의 개수만큼 현재 칸을 물들게 함
            turnedNeighbors = 0
            if grid[y+1][x] == 0:
                turnedNeighbors += 1
            if grid[y-1][x] == 0:
                turnedNeighbors += 1
            if grid[y][x+1] == 0:
                turnedNeighbors += 1
            if grid[y][x-1] == 0:
                turnedNeighbors += 1

            nextGrid[y][x] = max(0, grid[y][x] - turnedNeighbors)

    # 다음 상태를 현재 상태로 업데이트
    for y in range(1, side+1):
        for x in range(1, side+1):
            grid[y][x] = nextGrid[y][x]

# 전부 물들 때 까지 걸리는 날을 세기
days = 0
while not isAllTurned(side):
    turn(side)

    days += 1
print(days)
```



## 복잡도

공원 한 변의 길이를 $L$ 이라고 하자.
그리고 한 칸에 있는 나무들이 최대 $N$ 개 있다고 하자.



### 시간

다음 상태로 업데이트 하기 위해서 모든 칸을 방문해야 하므로 $O(L^2)$ 만큼 소요된다.
그런데 모든 나무가 물들 때까지 필요한 일수는 $O(NL)$ 이다.

하루마다 다음 상태로 업데이트하므로 $O(NL^3)$.



### 공간

공원을 위한 이차원 배열로 인해 $O(L^2)$.
