# 단어장 만들기

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

예시 첫 번째 문제 [단어장 만들기][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1664566/%EC%98%88%EC%8B%9C-%EB%AC%B8%EC%A0%9C-1-%EB%8B%A8%EC%96%B4%EC%9E%A5-%EB%A7%8C%EB%93%A4%EA%B8%B0



## 문제 요약

단어장에 단어들이 주어진다.

정렬해서 원하는 순번의 단어를 구해야 한다.
이 때 정렬은 길이의 오름차순으로, 길이가 같으면 사전순으로 정렬한다.



## 발상

단순히 문제에서 요구하는대로 정렬을 수행하고, 원하는 순번의 단어를 구한다.



## 코드 설명

설명은 코드 자체로 대신한다.

```python
# wordPos: 원하는 단어의 순번
# words: 단어들을 담은 배열

# 길이 오름차순으로 먼저 정렬하고, 그 다음 문자열을 사전순으로 정렬
words.sort(key=lambda w: (len(w), w))

print(words[wordPos-1])
```



## 복잡도

단어가 $N$ 개 있다고 하자.



### 시간

정렬 알고리즘의 복잡도에 의존한다.
정렬이 $O(N \log N)$ 만큼 시간을 소요한다면, 전체적으로도 그렇다.



### 공간

단어를 담기 위한 배열로 인해 $O(N)$.
