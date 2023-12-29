import sys
sys.setrecursionlimit(100000)
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
FAILED = -1

goormNumLen = int(readline())
goormNum = readline()

dp = [FAILED] * goormNumLen

for index in range(goormNumLen-1):
    twoChars = goormNum[index:index+2]

    # 첫 인덱스에서 변환할 수 없다면 실패
    if twoChars not in table and index == 0:
        break
    # 두 인접한 인덱스에서 연속으로 변환할 수 없다면 실패
    if twoChars not in table and dp[index-1] == FAILED:
        break
    # 이번 인덱스에서 실패하면 다음 인덱스 체크
    if twoChars not in table:
        continue

    dp[index] = table[twoChars]

if dp[goormNumLen-2] == FAILED:
    print(FAILED)
else:
    print("".join(map(str, filter(lambda x: x != FAILED, dp))))
