#include <iostream>

using namespace std;

constexpr int SIDE = 1001;

int grid[SIDE][SIDE];

void solve() {
  int numSpecies, threshold; // N, K
  cin >> numSpecies >> threshold;

  for (int i = 0; i < numSpecies; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    grid[y1][x1] += 1;
    grid[y1][x2] -= 1;
    grid[y2][x1] -= 1;
    grid[y2][x2] += 1;
  }

  for (int y = 0; y < SIDE; ++y) {
    int acc = 0;
    for (int x = 0; x < SIDE; ++x) {
      acc += grid[y][x];
      grid[y][x] = acc;
    }
  }

  for (int x = 0; x < SIDE; ++x) {
    int acc = 0;
    for (int y = 0; y < SIDE; ++y) {
      acc += grid[y][x];
      grid[y][x] = acc;
    }
  }

  int count = 0;
  for (int y = 0; y < SIDE; ++y) {
    for (int x = 0; x < SIDE; ++x) {
      if (grid[y][x] == threshold) {
        count++;
      }
    }
  }

  cout << count << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
