#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

#define MAX_NUM_ROWS int(1e4+1)

pair<string, double> rows[MAX_NUM_ROWS];

void solve() {
  int numRows, index;
  cin >> numRows >> index;

  for (int i = 0; i < numRows; ++i) {
    cin >> rows[i].first >> rows[i].second;
  }

  sort(rows, rows+numRows);

  auto [name, height] = rows[index-1];
  cout << fixed << setprecision(2);
  cout << name << " " << height << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
