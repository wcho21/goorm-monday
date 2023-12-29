# UXUI 디자이너

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

7주차 첫 번째 문제 [UXUI 디자이너][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1684540/7%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-uxui-%EB%94%94%EC%9E%90%EC%9D%B4%EB%84%88



## 문제 요약

각 유저마다, 그 유저가 발생시킨 **이벤트**의 번호들이 주어진다.

가장 많이 발생한 **이벤트**를 구해야 한다.
답이 여러 개라면 **이벤트** 번호의 내림차순으로 정렬한다.



## 발상

이벤트 횟수를 단순하게 모조리 센다.
그러면 가장 많이 일어난 횟수를 알 수 있다.

이로부터 가장 많이 일어난 이벤트만 알아낸다.



## 코드 설명

이벤트를 카운트하기 위해 배열을 만들고, 입력을 처리하며 이벤트를 카운트한다.

이후 가장 많이 발생한 이벤트를 큰 번호부터 출력한다.

```python
# eventCounts: 이벤트 번호마다 발생한 횟수를 담는 배열

# 횟수 카운트
for i in range(numUsers):
    events = map(int, readline().split()[1:])

    for event in events:
        eventCounts[event] += 1

# 가장 많이 일어난 이벤트를 큰 번호부터 출력
maxEventCount = max(eventCounts)
for i, count in reversed(list(enumerate(eventCounts))):
    if count != maxEventCount:
        continue

    print(i, end=" ")
print("")
```


## 복잡도

이벤트의 개수, 혹은 이벤트 번호의 최댓값을 $N$ 이라고 하자.



### 시간

입력 처리로 인해 $O(N)$.
(출력을 위해 이벤트 번호마다 반복하는 하단 `for` 문 또한 이와 같다.)



### 공간

이벤트 발생 횟수 카운트를 위한 배열로 인해 $O(N)$.
