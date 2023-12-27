#include <iostream>

using namespace std;

typedef long long ll;

constexpr ll MOD = int(1e8+7);
constexpr int MAX_COLORS = int(1e5+1);

ll dp[MAX_COLORS] { 0, 0, 1 }; // 1-based (0 index not used)

void solve() {
  int numColors; // N
  cin >> numColors;

  for (int i = 3; i <= numColors; ++i) {
    dp[i] = ((2*i - 1) * dp[i-1] + dp[i-2]) % MOD;
  }

  cout << dp[numColors] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
