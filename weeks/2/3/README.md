# 출석부

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

2주차 세 번째 문제 [출석부][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1669557/2%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EC%B6%9C%EC%84%9D%EB%B6%80



## 문제 요약

**출석부**가 주어진다.
**출석부**는 각 행마다 이름과 키가 있다.
**출석부**를 정렬했을 때, 주어진 순번에 해당하는 이름과 키를 구해야 한다.
정렬은 이름에 대해 사전순으로, 이름이 같으면 키에 대해 오름차순으로 한다.



## 발상

이름과 키가 행으로 주어졌다고 하자.
그러면 단순히 이 행들을 정렬한뒤, 원하는 순번의 이름과 키를 가져오면 답이 된다.



## 코드 설명

정렬시 문자열은 사전순으로, 숫자는 오름차순으로 한다.
주어진 순번의 행을 결과로 낸다.
단 키는 소수점 두 번째까지 구한다.

```python
# rows: 이름과 키가 튜플로 담긴 배열

# 문자열을 사전순, 숫자를 오름차순 정렬하는 것이 기본값
rows.sort()

name, height = rows[index-1]
formattedHeight = "{:.2f}".format(height)
print(f'{name} {formattedHeight}')
```



## 복잡도

출석부가 $N$ 개의 행을 가진다고 하자.



### 시간

정렬 알고리즘의 시간 복잡도에 의존한다.
정렬이 시간을 $O(N \log N)$ 만큼 소요한다면, 전체적으로도 그렇다.



### 공간

출석부를 위한 배열로 인해 $O(N)$.
