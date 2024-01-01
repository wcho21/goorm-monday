import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

numIslands = int(readline())
numBridges = map(int, readline().split())

# 모든 다리의 개수를 곱함
numPaths = 1
for numBridge in numBridges:
    numPaths *= numBridge

print(numPaths)
