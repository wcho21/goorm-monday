# 비밀편지

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

6주차 세 번째 문제 [비밀편지][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1682314/6%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EB%B9%84%EB%B0%80-%ED%8E%B8%EC%A7%80



## 문제 요약

편지 내용이 주어지고, 암호화 또는 복호화를 수행해야 한다.



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
