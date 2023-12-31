# 최장 맨해튼 거리

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

1주차 세 번째 문제 [최장 맨해튼 거리][problem]

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1665443/1%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-3-%EC%B5%9C%EC%9E%A5-%EB%A7%A8%ED%95%B4%ED%8A%BC-%EA%B1%B0%EB%A6%AC



## 문제 요약

네 개의 숫자가 주어진다.
이 숫자로 만들 수 있는 가장 큰 [맨해튼 거리][manhattan-dist]를 구해야 한다.

[manhattan-dist]: https://en.wikipedia.org/wiki/Taxicab_geometry



## 발상

네 개의 숫자가 있다고 하자.
이것으로 만들 수 있는 가장 큰 맨해튼 거리는 큰 두 수에서 작은 두 수를 뺀것이다.
([별도 문서][proof]에서 증명한다.)

[proof]: ./PROOF.md

따라서 주어진 숫자를 정렬 후, 그 가장 큰 맨해튼 거리를 구한다.


## 코드 설명

각 이름마다 주인공의 이름을 포함하는지 확인한다.
그런 이름이 몇 개인지 센다.
이것이 답이 된다.

```python
# nums: 네 개의 숫자를 담은 배열

# 가장 큰 맨해튼 거리 계산
nums.sort()

dist = (nums[2] - nums[0]) + (nums[3] - nums[1])
print(dist)
```



## 복잡도

숫자의 개수가 네 개로 정해져 있다.
분석을 위해 $N$ 개라고 하자.



### 시간

$N$ 개의 숫자가 입력된다.
이를 위한 입력 처리는 시간이 $O(N)$ 만큼 소요된다.

중간에 사용된 정렬이 $O(N \log N)$ 만큼 시간을 소요한다고 하자.
그러면 전체적으로도 그렇다.

정렬이 그것보다 더 빠를 수도 있으나 $O(N)$ 보다는 빠를 수 없다고 가정하자.
그렇더라도 전체적인 복잡도는 정렬 시간이 결정한다.



### 공간

숫자를 담은 배열로 인해 $O(N)$.