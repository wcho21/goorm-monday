# 동명이인

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

1주차 두 번째 문제 [동명이인][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1665442/1%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EB%8F%99%EB%AA%85%EC%9D%B4%EC%9D%B8



## 문제 요약

주인공의 이름과 다른 사람들의 이름이 주어진다.
다른 사람들의 이름 중에 주인공의 이름이 포함된 것이 몇 개인지 구해야 한다.



## 발상

단순히 얼마나 많은 이름이 주인공의 이름을 포함하는지 센다.



## 코드 설명

각 이름마다 주인공의 이름을 포함하는지 확인한다.
그런 이름이 몇 개인지 센다.
이것이 답이 된다.

```python
# goormName: 주인공의 이름
# names: 다른 사람들의 이름을 담은 배열

# 주인공의 이름을 포함하는 것을 세기
numIncluded = 0
for name in names:
    if goormName in name:
        numIncluded += 1

print(numIncluded)
```



## 복잡도

이름의 개수를 $N$ 이라고 하자.



### 시간

$N$ 개의 이름을 입력 받는다.
이 입력 처리는 시간을 $O(N)$ 만큼 소요한다.

`for` 문 또한 각 이름에 대해 반복하므로 $O(N)$ 만큼 소요한다.

따라서 $O(N)$.


### 공간

이름을 담은 배열로 인해 $O(N)$.
