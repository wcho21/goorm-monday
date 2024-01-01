# 문자열 나누기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

2주차 두 번째 문제 [문자열 나누기][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1669556/2%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%82%98%EB%88%84%EA%B8%B0



## 문제

알파벳 소문자로만 이루어진 문자열 $S$가 주어진다.
이 문자열을 아래 조건을 만족하는 여러 개의 부분 문자열로 나누고자 할 때, 최소 몇 개의 부분 문자열로 나뉘게 될 지를 구해보자.
부분 문자열이란 문자열의 연속된 일부를 의미한다.

- 어떤 문자열을 구성하는 문자는 모두 같아야 한다.

### 입력

첫째 줄에 문자열의 길이 $N$이 주어진다.
둘째 줄에 문자열 $S$가 주어진다.

- $1 \leq N \leq 10 \thinspace 000$
- $S$는 알파벳 소문자로만 이루어져 있다.

### 출력

주어진 문자열 $S$가 최소 몇 개의 부분 문자열로 나뉘게 될 지를 출력한다.



## 발상

문자열을 나눌 수 있는 최소 개수는 각 나눈 부분이 최대한 길 때이다.

그러면 같은 문자를 가진 부분이 몇 개인지 세면 된다.
즉 문자열을 읽으면서 문자가 바뀐 횟수를 센다.

예를 들어 문자열이 `aabbcc`가 주어졌다고 하자.
최소 개수로 나누려면 `aa`, `bb`, `cc`로 나눠야 한다.
나뉜 부분이 몇 개인지 세야한다.
즉 읽어들인 문자가 몇 번 바뀌는지 세야한다.

```
aa   bb   cc
   ^    ^
  a->b b->c
```

여기에 1을 더하면 답이 된다. 이 1은 첫 부분 `aa` 도 세야 하기 때문에 생긴다.



## 코드 설명

문자열을 읽으면서 문자가 바뀐 횟수를 구한다.
여기에 1을 더하면 답이 된다.

```python
# str: 문자열
# strLen: 문자열 길이

# 최소 개수를 구하기 위해, 문자가 바뀐 횟수를 1에서 더함
curChar = str[0]
numSubStrs = 1

for i in range(1, strLen):
    if str[i] != curChar:
        numSubStrs += 1
        curChar = str[i]

print(numSubStrs)
```



## 복잡도

문자열의 길이가 $N$ 이라고 하자.



### 시간

`for` 문이 각 문자마다 반복하므로 $O(N)$.



### 공간

문자열로 인해 $O(N)$.
