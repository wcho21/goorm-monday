# 구름 숫자

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

8주차 첫 번째 문제 [구름 숫자][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1686051/8%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-%EA%B5%AC%EB%A6%84-%EC%88%AB%EC%9E%90



## 문제 요약

**구름 숫자**는 하나의 숫자를 두 개의 알파벳으로 표기한다.
이는 문제에서 주어진다.

여러 자리의 **구름 숫자**를 표기할 때, 반복되는 알파벳이 있다면 겹쳐서 쓴다.

이런 식으로 주어진 **구름 숫자**를 십진수 숫자로 변환해야 한다.


## 발상

주어진 구름 숫자의 모든 자리에서 변환을 시도하고, 변환할 수 있으면 결과를 쓴다.

입력이 변환할 수 있도록 주어지기 때문에 항상 성공한다.



## 코드 설명

각 자리에서 구름 숫자 변환을 시도하고, 성공할 때마다 결과를 출력한다.
실패하는 경우는 조용히 무시한다.

```python
# table: 해시 테이블, 두 알파벳 구름 숫자에 대한 십진수 수
# goormNum: 구름 숫자 문자열
# goormNumLen: 구름 숫자 문자열 길이

# 각 자리의 구름 숫자마다 반복
for i in range(goormNumLen-1):
    # 변환할 수 없으면 스킵
    twoChars = goormNum[i:i+2]
    if twoChars not in table:
        continue

    # 변환할 수 있으면 그 결과를 출력
    print(table[twoChars], end="")
```



### Follow-up: 유효하지 않은 입력 처리

만약 변환할 수 없는 구름 숫자가 입력된다면 어떻게 처리해야 할까?

간단한 방법부터 보자.
각 자리마다 변환을 시도한다.
변환할 수 있다면, 그 다음 자리와 두 번째 다음 자리의 변환이 성공하는지 본다.
둘 중 한 곳만 성공하면 된다.
이런 식으로 문자열 끝까지 변환할 수 있다면, 유효한 입력이다.
그렇지 않으면, 유효하지 않은 입력이다.

실패 시 더 이상 탐색을 하지 않고 그만 두는 재귀함수를 만들자.
그러면 [백트래킹][backtracking]을 구현할 수 있다.

[backtracking]: https://en.wikipedia.org/wiki/Backtracking

```python
# converted: 변환 결과를 담는 배열

def convert(index):
    # 끝에 도달하면 성공을 리턴
    if index == goormNumLen-1:
        return True

    # 현재 자리의 구름 숫자가 유효하지 않다면 실패를 리턴
    twoChars = goormNum[index:index+2]
    if twoChars not in table:
        return False

    # 현재 자리에 대한 변환을 기록
    converted.append(table[twoChars])

    # 다음 자리에서 변환할 수 있으면 성공
    if convert(index+1):
        return True

    # 두 번째 다음 자리에서 변환할 수 있으면 성공
    if index < goormNumLen-2 and convert(index+2):
        return True

    # 그렇지 않으면 실패
    return False
```

이 방법은 다음 두 개의 인덱스에 대해 재귀호출로 해결한다.
최악의 경우, 즉 맨 마지막 구름 숫자만 유효하지 않을 때를 생각해보자.
관찰해보면 재방문하는 인덱스가 뒤로 갈수록 기하급수적으로 늘어난다는 걸 알 수 있을 것이다.

다시 말해 인덱스 $k$에 대한 소요 시간 $T(k)$는 대략 $T(k+1)+T(k+2)+O(1)$이 된다.
그래서 시간 복잡도가 대략 피보나치 넘버만큼 빠르게, 즉 구름 숫자 길이 $L$에 대해 시간 복잡도는 $O((\frac{1+\sqrt{5}}{2})^L)$ 이 된다.

이보다는 [DP][dp]로 해결할 수 있다. 그러면 $L$에 대해 $O(L)$의 시간 복잡도를 가질 수 있다.

[dp]: https://en.wikipedia.org/wiki/Dynamic_programming

```python
# goormNumLen: 구름 숫자 길이
# goormNum: 구름 숫자 배열
# FAILED: 실패를 나타내는 값

dp = [FAILED] * goormNumLen

for index in range(goormNumLen-1):
    twoChars = goormNum[index:index+2]

    # 첫 인덱스에서 변환할 수 없다면 실패
    if twoChars not in table and index == 0:
        break
    # 두 인접한 인덱스에서 연속으로 변환할 수 없다면 실패
    if twoChars not in table and dp[index-1] == FAILED:
        break
    # 이번 인덱스에서 실패하면 다음 인덱스 체크
    if twoChars not in table:
        continue

    dp[index] = table[twoChars]
```


## 복잡도

구름 숫자의 길이를 $L$ 이라고 하자.



### 시간

`for` 문은 각 자리마다 반복하므로 $O(L)$.



### 공간

입력을 위한 문자열 공간으로 인해 $O(L)$.
