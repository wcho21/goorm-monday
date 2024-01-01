import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

numWords, wordPos = map(int, readline().split())
words = [readline() for _ in range(numWords)]

# 길이 오름차순으로 먼저 정렬하고, 그 다음 문자열을 사전순으로 정렬
words.sort(key=lambda w: (len(w), w))

print(words[wordPos-1])
