# 뒤통수가 따가워

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

8주차 두 번째 문제 [뒤통수가 따가워][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1686052/8%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EB%92%A4%ED%86%B5%EC%88%98%EA%B0%80-%EB%94%B0%EA%B0%80%EC%9B%8C



## 문제

구름나라의 저편에 있는 무릉도원에는 높은 산봉우리들이 있는 산맥이 있다
모든 산봉우리에는 동쪽을 바라보며 명상을 하는 신선이 한 명씩 있다.
그러던 중 신선들은 다른 신선들이 자신의 뒤통수를 바라봐서 그런지 뒤통수가 따가워짐을 느끼다가, 문득 얼마나 많은 신선이 자신의 뒤통수를 볼 수 있는지 궁금해졌다.

산맥의 모든 봉우리들은 왼쪽에서 오른쪽으로 정확히 일렬로 놓여있다.
왼쪽에서 $a$번째 봉우리에 있는 신선이 $b$번째 봉우리에 있는 신선의 뒤통수를 보기 위해선, $a < b$ 이면서 두 봉우리 사이에 있는 모든 봉우리의 높이가 $a$번째 봉우리의 높이보다 작아야 한다.
중간에 높은 봉우리가 있으면 그 뒤쪽 봉우리는 가려져서 보이지 않기 때문이다.

신선들의 궁금증을 해결해주기 위해, 산맥에 있는 봉우리의 개수와 각 봉우리의 높이를 알려주면 각 신선마다 그 신선의 뒤통수를 볼 수 있는 신선의 수를 출력하는 프로그램을 만들어보자.

### 입력

첫째 줄에는 봉우리의 수 $N$이 주어진다.
둘째 줄에는 $h_1, \dots, h_N$ 이 공백을 두고 주어진다.
$h_i$는 $i$번째 봉우리의 높이를 의미한다.

- $5 \leq N \leq 100 \thinspace 000$
- $1 \leq h_i \leq 10^9$
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

어떤 신선의 뒤통수를 볼 수 있는 신선의 수를, 가장 서쪽의 봉우리에 있는 신선부터 순서대로 공백으로 구분하여 출력한다.



## 발상

스택을 만든다.
여기에는 다음 신선을 볼 수 있는 봉우리를 쌓아둘 것이다.

각 봉우리를 읽는다.
그 때마다 스택에 있는 봉우리 개수를 출력한다.
그 다음 현재 봉우리의 높이를 스택에 넣는다.
단 스택에 넣기 직전에, 현재 봉우리 높이 이하의 것들을 꺼내서 버린다.
그 봉우리들은 현재 봉우리에 막혀 다음 신선을 볼 수 없게 되기 때문이다.

예를 들어, 봉우리 높이가 `5 1 3 5`로 주어진다고 해보자.
그러면 스택의 크기는 처음에 `0`이다.
즉 이 신신을 볼 수 있는 다른 신선은 없다.
첫 봉우리는 그대로 스택에 들어간다.

```
input  5 1 3 5
output 0
stack  5
```

다음 봉우리 높이는 `1`이다.
현재 스택의 크기는 `1`이다.
즉, 현재 신선을 볼 수 있는 신선은 맨 뒤에 있는 한 명이다.
현재 봉우리를 스택에 넣으면, 꺼낼 것 없이 그대로 들어간다.

```
input  5 1 3 5
output 0 1
stack  5 1
```

다음 봉우리 높이는 `3`이다.
현재 스택의 크기는 `2`이다.
즉, 뒤에 있는 모든 신선이 현재 신선을 볼 수 있다.
현재 봉우리는 스택에서 `1`을 꺼낸 뒤 넣는다.
이 봉우리는 높이가 `3` 이하이므로, 현재 봉우리에 막혀 다음 신선을 볼 수 없게 되기 때문이다.

```
input  5 1 3 5
output 0 1 2
stack  5 3
```

이런식으로 최종 결과는 `0 1 2 2`가 된다.



## 코드 설명

봉우리를 읽을 때마다, 스택의 개수를 출력하고, 작은 봉우리를 스택에서 버린뒤, 현재 봉우리를 스택에 넣는다.
그러면 출력 결과가 답이 된다.

```python
# peaks: 봉우리 입력이 담긴 배열
# peakStack: 봉우리를 담는 스택

for peak in peaks:
    # 현재 스택의 개수 출력
    print(len(peakStack), end=" ")

    # 현재 봉우리보다 작은 봉우리를 스택에서 버림
    while True:
        if len(peakStack) == 0:
            break
        if peakStack[-1] > peak:
            break

        peakStack.pop()

    # 현재 봉우리를 스택에 넣음
    peakStack.append(peak)

print("")
```



## 복잡도

봉우리의 개수를 $N$ 이라고 하자.



### 시간

`for` 문은 각 봉우리마다 반복한다.

그 안에 `while` 문은 스택에서 다른 봉우리를 꺼낸다.
이 작업을 모두 모아놨다고 생각해보자.
그러면 각 봉우리 입장에서는, 스택에서 꺼내는 작업이 기껏해야 한번 생긴다.
같은 봉우리를 두 번 꺼낼 수 없기 때문이다.
따라서 `while` 문 또한 $O(N)$의 시간을 소요한다.

종합하면 $O(N)$이다.

### 공간

봉우리를 입력받기 위한 배열로 인해 $O(N)$.
