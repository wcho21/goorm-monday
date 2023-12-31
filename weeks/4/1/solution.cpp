#include <string>
#include <iostream>
#include <queue>

using namespace std;

queue<int> reservations;

void solve() {
  int balance, numTransactions; // N, M
  cin >> balance >> numTransactions;

  for (int i = 0; i < numTransactions; ++i) {
    string transaction;
    int num;
    cin >> transaction >> num;

    // 당장 지불할 수 있을 때만 처리
    if (transaction == "pay" && num <= balance) {
      balance -= num;
      continue;
    }

    // 예금이나 지불 예약이 생기면, 이후 큐에 대기 한 지불 예약을 처리
    if (transaction == "deposit") {
      balance += num;
    }
    if (transaction == "reservation") {
      reservations.push(num);
    }

    while (!reservations.empty()) {
      if (reservations.front() > balance) {
        break;
      }

      balance -= reservations.front();
      reservations.pop();
    }
  }

  cout << balance << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
