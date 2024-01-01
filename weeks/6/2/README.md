# 제곱암호

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

6주차 두 번째 문제 [제곱암호][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1682313/6%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%EC%A0%9C%EA%B3%B1%EC%95%94%ED%98%B8



## 문제 요약

**제곱 암호**라는 새로운 암호 체계가 주어진다.
**제곱 암호**로 암호화된 문장이 주어질 때, 복호화한 것을 구해야 한다.



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
