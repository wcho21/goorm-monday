#include <iostream>

using namespace std;

constexpr int MAX_SIDE_LEN = 20+2; // +2 due to margin

int bombValues[MAX_SIDE_LEN][MAX_SIDE_LEN];

void solve() {
  int side, numDrops;
  cin >> side >> numDrops;

  // 각 폭탄 좌표에 대해 인접한 칸을 포함하여 폭탄값 증가
  for (int i = 0; i < numDrops; ++i) {
    int x, y;
    cin >> y >> x;

    bombValues[y][x]++;
    bombValues[y-1][x]++;
    bombValues[y+1][x]++;
    bombValues[y][x-1]++;
    bombValues[y][x+1]++;
  }

  // 모든 폭탄 값 합하기
  int bombValueSum = 0;
  for (int y = 1; y <= side; ++y) {
    for (int x = 1; x <= side; ++x) {
      bombValueSum += bombValues[y][x];
    }
  }
  cout << bombValueSum << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
