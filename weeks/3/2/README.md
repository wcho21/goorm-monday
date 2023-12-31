# 폴더 폰 자판

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

3주차 두 번째 문제 [폴더 폰 자판][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1672665/3%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-2-%ED%8F%B4%EB%8D%94-%ED%8F%B0-%EC%9E%90%ED%8C%90



## 문제 요약

숫자 키를 가진 **자판**이 주어진다.
각 **자판**은 연속으로 눌렀을 때 입력할 수 있는 문자가 주어진다.

입력된 숫자 키들이 주어질 때, 어떤 문자가 실제로 입력되는지 구해야한다.
(여기서 모든 키는 전부 연속으로 입력됐다고 본다.)



## 발상

단순히 문제에서 주어진 대로 구현하면 된다.

연속으로 입력된 키가 있다면, 어떤 키가 몇번 연속으로 입력됐는지 구한다.
이것을 가지고 숫자 키에서 어떤 문자가 입력되는지 구한다.



## 코드 설명

연속으로 입력된 키를 구분하는 것은 현재 입력된 키와 다음 입력된 키가 다른지 구분하면 된다.

연속 입력이 끝났을 때, 입력된 키와 횟수를 가지고 문자를 구한다.

다만 키가 가진 문자보다 더 많이 누를 때, 다시 첫 문자로 되돌아오므로, 나머지 연산으로 입력된 문자를 구한다.
예를 들어 키가 입력할 수 있는 문자가 문자열 `"ABC"`로 주어질 때, 5번째 문자는 `5 % 3`, 즉 두 번째 문자로 본다.

```python
pads = [ "", "1.,?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ" ]

# 입력 키와 횟수로 입력 문자를 구하는 함수
def getCharFromPresses(key, presses):
    # 숫자로 변환
    keyNum = ord(key) - ord('0')

    # 키 패드의 문자 인덱스 구하기
    mod = len(pads[keyNum])
    keyIndex = (presses-1) % mod

    return pads[keyNum][keyIndex]

numPresses = int(readline())
presses = readline()

curChar = presses[0]
streak = 1
for i in range(numPresses):
    if presses[i] == presses[i+1]:
        streak += 1
        continue

    # 현재 문자와 다음 것과 다를 때 입력할 문자를 구함
    print(getCharFromPresses(curChar, streak), end="")

    # 현재 문자와 입력 횟수 초기화
    streak = 1
    curChar = presses[i+1]

print("")
```



## 복잡도

입력 키가 $N$ 개 주어진다고 하자.



### 시간

`for` 반복문은 각 입력키에 대해 반복하고, 그 때마다 $O(1)$ 의 연산을 수행하므로, $O(N)$.




### 공간

입력 키를 담는 배열로 인해 $O(N)$.
