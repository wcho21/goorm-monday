import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

numPeaks = int(readline())
peaks = map(int, readline().split())

peakStack = []

for peak in peaks:
    print(len(peakStack), end=" ")

    # 현재 봉우리보다 작은 봉우리를 스택에서 버림
    while True:
        if len(peakStack) == 0:
            break
        if peakStack[-1] > peak:
            break

        peakStack.pop()

    peakStack.append(peak)

print("")
