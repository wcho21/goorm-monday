# 비밀편지

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

6주차 세 번째 문제 [비밀편지][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1682314/6%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EB%B9%84%EB%B0%80-%ED%8E%B8%EC%A7%80



## 문제

구름이는 친구에게 전달할 편지의 내용을 숨기기 위해서 새로운 암호 체계를 고안했다.
암호는 문자열과 토큰으로 이루어져 있고, 암호화가 진행되는 과정은 아래와 같다.

- 토큰의 길이를 문자열의 길이와 맞춘다.
    길이를 맞출 때는 토큰을 연속해서 길게 이어붙인 뒤 앞에서부터 문자열의 길이만큼 자른다.
- 문자열의 값이 알파벳 대소문자인 경우 같은 위치에 있는 토큰의 문자의 ASCII 코드 값만큼 Shift 연산을 수행한다.
    문자에 Shift 연산을 수행하게 되면 사전순으로 다음에 오는 문자로 변한다.
    이 때 알파벳 대소문자 여부는 변하지 않는다.
    즉 `a`에 연산을 수행하면 `b`로 변하고, `C`에 연산을 수행하면 `D`로 변한다.
    단, 알파벳 `Z`에 또는 `z`에 연산을 수행할 경우에는 각각 `A`와 `a`로 변한다.

복호화는 암호화 과정을 반대로 하여 진행할 수 있다.

문자열과 토큰이 주어졌을 때, 암호화 또는 복호화를 진행해보자.

### 입력

입력은 $T$개의 테스트 케이스로 구성되어 있다.
입력의 첫째 줄에는 테스트 케이스의 개수 $T$가 주어지며, 각 테스트 케이스의 입력은 아래와 같은 형식을 따른다.

입력의 첫째 줄에는 문자열 $S$가 주어진다. $S$는 공백을 포함하고 있을 수 있다.
입력의 둘째 줄에는 수행할 연산의 종류를 나타내는 문자 하나와 토큰 $P$가 공백을 두고 주어진다.

- $1 \leq T \leq 100 \thinspace 000$
- $S$는 ASCII 값이 32 이상 126 이하인 문자들로 구성되어 있다.
- 연산의 종류를 나타내는 문자는 `E` 또는 `D` 중 하나이다.
    `E`는 암호화, `D`는 복호화를 진행하라는 의미이다.
- $P$는 알파벳 대소문자와 숫자로만 구성되어 있다.
- 하나의 입력 파일에서 주어지는 모든 $S$와 $P$ 길이의 합은 $2 \thinspace 000 \thinspace 000$을 넘지 않는다.

### 출력

각 테스트 케이스마다 주어진 문자열을 암호화 또는 복호화한 문자열을 한 줄에 하나씩 출력한다.



## 발상

별다른 것 없이 문제의 요구사항 그대로 구현한다.



## 코드 설명

입력 문자가 알파벳이 아니면 그대로 출력 문자가 된다.
알파벳이면 키 문자의 ASCII 코드 값만큼 시프트해야 한다.

암호화를 해야하는지 복호화를 해야하는지에 따라 시프트 방향이 달라진다.
그런데 26으로 나눈 나머지 만큼 시프트 해야 한다. (따라서 항상 0 이상이 됨을 참고)
따라서 $n$ 번 왼쪽 시프트는 곧 $26 - n$ 번 오른쪽 시프트로 볼 수 있다.

이를 이용해 출력 문자로서 결과를 낸다.

```python
# 문자 ch를 (toShift % 26) 번 시프트
# 첫 번째 문자로서 취급할 것을 base로 받음
def convert(ch, base, toShift):
    shifted = ((ord(ch) - ord(base)) + toShift) % 26
    converted = chr(shifted + ord(base))
    return converted

def solveCase():
    input = readline().strip()
    operation, key = readline().split()
    key = list(map(ord, key))

    # 각 문자에 대해 처리
    for i, ch in enumerate(input):
        # 알파벳이 아니면 그 문자 그대로 결과를 냄
        if not ch.isalpha():
            print(ch, end="")
            continue

        # 오른쪽으로 시프트할 횟수를 구함
        keyIndex = i % len(key)
        toShift = key[keyIndex] % 26
        if operation == "D":
            toShift = 26 - toShift

        # 시프트한 결과를 냄
        if ch.islower():
            print(convert(ch, 'a', toShift), end="")
        if ch.isupper():
            print(convert(ch, 'A', toShift), end="")

    print("")


for _ in range(numCases):
    solveCase()
```



## 복잡도

문제에서 주어지는 케이스의 개수를 $M$, 각 케이스마다 주어지는 입력과 키 문자가 최대 $N$ 개라고 하자.



### 시간

각 케이스마다 모든 문자를 처리해야 하므로 $O(MN)$.



### 공간

각 케이스마다 입력과 키를 담는 배열로 인해 $O(N)$ 만큼 필요하다.
모든 케이스마다 새로 배열을 만들 경우 $O(MN)$, 같은 배열을 쓸 경우 $O(N)$이 된다.
