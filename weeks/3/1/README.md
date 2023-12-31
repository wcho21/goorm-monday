# 0커플

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

3주차 첫 번째 문제 [0커플][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1672660/3%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-0%EC%BB%A4%ED%94%8C



## 문제 요약

짝수 명의 사람들이 점수와 함께 주어진다.

사람들이 같은 점수를 갖고 있지 않고, 점수가 $x$ 인 사람이 있으면 반드시 $-x$ 인 사람이 존재한다.
단, 그 중 두 명만 자신의 점수 $x$에 대해 $-x$ 인 사람이 존재한다는 규칙을 깬다.
그 예외적인 두 사람의 점수를 합한 값을 구해야한다.



## 발상

점수가 $x$ 인 사람이 있으면 반드시 $-x$ 사람이 두 명 빼고 존재한다.

따라서 이 두 명을 제외하고, 모든 점수를 더하면 0이다.

그런데 그 두 명의 점수를 합해야 하므로, 결국 단순히 모든 점수를 더한 값이 답이 된다.



## 코드 설명

두 번째 줄로 주어진 점수들을 모두 더한다.

```python
scores = map(int, readline().split())
scoreSum = sum(scores)

print(scoreSum)
```



## 복잡도

사람이 $N$ 명 있다고 하자.



### 시간

모든 사람에 대해 점수를 합하므로 $O(N)$.



### 공간

모든 사람의 점수를 담는 배열로 인해 $O(N)$.
