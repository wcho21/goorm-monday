import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

numRows, index = map(int, readline().split())
rows = []
for _ in range(numRows):
    row = readline().split()

    name = row[0]
    height = float(row[1])

    rows.append((name, height))

# 문자열을 사전순, 숫자를 오름차순 정렬하는 것이 기본값
rows.sort()

name, height = rows[index-1]
formattedHeight = "{:.2f}".format(height)
print(f'{name} {formattedHeight}')
