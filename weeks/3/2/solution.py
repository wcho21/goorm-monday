import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

pads = [ "", "1.,?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ" ]

def getCharFromPresses(key, presses):
    # 숫자로 변환
    keyNum = ord(key) - ord('0')

    # 키 패드의 문자 인덱스 구하기
    # 누른 횟수가 1부터 시작이므로 배열 인덱스로 쓰기 위해 -1
    mod = len(pads[keyNum])
    keyIndex = (presses-1) % mod

    return pads[keyNum][keyIndex]

numPresses = int(readline())
presses = readline()

curChar = presses[0]
numStreaks = 1
for i in range(numPresses):
    if presses[i] == presses[i+1]:
        numStreaks += 1
        continue

    # 현재 문자와 다음 것과 다를 때 입력할 문자를 구함
    print(getCharFromPresses(curChar, numStreaks), end="")

    # 현재 문자와 입력 횟수 초기화
    numStreaks = 1
    curChar = presses[i+1]

print("")
