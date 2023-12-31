# 경로의 개수

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

1주차 첫 번째 문제 [경로의 개수][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1665441/1%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-%EA%B2%BD%EB%A1%9C%EC%9D%98-%EA%B0%9C%EC%88%98



## 문제 요약

여러 섬들에 대해 각 섬마다 다음 섬을 잇는 다리의 개수가 주어진다.
처음 섬에서 출발해 되돌아 올 수 있는 경로의 개수를 구해야 한다.



## 발상

모든 경우의 수를 구하면 되므로, 각 섬마다 있는 다리의 개수를 전부 곱한다. (즉 조합론의 [곱 규칙][rule-of-product])

[rule-of-product]: https://en.wikipedia.org/wiki/Rule_of_product



## 코드 설명

각 섬마다 있는 다리의 개수를 전부 곱한다.
이것이 답이 된다.

```python
# numBridges: 각 섬마다 다리 개수를 담은 배열

# 모든 다리의 개수를 곱함
numPaths = 1
for numBridge in numBridges:
    numPaths *= numBridge

print(numPaths)
```



## 복잡도

섬의 개수를 $N$ 이라고 하자.



### 시간

섬 마다 다리의 개수를 입력 받는다.
이 입력 처리는 시간을 $O(N)$ 만큼 소요한다.

`for` 문 또한 섬 마다 있는 다리 개수에 대해 반복하므로 $O(N)$ 만큼 소요한다.

따라서 $O(N)$.


### 공간

섬 마다 다리 개수를 담은 배열로 인해 $O(N)$.
