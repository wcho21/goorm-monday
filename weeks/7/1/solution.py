import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

MAX_NUM_EVENTS = int(1e5+1)

eventCounts = [0] * MAX_NUM_EVENTS

numEvents, numUsers = map(int, readline().split())

# 횟수 카운트
for i in range(numUsers):
    events = map(int, readline().split()[1:])

    for event in events:
        eventCounts[event] += 1

# 가장 많이 일어난 이벤트를 큰 번호부터 출력
maxEventCount = max(eventCounts)
for i, count in reversed(list(enumerate(eventCounts))):
    if count != maxEventCount:
        continue

    print(i, end=" ")
print("")
