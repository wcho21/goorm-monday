#include <iostream>

using namespace std;

typedef long long ll;

constexpr int MAX_NUM_ISLANDS = 101;

int numBridges[MAX_NUM_ISLANDS];

void solve() {
  int numIslands;
  cin >> numIslands;

  for (int i = 1; i <= numIslands; ++i) {
    cin >> numBridges[i];
  }

  // 모든 다리의 개수를 곱함
  ll numPaths = 1;
  for (int i = 1; i <= numIslands; ++i) {
    numPaths *= numBridges[i];
  }

  cout << numPaths << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
