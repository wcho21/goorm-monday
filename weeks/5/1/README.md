# 개미와 진딧물

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

5주차 첫 번째 문제 [개미와 진딧물][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1681203/5%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-%EA%B0%9C%EB%AF%B8%EC%99%80-%EC%A7%84%EB%94%A7%EB%AC%BC



## 문제 요약

정사각형 격자에 각 칸에는 개미나 진딧물이 있을 수 있다.

개미는 주어진 맨해튼 거리 안에 있는 진딧물에게만 도달할 수 있다.

진딧물에게 도달할 수 있는 개미는 몇 마리인지 구해야 한다.



## 발상

단순히 진딧물의 좌표와 개미의 좌표를 읽은 뒤, 얼마나 많은 개미가 대해 진딧물에게 도달할 수 있는지 센다.



## 코드 설명

개미와 진딧물의 좌표를 배열에 담아둔다.
각 개미마다 도달할 수 있는 진딧물이 하나라도 있는지 확인한다.
그렇게 도달할 수 있는 개미가 몇 마리인지 센다.

```python
# side: 정사각형 한 변의 길이
# reachableDistance: 개미가 갈 수 있는 거리
# ants: 개미의 좌표를 담는 배열
# aphids: 진딧물의 좌표를 담는 배열

def getManhattanDistance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

# 개미와 진딧물 좌표를 읽어서 배열에 담음
for y in range(side):
    reads = map(int, readline().split())

    for x, read in enumerate(reads):
        if read == ANT:
            ants.append((y, x))
            continue
        if read == APHID:
            aphids.append((y, x))
            continue

# 각 개미마다 진딧물에 닿을 수 있는지 세기
numFeedable = 0
for antY, antX in ants:
    for aphidY, aphidX in aphids:
        # 닿을 수 있는 진딧물이 하나라도 있다면 다음 개미로 스킵
        distance = getManhattanDistance(antX, antY, aphidX, aphidY)
        if distance <= reachableDistance:
            numFeedable += 1
            break
print(numFeedable)
```



## 복잡도

정사각형 한 변의 길이를 $L$ 이라고 하자.



### 시간

입력을 처리하는 `for` 문은 각 칸을 읽으므로 $O(L^2)$ 만큼 시간을 소요한다.

하단 `for` 문을 보자.
최악의 경우, 개미와 진딧물이 $L^2/2$ 마리씩 주어질 수 있다.
각 개미에 대해 각 진딧물을 확인하므로 $O(L^4)$ 이다.



### 공간

정사각형을 담기 위한 이차원 배열로 인해 $O(L^2)$.
