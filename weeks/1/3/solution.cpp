#include <algorithm>
#include <iostream>

using namespace std;

int nums[4];

void solve() {
  for (int i = 0; i < 4; ++i) {
    cin >> nums[i];
  }

  // 가장 큰 맨해튼 거리 계산
  sort(begin(nums), end(nums));

  int dist = (nums[2] - nums[0]) + (nums[3] - nums[1]);
  cout << dist << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
