# 합격자 찾기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

2주차 첫 번째 문제 [합격자 찾기][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1669552/2%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-%ED%95%A9%EA%B2%A9%EC%9E%90-%EC%B0%BE%EA%B8%B0



## 문제 요약

시험 성적들이 주어진다.
평균 이상이면 시험을 통과한다고 할 때, 몇 명이 통과하는지 구해야한다.



## 발상

점수가 $N$ 개 주어졌다고 하자.

그러면 평균을 구할 수 있다.
(여기서 평균은 산술 평균이다.)

이제 몇 개의 점수가 평균 이상인지 구하면 답이 된다.


## 코드 설명

성적을 담은 배열이 있으면, 그 중에 평균 이상인 숫자가 몇 개인지 센다.

평균을 구할 때 총 점수에서 사람의 수를 나눌 수도 있다.
C++처럼 정수 끼리의 나눗셈이 정수로 나온다면, 평균이 잘못 계산되어 잘못된 결과를 얻는다.
이 경우에는 대신 아래처럼 점수에 사람의 수를 곱한 것이 총점을 넘는지 확인한다.

```python
# numPeople: 사람의 수
# scores: 성적이 담긴 배열

sumScores = sum(scores)

numPassed = len(list(filter(lambda n: n * numPeople >= sumScores, scores)))
print(f'{numPassed}/{numPeople}')
```

시험이 여러번, 즉 점수들의 입력이 여러번 주어지므로, 각 시험에 대해 이를 반복한다.



## 복잡도

시험의 개수를 $T$ 개 있다고 하자.
그리고 각 시험마다 점수가 최대 $N$ 개 있다고 하자.



### 시간

점수 입력과 점수의 합, 그리고 평균을 넘는지 확인하는 이 세 작업은 모두 $O(N)$이다.

이것을 각 시험마다 반복되므로, 즉 $T$ 번 반복되므로, $O(TN)$.



### 공간

숫자를 담은 배열로 인해 $O(N)$.

각 시험마다 배열을 새로 만든다면 $O(TN)$, 배열을 재사용한다면 $O(N)$이다.
