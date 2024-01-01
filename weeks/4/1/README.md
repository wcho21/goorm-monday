# 체크 카드

![Difficulty Easy](https://img.shields.io/badge/Difficulty-Easy-green)

4주차 첫 번째 문제 [체크 카드][problem].

[problem]: https://edu.goorm.io/learn/lecture/33428/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%A8%BC%EB%8D%B0%EC%9D%B4-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C1/lesson/1679178/4%EC%A3%BC%EC%B0%A8-%EB%AC%B8%EC%A0%9C-1-%EC%B2%B4%ED%81%AC-%EC%B9%B4%EB%93%9C



## 문제

체크 카드를 사용할 때 가장 중요한 것은 결제가 항상 가능하도록 계좌 잔고를 항상 채워둬야 한다는 점이다.
구름이는 올바른 소비 습관을 만들기 위해서 지난달 구름이가 카드를 통해서 얼마를 입금하고 결제하였는지 확인하려고 한다.

구름이가 쓰는 체크 카드는 deposit, pay, reservation의 세 가지 기능을 가지고 있다.

- deposit: 주어진 금액만큼 계좌에 돈이 들어온다.
- pay: 주어진 금액만큼 계좌에서 돈이 결제된다.
     단, 계좌의 현재 잔액이 주어진 금액보다 적다면 결제되지 않는다.
- reservation: 주어진 금액만큼 계좌에서 돈이 결제된다.
    단, 계좌의 현재 잔액이 주어진 금액보다 적거나, 대기 목록에 다른 거래가 있다면 결제되지 않고 대기 목록의 맨 뒤에 추가된다.
- 대기 목록에 있는 거래들은 대기 목록에 들어간 순서대로 결제가 가능해지는 즉시 해당 거래의 금액만큼 계좌에서 금액이 차감된 뒤 대기 목록에서 삭제된다.

처음에 구름이의 계좌에 들어있던 금액과 지난달 구름이의 거래 내역이 주어졌을 때, 주어진 모든 거래가 진행된 뒤에 구름이의 계좌에 남아있는 금액을 출력하시오.
거래가 완료되지 않고 대기 목록에 남아있는 경우도 거래가 진행된 것으로 본다.

### 입력

첫째 줄에는 처음에 구름이의 계좌에 들어 있던 잔액 $N$과 지난 달 구름이의 거래 횟수 $M$이 공백을 두고 주어진다.
다음 $M$개의 줄에는 구름이의 거래 내역이 시간 순서대로 주어진다.
거래 내역은 유형과 금액이 공백을 두고 주어진다.

- $0 \leq N \leq 100 \thinspace 000$
- $1 \leq M \leq 10 \thinspace 000$
- 거래 유형은 deposit, pay, reservation 의 세 문자열 중 하나로 주어진다.
- 거래 금액은 $1$ 이상 $1 \thinspace 000$ 이하의 정수이다.
- 입력에서 주어지는 모든 수는 정수이다.

### 출력

주어진 모든 거래가 진행된 뒤에 구름이의 계좌에 남아있는 금액을 출력한다.



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
