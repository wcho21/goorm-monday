# 폭탄 구현하기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

2주차 네 번째 문제 [폭탄 구현하기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1669558/2%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-4-%ED%8F%AD%ED%83%84-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0



## 문제

$N \times N$ 크기의 정사각형 모양의 땅이 있다.
땅을 $1 \times 1$ 크기의 작은 땅으로 나누었을 때, 위에서 $y$번째, 왼쪽에서 $x$번째에 위치한 땅의 좌표를 $(y, x)$로 나타낸다.
추가로 모든 땅에는 폭탄 값이라고 하는 값이 있다. 모든 폭탄 값의 초기 값은 $0$이다.

$K$개의 폭탄을 이 땅 위에 떨어트리려고 한다.
어떤 $1 \times 1$ 크기의 땅 위에 폭탄을 떨어트리게 되면 폭탄이 떨어진 땅과, 그 땅에 상하좌우로 인접한 칸의 폭탄 값이 1 증가하게 된다.
$N \times N$ 크기의 영역을 벗어난 땅은 아무런 영향을 받지 않는다.

폭탄을 모두 떨어트렸을 때, $N \times N$ 안의 모든 땅들의 폭탄 값의 합을 구하시오.

### 입력

첫째 줄에 땅의 길이 $N$과 폭탄을 떨어트릴 횟수 $K$가 공백을 두고 주어진다.
다음 $K$개의 줄에는 폭탄을 떨어트릴 땅의 좌표를 나타내는 $y_i, x_i$가 공백을 두고 주어진다.

- $1 \leq N \leq 20$
- $1 \leq K \leq 500 \thinspace 000$
- $1 \leq y_i, x_i \leq N$
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

폭탄을 모두 떨어트렸을 때, $N \times N$ 안의 모든 땅들의 폭탄 값의 합을 출력한다.



## 발상

단순히 땅을 이차원 배열로 만든 뒤, 폭탄이 떨어지는 위치마다 폭탄 값을 증가시킨다.

이후 모든 좌표에 대해 폭탄 값을 더하면 답이 된다.



## 코드 설명

땅을 이차원 배열로 만든다.
주어진 땅의 크기보다 상하좌우로 한 칸씩 더 크게 할당한다.
이렇게 하면 폭탄이 떨어져서 상하좌우로 인접한 칸에 폭탄 값을 증가시킬때, 좌표가 범위를 벗어나는지 체크할 필요가 사라진다.

단순히 모든 폭탄 좌표에 대해 시뮬레이션을 진행하고, 폭탄 값을 전부 합하여 결과를 낸다.

```python
# bombValues: 폭탄 값을 담을 이차원 배열
# side: 땅 한 변의 길이
# numDrops: 폭탄의 개수

# 각 폭탄 좌표에 대해 인접한 칸을 포함하여 폭탄값 증가
for i in range(numDrops):
    y, x = map(int, readline().split())

    bombValues[y][x] += 1
    bombValues[y-1][x] += 1
    bombValues[y+1][x] += 1
    bombValues[y][x-1] += 1
    bombValues[y][x+1] += 1

# 모든 폭탄 값 합하기
bombValueSum = 0
for y in range(1, side+1):
    bombValueSum += sum(bombValues[y][1:side+1])

print(bombValueSum)
```



## 복잡도

정사각형 땅의 한 변이 $L$ 이라고 하자.

폭탄의 개수를 $N$ 이라고 하자.



### 시간

상단 `for` 문은 모든 폭탄에 대해 반복하므로 $O(N)$ 만큼 소요한다.

하단 `for` 문은 모든 칸을 방문하므로 $O(L^2)$ 만큼 소요한다.

따라서 $O(N+L^2)$.



### 공간

땅을 위한 배열로 인해 $O(L^2)$.
