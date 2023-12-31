#include <iostream>
#include <string>

using namespace std;

void solve() {
  for (int i = 0; i < 5; ++i) {
    string num;
    cin >> num;

    int digits[7];
    for (int j = 0; j < 7; ++j) {
      digits[j] = num[j] - '0';
    }

    int sum = digits[0] + digits[2] + digits[4] + digits[6];
    int prod = sum * max(1, digits[1]) * max(1, digits[3]) * max(1, digits[5]);
    cout << (prod % 10) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
