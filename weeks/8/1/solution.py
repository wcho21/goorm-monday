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

goormNumLen = int(readline())
goormNum = readline()

for i in range(goormNumLen-1):
    twoChars = goormNum[i:i+2]
    if twoChars not in table:
        continue

    print(table[twoChars], end="")

print("")
