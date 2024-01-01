# 제곱암호

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

6주차 두 번째 문제 [제곱암호][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1682313/6%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EC%A0%9C%EA%B3%B1%EC%95%94%ED%98%B8


## 문제

구름이는 비밀스러운 이야기를 전달하기 위해서 새로운 암호 체계인 제곱암호를 고안했다.
제곱암호로 암호화된 문장은 다음과 같은 특징을 가진다.

- 암호문의 길이가 $N$이라면, $N/2$개의 숫자와 $N/2$개의 알파벳 소문자로 이루어져 있다.
    암호문의 길이는 항상 짝수이다.
- 암호문의 첫 글자는 항상 알파벳 소문자이며, 이후에는 항상 숫자와 알파벳 소문자가 번갈아 가며 등장한다.

제곱암호로 암호화된 문장은 아래 방식을 통해 복호화할 수 있다.

- 원문은 처음에 비어있는 상태이다.
- 암호문의 첫 번째 문자부터 순서대로 아래의 복호화 과정을 거친다.
    첫 번째 문자는 문장의 가장 왼쪽 문자를 의미한다.
- $i$가 홀수일 때, 암호문의 번째 문자를 알파벳의 사전 기준 다음 문자로 바꾸는 작업을 암호의 $i+1$번째 수의 제곱번 시행한다. 작업이 끝난 뒤 변환된 알파벳을 원문의 맨 오른쪽에 추가한다.
- `z`에서 사전 기준 다음 문자로 바꿔야 하는 경우에는 `a`로 바뀌게 된다.
- 복호화가 끝난 뒤의 원문은 $N/2$의 길이의 알파벳 소문자로만 이루어진 문자열이다.

구름이가 친구에게 제곱암호로 암호화된 문장을 받았을 때, 이를 원문으로 복호화하는 프로그램을 작성하시오.

### 입력

첫째 줄에는 암호문의 길이를 의미하는 정수 $N$이 주어진다.
둘째 줄에는 암호문 $S$가 주어진다.

- $4 \leq N \leq 200 \thinspace 000$; $N$은 짝수이다.
- $S$는 알파벳 소문자와 `1`부터 `9` 사이의 숫자로만 이루어져 있다.

### 출력

암호문을 조건에 따라서 복호화한 뒤, 원문을 출력한다.



## 발상

별다른 것 없이 문제의 요구사항 그대로 구현한다.



## 코드 설명

하나의 복호화된 문자를 내기 위해, 두 개의 암호화된 문자를 읽어야 한다.
따라서 두 문자씩 읽으며 복호화 결과를 낸다.

다음 문자로 시프트하는 것은 ASCII 코드에 의존한다.

```python
# encrypted: 암호화된 문자가 담긴 배열
# numEncrypted: 암호화된 문자의 길이
# decrypted: 복호화된 문자를 담을 배열

for i in range(0, numEncrypted, 2):
    # 문자 두 개씩 읽음
    encryptedChar = encrypted[i]
    encryptedNum = ord(encrypted[i+1]) - ord('0')

    # 다음 ASCII 문자로 제곱번 시프트
    encryptedAsciiIndex = ord(encryptedChar) - ord('a')
    decryptedAsciiIndex = (encryptedAsciiIndex + encryptedNum ** 2) % 26

    # 복호화 결과 담기
    decryptedChar = chr(decryptedAsciiIndex + ord('a'))
    decrypted.append(decryptedChar)

print("".join(decrypted))
```



## 복잡도

암호화 문장의 길이를 $N$ 이라고 하자.



### 시간

`for` 문이 각 문자를 읽으므로 $O(N)$.



### 공간

암호화 문장과 복호화 문장을 담기위한 배열로 인해 $O(N)$.
