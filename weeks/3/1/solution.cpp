#include <iostream>

using namespace std;

void solve() {
  int numPeople;
  cin >> numPeople;

  int sum = 0;
  for (int i = 0; i < numPeople; ++i) {
    int score;
    cin >> score;

    sum += score;
  }

  cout << sum << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
