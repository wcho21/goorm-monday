#include <iostream>

using namespace std;

constexpr int NONE = 0;
constexpr int LEFT = 1;
constexpr int MID = 2;
constexpr int RIGHT = 3;
constexpr int SIDES = 4;

constexpr int NUM_PATTERNS = 5;
constexpr int MAX_ROWS = int(1e5+1);
constexpr int MOD = int(1e8+7);

int rows[MAX_ROWS][NUM_PATTERNS];

void solve() {
  int numRows;
  cin >> numRows;

  // 첫 줄은 각 패턴의 경우의 수가 한 가지
  fill(rows[0], rows[0]+NUM_PATTERNS, 1);

  // 다음 행 계산
  for (int i = 1; i < numRows; ++i) {
    rows[i][NONE] += rows[i-1][NONE];
    rows[i][NONE] += rows[i-1][LEFT];
    rows[i][NONE] += rows[i-1][MID];
    rows[i][NONE] += rows[i-1][RIGHT];
    rows[i][NONE] += rows[i-1][SIDES];
    rows[i][NONE] %= MOD;

    rows[i][LEFT] += rows[i-1][NONE];
    rows[i][LEFT] += rows[i-1][MID];
    rows[i][LEFT] += rows[i-1][RIGHT];
    rows[i][LEFT] %= MOD;

    rows[i][MID] += rows[i-1][NONE];
    rows[i][MID] += rows[i-1][LEFT];
    rows[i][MID] += rows[i-1][RIGHT];
    rows[i][MID] += rows[i-1][SIDES];
    rows[i][MID] %= MOD;

    rows[i][RIGHT] += rows[i-1][NONE];
    rows[i][RIGHT] += rows[i-1][LEFT];
    rows[i][RIGHT] += rows[i-1][MID];
    rows[i][RIGHT] %= MOD;

    rows[i][SIDES] += rows[i-1][NONE];
    rows[i][SIDES] += rows[i-1][MID];
    rows[i][SIDES] %= MOD;
  }

  // 마지막 행의 경우의 수 합
  int lastRow = 0;
  lastRow += rows[numRows-1][NONE];
  lastRow += rows[numRows-1][LEFT];
  lastRow += rows[numRows-1][MID];
  lastRow += rows[numRows-1][RIGHT];
  lastRow += rows[numRows-1][SIDES];
  lastRow %= MOD;
  cout << lastRow << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
