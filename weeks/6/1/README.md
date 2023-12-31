# 7게임

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

6주차 첫 번째 문제 [7게임][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1682312/6%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-7%EA%B2%8C%EC%9E%84



## 문제 요약

일곱 자리의 숫자들이 주어진다.

7게임은 일곱 자리의 숫자에서 홀수번 째 숫자를 더하고, 거기에 짝수번 째 숫자를 0이 아닌 것만 곱한 뒤, 10으로 나눈 나머지가 답이다.

이런 7게임의 결과를 구해야 한다.



## 발상

별다른 것 없이 문제의 요구사항 그대로 구현한다.



## 코드 설명

각 숫자에 대해 다음과 같이 결과를 낸다.
설명은 코드 자체로 대신한다.

```python
# digits: 각 자리의 숫자가 담긴 배열

oddDigitsSum = sum(d for d in digits[::2])
nonZeroEvenDigits = filter(lambda n: n != 0, digits[1::2])
evenDigitsProd = reduce(mul, nonZeroEvenDigits, 1)
print((oddDigitsSum * evenDigitsProd) % 10)
```



## 복잡도

자릿수가 정해져 있지만, 분석을 위해 자릿수의 길이를 $N$ 이라고 하자.

그리고 숫자의 개수도 정해져 있지만, 이 또한 $M$ 이라고 하자.



### 시간

대략 절반 정도 되는 자리의 숫자에 대해 덧셈과 곱셈을 한다.
$M$ 개의 숫자가 있다면 $M$ 번 반복해야 하므로 $O(MN)$.



### 공간

자릿수를 담는 배열로 인해 $O(N)$ 만큼 공간이 필요하다.
이 배열을 재사용한다면 $O(N)$ 만큼, 재사용하지 않는다면 $O(MN)$ 만큼 공간이 필요하다.
