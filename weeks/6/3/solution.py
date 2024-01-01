import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

numCases = int(readline())

def convert(ch, base, toShift):
    shifted = ((ord(ch) - ord(base)) + toShift) % 26
    converted = chr(shifted + ord(base))
    return converted

def solveCase():
    input = readline().strip()
    operation, key = readline().split()
    key = list(map(ord, key))

    # 각 문자에 대해 처리
    for i, ch in enumerate(input):
        # 알파벳이 아니면 그 문자 그대로 결과를 냄
        if not ch.isalpha():
            print(ch, end="")
            continue

        # 오른쪽으로 시프트할 횟수를 구함
        keyIndex = i % len(key)
        toShift = key[keyIndex] % 26
        if operation == "D":
            toShift = 26 - toShift

        # 시프트한 결과를 냄
        if ch.islower():
            print(convert(ch, 'a', toShift), end="")
        if ch.isupper():
            print(convert(ch, 'A', toShift), end="")

    print("")


for _ in range(numCases):
    solveCase()
