#include <iostream>

using namespace std;

constexpr int SIDE = 1001;

int grid[SIDE][SIDE];

void solve() {
  int numSpecies, threshold; // N, K
  cin >> numSpecies >> threshold;

  // 각 종마다 영역의 꼭지점에 서식 영역 인코딩
  for (int i = 0; i < numSpecies; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    grid[y1][x1] += 1;
    grid[y1][x2] -= 1;
    grid[y2][x1] -= 1;
    grid[y2][x2] += 1;
  }

  // 행에 대한 프리픽스 섬
  for (int y = 0; y < SIDE; ++y) {
    int acc = 0;
    for (int x = 0; x < SIDE; ++x) {
      acc += grid[y][x];
      grid[y][x] = acc;
    }
  }

  // 열에 대한 프리픽스 섬
  for (int x = 0; x < SIDE; ++x) {
    int acc = 0;
    for (int y = 0; y < SIDE; ++y) {
      acc += grid[y][x];
      grid[y][x] = acc;
    }
  }

  // 종이 threshold 만큼 있는 칸의 개수 세기
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
