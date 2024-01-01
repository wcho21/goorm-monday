# 소수 찾기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

1주차 네 번째 문제 [소수 찾기][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1665444/1%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-4-%EC%86%8C%EC%88%98-%EC%B0%BE%EA%B8%B0



## 문제

구름이는 수열 $A$에 있는 수들을 합한 값을 구하기로 한다.
하지만 단순히 모든 값을 다 더하는 것은 이젠 진부하다.
대신 구름이는 수열의 앞에서 소수 번째에 위치한 값들을 모두 더하려고 한다.
수열의 값들이 주어졌을 때, 구름이가 계산한 수들의 합을 구해보자.

### 입력

첫째 줄에 수열 $A$의 길이 $N$이 주어진다.
둘째 줄에는 $A_1, \dots, A_N$이 공백을 두고 주어진다.
$A_i$는 $A$의 $i$번째에 위치한 값을 의미한다.

- $1 \leq N \leq 100 \thinspace 000$
- $-100 \leq A_i \leq 100$
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

수열 $A$에서 소수 번째에 위치한 값들의 합을 출력한다.



## 발상

숫자가 $N$ 개 주어졌다고 하자.

[에라토스테네스의 체][sieve]를 이용해 $N$ 까지의 숫자 중에 소수만 남긴다.

[sieve]: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

각 소수에 대해, 소수번 째 숫자를 더한다.


## 코드 설명

$N$ 까지의 숫자가 있다고 하자.
에라토스테네스의 체는 $\sqrt{N}$ 까지의 각 숫자에 대해, 그 숫자의 배수를 전부 지운다.
그러면 지우고 남은 숫자가 소수이다.

소수를 찾았으니 순서가 소수인 숫자를 알 수 있다.
그런 숫자를 전부 더한다.

```python
# nums: 입력 숫자들을 담은 배열 (인덱스 1부터 사용)
# numsLength: 입력 숫자의 개수
# prime: 소수 여부를 담은 배열

prime = [True] * (numsLength+1) # +1는 인덱스를 1부터 사용하기 위함
prime[1] = False

def seive():
    for i in range(2, numsLength+1):
        if i*i >= numsLength+1: # 개수의 제곱근보다 커지면 반복할 필요 없음
            break

        if not prime[i]:
            continue

        # 배수를 지움
        step = i
        for j in range(i+step, numsLength+1, step):
            prime[j] = False

seive()

# 순서가 소수인 숫자를 더함
sum = 0
for i in range(1, numsLength+1):
    if not prime[i]:
        continue

    sum += nums[i]

print(sum)
```



## 복잡도

주어진 숫자의 개수를 $N$ 이라고 하자.



### 시간

$N$ 개의 숫자가 입력된다.
이를 위한 입력 처리는 시간이 $O(N)$ 만큼 소요된다.

에라토스테네스의 체는 소수마다 배수를 지운다.
즉 2의 배수 $N/2$ 개, 그 다음 3의 배수 $N/3$개를 확인하며 지워나간다.
그런데 [소수를 분모로 하는 분수의 합][sum-primes]인 $1/2 + 1/3 + 1/5 + \dots$는 $O(\log \log N)$ 만큼 빠르게 증가한다고 알려져있다.
(소수에 대한 정리는 대체로 어렵기 때문에 여기서는 결과만 이용한다.)
따라서 배수를 지우는 횟수 $N/2 + N/3 + N/5 + \dots$는 곧 $O(N \log \log N)$ 이다.
즉 에라토스테네스의 체는 시간을 $O(N \log \log N)$ 만큼 소요한다.

[sum-primes]: https://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes

그러므로 $O(N \log \log N$).



### 공간

숫자를 담은 배열로 인해 $O(N)$.



### Follow-up: 시간 복잡도 개선하기

매번 똑같은 소수를 사용한다.
그러므로 미리 계산한 소수를 사용하는 트릭을 써볼 수 있다.

```python
# PRIMES: 미리 계산한 소수가 있는 배열
# numsLength: 입력 숫자의 개수
# nums: 입력 숫자들을 담은 배열 (인덱스 1부터 사용)

sum = 0
for prime in PRIMES:
    if prime > numsLength:
        break

    sum += nums[prime]

print(sum)
```

여기서 `for` 문은 $N$ 이하의 소수에 대해서 반복한다.

$N$ 이하의 소수는 $O(N / \log N)$ 개 있다고 알려져 있다. ([소수 정리][prime-number-theorem])
따라서 소수번 째 숫자를 더하는 계산 또한 $O(N / \log N)$ 만큼의 시간이 소요된다.

[prime-number-theorem]: https://en.wikipedia.org/wiki/Prime_number_theorem

입력 처리가 $O(N)$ 만큼 시간을 소요하기 때문에, 전체적인 시간 복잡도는 $O(N)$ 으로 떨어질 수 있다.

한편, 미리 계산한 소수를 메모리에 담아둬야 한다.
숫자가 최대 $N$ 개 들어온다고 할 때, 필요한 소수의 개수는, 다시 소수 정리로 인해 $O(N / \log N)$ 개이다.
입력 숫자를 담기 위한 배열이 $O(N)$ 만큼의 공간을 차지한다면, 공간 복잡도는 $O(N)$ 에서 달라지지 않는다.
