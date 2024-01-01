import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

table = {
    "qw": 1,
    "as": 2,
    "zx": 3,
    "we": 4,
    "sd": 5,
    "xc": 6,
    "er": 7,
    "df": 8,
    "cv": 9,
    "ze": 0,
}

goormNumLen = int(readline())
goormNum = readline()

for i in range(goormNumLen-1):
    # 변환할 수 없으면 스킵
    twoChars = goormNum[i:i+2]
    if twoChars not in table:
        continue

    # 변환할 수 있으면 그 결과를 출력
    print(table[twoChars], end="")

print("")
