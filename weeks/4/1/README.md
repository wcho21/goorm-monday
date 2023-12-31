# 체크 카드

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

4주차 첫 번째 문제 [체크 카드][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1679178/4%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-%EC%B2%B4%ED%81%AC-%EC%B9%B4%EB%93%9C


## 문제 요약

체크 카드에 대해 일어나는 거래를 처리해야 한다.

거래는 세 가지 종류가 있다.
계좌에 예금하거나, 돈이 충분할때만 지불하거나, 돈이 충분해질 때 지불을 예약하는 것이다.

처리할 거래들이 주어질 때, 계좌에 남은 돈을 구해야 한다.



## 발상

지불 예약이 생기면 예약 큐에 대기시킨다.
그리고 계좌에 돈이 들어오거나 지불 예약이 생길 때, 큐에 대기한 예약을 처리한다.

당장 지불하는 것은 돈이 충분할 때만 거래가 일어나므로, 이 경우 예약 큐를 확인할 일은 없다.



## 코드 설명

```python
# numTransactions: 거래 개수
# balance: 계좌에 있는 돈
# reservations: 지불 예약이 대기된 큐

for _ in range(numTransactions):
    transaction, num = readline().split()
    num = int(num)

    # 당장 지불할 수 있을 때만 처리
    if transaction == "pay" and num <= balance:
        balance -= num
        continue

    # 예금이나 지불 예약이 생기면, 이후 큐에 대기 한 예약을 처리
    if transaction == "deposit":
        balance += num
    if transaction == "reservation":
        reservations.append(num)

    while len(reservations) > 0:
        if reservations[0] > balance:
            break

        balance -= reservations.popleft()

print(balance)
```



## 복잡도

거래 개수가 $N$ 개 있다고 하자.



### 시간

`for` 문은 각 거래에 대해 반복한다.

대기 큐를 처리하는 `while` 문을 보자.
큐에 지불 예약이 가장 많이 들어갈 때는, 모든 거래가 지불 예약인 경우다.
그런데 각 예약은 기껏해야 한 번 큐에서 처리된다.
즉 대기큐는 모든 거래를 처리했을 때, 시간을 $O(N)$ 만큼 소요하게 된다.

따라서 $O(N)$의 시간을 소요한다.



### 공간

최악의 경우, 모든 거래가 처리할 수 없는 지불 예약일 때 대기 큐가 $O(N)$ 만큼 커진다.

따라서 $O(N)$.
