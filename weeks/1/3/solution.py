import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

nums = list(map(int, readline().split()))

# 가장 큰 맨해튼 거리 계산
nums.sort()

dist = (nums[2] - nums[0]) + (nums[3] - nums[1])
print(dist)
