# UXUI 디자이너

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

7주차 첫 번째 문제 [UXUI 디자이너][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1684540/7%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-uxui-%EB%94%94%EC%9E%90%EC%9D%B4%EB%84%88



## 문제

구름이는 구름 사이트의 UXUI 디자이너로 일하게 되었다.
구름이의 첫 업무는 구름 사이트에서 사용자들이 자주 실행하는 이벤트를 정리하는 일이다.
이때 이벤트란 사용자가 웹사이트에서 실행하거나, 클릭한 것을 의미한다.
구름이는 이를 위해서 사용자들이 취할 수 있는 이벤트를 $N$개로 규정하고, 각각의 이벤트에 $1$번부터 $N$번까지 번호를 붙였다.

구름이는 이어서 $M$명의 사용자가 구름 사이트에서 이벤트를 실행한 내역을 추출하였다.
추출한 정보를 바탕으로 구름이는 사용자들이 가장 자주 실행하는 이벤트들을 알아내고자 한다.
한 사람이 같은 이벤트를 여러 번 실행한 경우에도 중복으로 세어준다.

구름이를 도와 $M$명의 사용자들이 가장 자주 실행했던 이벤트들을 찾아 출력하시오.

### 입력

첫째 줄에 이벤트의 개수 $N$과 사용자의 수 $M$이 공백을 두고 주어진다.

다음 $M$개의 줄에는 매 줄마다 $i$번 사용자가 실행한 이벤트의 개수 $k$가 주어지고, 이어서 실행한 이벤트의 번호 $e_1, \dots, e_k$가 공백을 두고 주어진다.

- $1 \leq N \leq 100 \thinspace 000$
- $1 \leq M \leq 1 \thinspace 000$
- $1 \leq k \leq 100$
- $1 \leq e_i \leq N$
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

추출한 정보를 바탕으로 사용자들이 구름 사이트에서 가장 많이 실행한 이벤트를 출력하시오.
단, 가장 많이 실행한 이벤트가 여러 개라면 각 이벤트를 공백으로 구분하여, 이벤트 번호가 큰 순서에서 작은 순서로 출력하시오.



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
