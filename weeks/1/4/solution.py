import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

numsLength = int(readline())
nums = [0] + list(map(int, readline().split()))
prime = [True] * (numsLength+1)
prime[1] = False

def seive():
    for i in range(2, numsLength+1):
        # 제곱근보다 큰 숫자는 확인할 필요 없음
        if i*i >= numsLength+1:
            break

        if not prime[i]:
            continue

        # 배수를 지움
        step = i
        for j in range(i+step, numsLength+1, step):
            prime[j] = False

seive()

# 순서가 소수인 숫자를 더함
sum = 0
for i in range(1, numsLength+1):
    if not prime[i]:
        continue

    sum += nums[i]

print(sum)
