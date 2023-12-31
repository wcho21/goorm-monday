#include <iostream>

using namespace std;

typedef long long ll;

constexpr int MAX_LEN = int(1e5+1);

int nums[MAX_LEN];
bool prime[MAX_LEN];

void seive(int limit) {
  fill(begin(prime), end(prime), true);
  prime[0] = prime[1] = false;

  // 제곱근보다 큰 숫자는 확인할 필요 없음
  for (int i = 2; i*i <= limit; ++i) {
    if (!prime[i]) { // since already filtered for that number
      continue;
    }

    // 배수를 지움
    int step = i;
    for (int num = i + step; num <= limit; num += step) {
      prime[num] = false;
    }
  }
}

void solve() {
  int numsLength; // N
  cin >> numsLength;

  for (int i = 1; i <= numsLength; ++i) {
    cin >> nums[i];
  }

  seive(numsLength);

  // 순서가 소수인 숫자를 더함
  int sum = 0;
  for (int i = 1; i <= numsLength; ++i) {
    if (!prime[i]) {
      continue;
    }
    sum += nums[i];
  }

  cout << sum << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
