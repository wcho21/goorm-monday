import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

from collections import deque

balance, numTransactions = map(int, readline().split())

reservations = deque()

for _ in range(numTransactions):
    transaction, num = readline().split()
    num = int(num)

    # 당장 지불할 수 있을 때만 처리
    if transaction == "pay" and num <= balance:
        balance -= num
        continue

    # 예금이나 지불 예약이 생기면, 이후 큐에 대기 한 지불 예약을 처리
    if transaction == "deposit":
        balance += num
    if transaction == "reservation":
        reservations.append(num)

    while len(reservations) > 0:
        if reservations[0] > balance:
            break

        balance -= reservations.popleft()

print(balance)
